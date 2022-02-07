#include "Recursion.h"

#include <cassert>
#include <cmath>
#include <string>
#include <iostream>

#include "helpers/Helpers.h"

int64_t Recursion::sum(int32_t const* arr, size_t n) {
	return sum(arr, 0, n);
}

int64_t Recursion::sum(int32_t const* arr, size_t idx, size_t n) {
	if (idx >= n) return 0;

	return arr[idx] + sum(arr, idx + 1, n);
}

uint64_t Recursion::factoriel(const uint8_t n) {
	assert(n <= 20);
	return factoriel(1, n);
}

uint64_t Recursion::factoriel(const uint8_t current, const uint8_t n) {
	if (current > n) return 1;

	return current * factoriel(current + 1, n);
}

void Recursion::generate01(const uint8_t n, void (*consumer)(bool* arr, size_t n)) {
	bool* arr = new bool[n];

	std::cout << "Generating " << pow(2, n) << " vectors" << std::endl;

	generate01(arr, 0, n, consumer);

	delete[] arr;
}

void Recursion::generate01(bool* arr, const uint8_t currentIdx, const uint8_t n, void (*consumer)(bool* arr, size_t n)) {
	if (currentIdx >= n) {
		consumer(arr, n);
		return;
	}

	for (int i = 0; i < 2; i++) {
		arr[currentIdx] = i;
		generate01(arr, currentIdx + 1, n, consumer);
	}
}

void Recursion::generateNchooseKCombinations(const uint8_t n, const uint8_t k, void (*consumer)(int32_t* arr, size_t n)) {
	int32_t* arr = new int32_t[k];
	int32_t* choiceArr = new int32_t[n];

	for (uint8_t i = 0; i < n; i++) {
		choiceArr[i] = i + 1;
	}

	generateNchooseKCombinations(arr, choiceArr, 0, 0, k, n, consumer);

	delete[] arr;
}

void Recursion::generateNchooseKCombinations(int32_t* arr, int32_t* choiceArr, size_t currentArrIdx, size_t currentChoiceArrIdx, const uint8_t k, const uint8_t n, void (*consumer)(int32_t* arr, size_t n)) {
	if (currentArrIdx >= k) {
		consumer(arr, k);
		return;
	}

	for (size_t i = currentChoiceArrIdx; i < n; i++) {
		arr[currentArrIdx] = choiceArr[i];
		generateNchooseKCombinations(arr, choiceArr, currentArrIdx + 1, i + 1, k, n, consumer);
	}
}

void Recursion::put8Queens(const uint8_t n, void (*consumer)(char** arr, int8_t n)) {
	char** board = createMatrix<char>(n, n);

	bool* attackedCols = new bool[n + 1];
	bool* attackedDiagonals = new bool[n * 2];

	put8Queens(board, 0, 0, n, attackedCols, attackedDiagonals, consumer);

	deleteMatrix<char>(board, n);
	delete[] attackedCols;
	delete[] attackedDiagonals;
}

void Recursion::put8Queens(char** board,
		int8_t row,
		int8_t col,
		int8_t boardSize,
		bool* attackedCols,
		bool* attackedDiagonals,
		void (*consumer)(char** arr, int8_t n)) {

	if (row >= boardSize) {
		consumer(board, boardSize);
		return;
	}

	for (uint8_t i = 0; i < boardSize; i++) {
		size_t LRDiagonalIdx = i - row;
		size_t RLDiagonalIdx = boardSize + row + i;
		if (attackedCols[i] || attackedDiagonals[LRDiagonalIdx] || attackedDiagonals[RLDiagonalIdx]) {
			continue;
		}

		board[row][i] = '*';
		attackedCols[i] = true;
		attackedDiagonals[LRDiagonalIdx] = true;
		attackedDiagonals[RLDiagonalIdx] = true;

		put8Queens(board, row + 1, i, boardSize, attackedCols, attackedDiagonals, consumer);

		attackedCols[i] = false;
		attackedDiagonals[LRDiagonalIdx] = false;
		attackedDiagonals[RLDiagonalIdx] = false;
		board[row][i] = '\0';
	}
}

void Recursion::findAllPathsInLabyrinth(
			char** labyrinth,
			uint8_t width,
			uint8_t height,
			void (*consumer)(std::stack<char> path),
			uint8_t startRow,
			uint8_t startCol
) {
	std::stack<char> path;
	bool** visited = createMatrix<bool>(width, height);

	findAllPathsInLabyrinth(
			labyrinth,
			visited,
			width,
			height,
			path,
			consumer,
			startRow,
			startCol,
			'S'
	);

	deleteMatrix(visited, width);
}

void Recursion::findAllPathsInLabyrinth(
			char** labyrinth,
			bool** visited,
			uint8_t width,
			uint8_t height,
			std::stack<char>& currentPath,
			void (*consumer)(std::stack<char> path),
			uint8_t currentRow,
			uint8_t currentCol,
			char currentDirection
) {
	// Test out of bounds
	if (currentRow >= height || currentCol >= width || currentRow < 0 || currentCol < 0) {
		return;
	}

	// Have we hit a wall
	if (labyrinth[currentRow][currentCol] == '*') {
		return;
	}

	// Is it already visited?
	if (visited[currentRow][currentCol]) {
		return;
	}

	// Have we reached the exit?
	if (labyrinth[currentRow][currentCol] == 'e') {
		currentPath.push(currentDirection);
		consumer(currentPath);
		currentPath.pop();
		return;
	}

	currentPath.push(currentDirection);
	visited[currentRow][currentCol] = true;

	findAllPathsInLabyrinth(labyrinth, visited, width, height, currentPath, consumer, currentRow, currentCol + 1, 'R');
	findAllPathsInLabyrinth(labyrinth, visited, width, height, currentPath, consumer, currentRow, currentCol - 1, 'L');
	findAllPathsInLabyrinth(labyrinth, visited, width, height, currentPath, consumer, currentRow + 1, currentCol, 'D');
	findAllPathsInLabyrinth(labyrinth, visited, width, height, currentPath, consumer, currentRow - 1, currentCol, 'U');

	currentPath.pop();
	visited[currentRow][currentCol] = false;
}
