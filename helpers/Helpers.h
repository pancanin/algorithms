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


#endif /* HELPERS_HELPERS_H_ */
