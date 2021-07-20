#include <iostream>

#define MODULUS 1000000007

uint64_t power(uint64_t exponent, uint64_t base = 2);


int main() {
	uint64_t n;
	std::cin >> n;
	std::cout << power(n);
	return 0;
}

uint64_t power(uint64_t exponent, uint64_t base) {
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base % MODULUS;
	uint64_t r = power(exponent / 2, base) % MODULUS;
	return exponent % 2 == 0 ? (r * r) % MODULUS : (((r * base) % MODULUS) * r) % MODULUS;
}