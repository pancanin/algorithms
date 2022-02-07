#ifndef HELPERS_HELPERS_H_
#define HELPERS_HELPERS_H_

#include <iostream>
#include <string>
#include <cstdlib>

template<typename T>
void print(const T* arr, size_t n) {
	std::cout << "[ ";

	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}

	std::cout << "]" << std::endl;
}

void printWithNewLine(std::string& s) {
	std::cout << s << std::endl;
}

template<typename T>
T** createMatrix(uint32_t rows, uint32_t cols) {
	T** matrix = new T*[rows];

	for (int i = 0; i < rows; i++) {
		matrix[i] = new T[cols];
	}

	return matrix;
}

template<typename T>
void deleteMatrix(T** matrix, uint32_t rows) {
	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}

	delete[] matrix;
}

#endif /* HELPERS_HELPERS_H_ */
