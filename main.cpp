#include <iostream>

#include "softuni-algo/recursion/Recursion.h"

int main() {
	Recursion r;
	uint64_t result = r.factoriel(20);

	std::cout << "The result is: " << result << std::endl;

	return 0;
}
