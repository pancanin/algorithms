#include <iostream>

#include "softuni-algo/recursion/Recursion.h"

int main() {
	size_t n = 5;
	int32_t numbers[n] = {1, 2, 3, 4, 5};
	Recursion r;

	int64_t result = r.sum(numbers, n);

	std::cout << "The result is: " << result << std::endl;

	return 0;
}
