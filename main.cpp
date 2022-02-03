#include <iostream>
#include <string>

#include "softuni-algo/recursion/Recursion.h"

void print(bool* arr, size_t n) {
	std::cout << "[ ";

	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}

	std::cout << "]" << std::endl;
}

int main() {
	Recursion r;

	r.generate01(3, &print);

	return 0;
}
