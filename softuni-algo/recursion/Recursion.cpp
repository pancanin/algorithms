#include "Recursion.h"

int64_t Recursion::sum(int32_t const* arr, size_t n) {
	return sum(arr, 0, n);
}

int64_t Recursion::sum(int32_t const* arr, size_t idx, size_t n) {
	if (idx >= n) return 0;

	return arr[idx] + sum(arr, idx + 1, n);
}
