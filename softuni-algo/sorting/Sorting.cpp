#include <iostream>
#include "Sorting.h"

void Sorting::mergeSort(int* arr, int32_t n) {
	int32_t* dest = new int[n];
	mergeSort(arr, 0, n - 1, dest);

	arr = dest;
}

void Sorting::merge(int32_t* a, int32_t* b, int32_t aSize, int32_t bSize, int32_t* destination, int32_t destStart) {
	int32_t aIdx = 0;
	int32_t bIdx = 0;
	int32_t destIdx = destStart;

	while (aIdx < aSize && bIdx < bSize) {
		if (a[aIdx] <= b[bIdx]) {
			destination[destIdx] = a[aIdx];
			aIdx++;
		} else {
			destination[destIdx] = b[bIdx];
			bIdx++;
		}

		destIdx++;
	}

	while (aIdx < aSize) {
		destination[destIdx++] = a[aIdx++];
	}

	while (bIdx < bSize) {
		destination[destIdx++] = b[bIdx++];
	}
}

void Sorting::mergeSort(int32_t* arr, int32_t low, int32_t high, int32_t* destination) {
	if (high <= low) {
		return;
	}

	int32_t mid = low + ((high - low) / 2);
	std::cout << "Pre Low: " << low << "; high " << high << "; Mid is " << mid << std::endl;

	mergeSort(arr, low, mid, destination);
	mergeSort(arr, mid + 1, high, destination);

	std::cout << "Post Low: " << low << "; Mid is " << mid << "; high " << high << std::endl;
}
