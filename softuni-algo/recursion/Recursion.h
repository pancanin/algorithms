#ifndef SOFTUNI_ALGO_RECURSION_RECURSION_H_
#define SOFTUNI_ALGO_RECURSION_RECURSION_H_

#include <cstdint>
#include <cstdlib>

class Recursion {
public:
	Recursion() = default;

	int64_t sum(int32_t const* arr, size_t n);
	uint64_t factoriel(const uint8_t n);
private:
	int64_t sum(int32_t const* arr, size_t idx, size_t n);
	uint64_t factoriel(const uint8_t current, const uint8_t n);
};

#endif /* SOFTUNI_ALGO_RECURSION_RECURSION_H_ */
