#include <iostream>

void weird_algorithm(uint64_t n);

int main() {
	uint64_t n;
	std::cin >> n;
	weird_algorithm(n);
	return 0;
}

void weird_algorithm(uint64_t n) {
	std::cout << n << ' ';
	while(n != 1) {
		if(n % 2 == 0) {
			n /= 2;
		} else {
			n *= 3;
			++n;
		}
		std::cout << n << ' ';
	}
}
