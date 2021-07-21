#include <iostream>

uint64_t trailing_zeroes(uint64_t n);

int main() {
	uint64_t n;
	std::cin >> n;
	std::cout << trailing_zeroes(n) << '\n';
	return 0;
}

uint64_t trailing_zeroes(uint64_t n) {
	uint64_t multiple_5 = 5;
	uint64_t zeroes = 0;
	while(multiple_5 <= n) {
		zeroes += n / multiple_5;
		multiple_5 *= 5;
	}
	return zeroes;
}
