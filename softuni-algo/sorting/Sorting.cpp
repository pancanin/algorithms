#include <iostream>
#include "Sorting.h"

void Sorting::mergeSort(int* arr, int32_t n) {
	int32_t* dest = new int[n];
	mergeSort(arr, 0, n - 1, dest);
}

void Sorting::merge(int32_t* a, int32_t* b, int32_t aSize, int32_t bSize, int32_t* destination, int32_t destStart) {
	int32_t* temp = new int32_t[aSize + bSize];
	std::cout << "Merge method called with parameters " << aSize << " and " << bSize << std::endl;
	int32_t aIdx = 0;
	int32_t bIdx = 0;
	int32_t destIdx = destStart;

	while (aIdx < aSize && bIdx < bSize) {
		if (a[aIdx] <= b[bIdx]) {
			std::cout << "Selecting " << a[aIdx] << std::endl;
			temp[destIdx] = a[aIdx];
			aIdx++;
		} else {
			std::cout << "Selecting " << b[bIdx] << std::endl;
			temp[destIdx] = b[bIdx];
			bIdx++;
		}

		destIdx++;
	}

	while (aIdx < aSize) {
		std::cout << "Selecting " << a[aIdx] << std::endl;
		temp[destIdx++] = a[aIdx++];
	}

	while (bIdx < bSize) {
		std::cout << "Selecting " << b[bIdx] << std::endl;
		temp[destIdx++] = b[bIdx++];
	}

	for (int32_t i = destStart; i < destStart + aSize + bSize; i++) {
		destination[i] = temp[i - destStart];
	}
}

void Sorting::mergeSort(int32_t* arr, int32_t low, int32_t high, int32_t* destination) {
	if (high <= low) {
		std::cout << "Here we have an array of size 1: " << arr[low] << std::endl;
		return;
	}

	int32_t mid = low + ((high - low) / 2);

	mergeSort(arr, low, mid, destination);
	mergeSort(arr, mid + 1, high, destination);
	merge(&arr[low], &arr[mid + 1], mid - low + 1, high - mid, arr, low);
	std::cout << "Backtracking: low is: " << low << " and mid is: " << mid << " and high is " << high << std::endl;
}
