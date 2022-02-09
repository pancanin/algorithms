#include <iostream>
#include <string>
#include <chrono>
#include <queue>
#include <sstream>
#include <unordered_set>
#include <list>

#include "softuni-algo/recursion/Recursion.h"
#include "softuni-algo/sorting/Sorting.h"
#include "softuni-algo/graphs/ConnectedComponents.h"
#include "softuni-algo/graphs/Node.h"
#include "softuni-algo/graphs/Graph.h"

void print(int32_t* arr, size_t n) {
	std::cout << "[ ";

	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}

	std::cout << "]" << std::endl;
}

int32_t counter = 0;

void printMatrix(char** matrix, int8_t n) {
	std::cout << "--------" << std::endl;
	for (uint8_t i = 0; i < n; i++) {
		for (uint8_t j = 0; j < n; j++) {
			if (matrix[i][j] == '*') {
				std::cout << "Q" << " ";
			} else {
				std::cout << '-' << " ";
			}
		}

		std::cout << std::endl;
	}

	counter++;
}

template<typename T>
T** consumeMatrixFromStdIn(uint32_t rows, uint32_t cols) {
	T** matrix = new T*[rows];

	for (int32_t i = 0; i < rows; i++) {
		matrix[i] = new T[cols];

		for (int32_t j = 0; j < cols; j++) {
			char c;
			std::cin >> c;
			matrix[i][j] = c;
		}
	}

	return matrix;
}

void printQueue(std::stack<char> q) {
	while (!q.empty()) {
		std::cout << q.top();
		q.pop();
	}


	std::cout << std::endl;
}

int main() {
//	Recursion r;
//
//	uint32_t rows, cols;
//
//	std::cin >> rows >> cols;
//	char** laby = consumeMatrixFromStdIn<char>(rows, cols);
//
//	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
//
//	r.findAllPathsInLabyrinth(laby, cols, rows, printQueue, 0, 0);
//
//	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
//
//	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

//	Sorting s;
//	const int32_t n = 8;
//
//	int* dest = new int[n];
//
//	dest[0] = 1;
//	dest[1] = 2;
//	dest[2] = 3;
//	dest[3] = 4;
//	dest[4] = 5;
//	dest[5] = 6;
//	dest[6] = 7;
//	dest[7] = 8;
//
//
//	std::cout << s.binarySearch(dest, 8, 5) << std::endl;
//
//	print(dest, n);


	/**
	 * Test data:
9
3 6
3 4 5 6
8
0 1 5
1 6
1 3
0 1 4

2

Another test data:
7

2 6
1
4
3

1
	 */
	Graph g;

	int n;

	std::cin >> n;
	std::string line;
	getline(std::cin, line);

	for (int i = 0; i < n; i++) {

		getline(std::cin, line);
		std::istringstream lineStream(line);

		int num;
		std::unordered_set<int> numbers;

		while (lineStream >> num) {
			numbers.insert(num);
		}

		g.addOneWay(i, numbers);
	}

	g.print();

	/* Topological sorting data
6
1 2
3 4
5
2 5
3

	 *
	 */
	std::list<Node*> dfsPath = g.walkDFS(0);

	for (Node* n : dfsPath) {
		std::cout << n->id << std::endl;
	}

	return 0;
}
