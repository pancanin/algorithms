#include <iostream>
#include <string>

#include "softuni-algo/recursion/Recursion.h"

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

int main() {
	Recursion r;

	r.put8Queens(&printMatrix);

	std::cout << "Numbers of queen placements: " << counter << std::endl;

	return 0;
}
