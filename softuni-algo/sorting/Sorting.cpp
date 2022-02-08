#include <iostream>
#include <cassert>
#include "Sorting.h"

void Sorting::mergeSort(int* arr, int32_t n) {
	assert(n >= 0);
	int32_t* dest = new int[n];
	mergeSort(arr, 0, n - 1, dest);
}

void Sorting::merge(int32_t* a, int32_t* b, int32_t aSize, int32_t bSize, int32_t* destination, int32_t destStart) {
	int32_t* temp = new int32_t[aSize + bSize];
	int32_t aIdx = 0;
	int32_t bIdx = 0;
	int32_t destIdx = 0;

	while (aIdx < aSize && bIdx < bSize) {
		if (a[aIdx] <= b[bIdx]) {
			temp[destIdx] = a[aIdx];
			aIdx++;
		} else {
			temp[destIdx] = b[bIdx];
			bIdx++;
		}

		destIdx++;
	}

	while (aIdx < aSize) {
		temp[destIdx++] = a[aIdx++];
	}

	while (bIdx < bSize) {
		temp[destIdx++] = b[bIdx++];
	}

	for (int32_t i = destStart; i < destStart + aSize + bSize; i++) {
		destination[i] = temp[i - destStart];
	}
}

void Sorting::mergeSort(int32_t* arr, int32_t low, int32_t high, int32_t* destination) {
	if (high <= low) {
		return;
	}

	int32_t mid = low + ((high - low) / 2);

	mergeSort(arr, low, mid, destination);
	mergeSort(arr, mid + 1, high, destination);
	merge(&arr[low], &arr[mid + 1], mid - low + 1, high - mid, arr, low);
}

void Sorting::quick(int32_t* a, int32_t start, int32_t end) {
	int32_t pivot = start + ((end - start) / 2);

	int32_t left = start;
	int32_t right = end;

	while (left < pivot && right >= pivot) {
		if (a[left] > a[pivot] && a[right] <= a[pivot]) {
			std::cout << "Swapping values " << a[left] << " and " << a[right] << std::endl;
			int32_t temp = a[left];
			a[left] = a[right];
			a[right] = temp;
		}

		if (a[left] <= a[pivot]) {
			left++;
		}

		if (a[right] >= a[pivot]) {
			right--;
		}
	}
}

int32_t Sorting::binarySearch(int32_t* arr, int32_t n, int32_t needle) {
	return binarySearch(arr, needle, 0, n - 1);
}

int32_t Sorting::binarySearch(int32_t* arr, int32_t needle, int32_t start, int32_t end) {
	if (start > end) {
		return -1;
	}

	int32_t mid = start + ((end - start) / 2);

	if (arr[mid] == needle) {
		return mid;
	}

	if (arr[mid] < needle) {
		return binarySearch(arr, needle, mid + 1, end);
	} else {
		return binarySearch(arr, needle, start, mid);
	}
}
