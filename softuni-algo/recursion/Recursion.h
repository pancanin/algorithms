#ifndef SOFTUNI_ALGO_RECURSION_RECURSION_H_
#define SOFTUNI_ALGO_RECURSION_RECURSION_H_

#include <cstdint>
#include <cstdlib>
#include <string>
#include <vector>
#include <unordered_set>

class Recursion {
public:
	Recursion() = default;

	int64_t sum(int32_t const* arr, size_t n);
	uint64_t factoriel(const uint8_t n);
	std::string drawing(const uint8_t n);
	void generate01(const uint8_t n, void (*consumer)(bool* arr, size_t n));
	void generateNchooseKCombinations(const uint8_t n, const uint8_t k, void (*consumer)(int32_t* arr, size_t n));
	void put8Queens(void (*consumer)(char** arr, int8_t n));
private:
	int64_t sum(int32_t const* arr, size_t idx, size_t n);
	uint64_t factoriel(const uint8_t current, const uint8_t n);

	void generate01(bool* arr, const uint8_t currentIdx, const uint8_t n, void (*consumer)(bool* arr, size_t n));

	void generateNchooseKCombinations(int32_t* arr, int32_t* choiceArr, size_t currentIdx, size_t currentChoiceArrIdx, const uint8_t k, const uint8_t n, void (*consumer)(int32_t* arr, size_t n));

	void put8Queens(char** board, int8_t row, int8_t col, int8_t boardSize, std::unordered_set<int32_t>& attackedCols, std::unordered_set<int32_t>& attackedDiagonals, void (*consumer)(char** arr, int8_t n));
};

#endif /* SOFTUNI_ALGO_RECURSION_RECURSION_H_ */
