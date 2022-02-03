#include "Recursion.h"

#include <cassert>

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
