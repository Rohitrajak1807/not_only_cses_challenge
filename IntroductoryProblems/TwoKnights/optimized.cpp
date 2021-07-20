//
// Created on 7/20/21.
//

#include <iostream>

void count_arrangements(uint64_t n);

int main() {
	uint64_t n;
	std::cin >> n;
	count_arrangements(n);
}

//referenced from https://github.com/sabrina214/WorkOut/blob/main/Two%20Knights/solution.py#L27
void count_arrangements(uint64_t n) {
	for (uint64_t i = 1; i <= n; ++i) {
		if(i == 1) {
			std::cout << 0 << '\n';
		}
		else if(i == 2) {
			std::cout << 6 << '\n';
		}
		else if(i == 3) {
			std::cout << 28 << '\n';
		} else {
			uint64_t total_squares = i * i;
			uint64_t twos = (4 * (total_squares - 3)) / 2;
			uint64_t threes = (8 * (total_squares - 4)) / 2;
			uint64_t fours = (((4 + (i - 4) * 4)) * (total_squares - 5)) / 2;
			uint64_t sixes = (((i - 4) * 4) * (total_squares - 7)) / 2;
			uint64_t eights = (((i - 4) * (i - 4)) * (total_squares - 9)) / 2;
			std::cout << twos + threes + fours + sixes + eights << '\n';
		}
	}
}
