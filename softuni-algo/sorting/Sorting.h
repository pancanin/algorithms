/*
 * Sorting.h
 *
 *  Created on: Feb 7, 2022
 *      Author: ubuntu
 */

#ifndef SOFTUNI_ALGO_SORTING_H_
#define SOFTUNI_ALGO_SORTING_H_

#include <cstdint>

class Sorting {
public:
	Sorting() = default;

	void mergeSort(int32_t* arr, int32_t n);
	void merge(int32_t* a, int32_t* b, int32_t aSize, int32_t bSize, int32_t* destination, int32_t destStart);

	void quick(int32_t* a, int32_t start, int32_t end);

	int32_t binarySearch(int32_t* arr, int32_t n, int32_t needle);
private:
	void mergeSort(int32_t* arr, int32_t low, int32_t high, int32_t* destination);

	int32_t binarySearch(int32_t* arr, int32_t needle, int32_t start, int32_t end);
};

#endif /* SOFTUNI_ALGO_SORTING_H_ */
