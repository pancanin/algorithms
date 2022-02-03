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
