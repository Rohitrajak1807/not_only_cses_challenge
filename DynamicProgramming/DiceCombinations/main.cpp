#include <iostream>
#include <vector>

#define MODULUS 1000000007

int32_t dice_combinations(int32_t n);

int main() {
	int32_t n;
	std::cin >> n;
	std::cout << dice_combinations(n);
	return 0;
}

int32_t dice_combinations(int32_t n) {
	std::vector<int32_t> table(n + 1, 0);
	table[0] = 1;
	for(int32_t i = 0; i <= n; ++i) {
		for(int32_t j = 1; j <= 6; ++j) {
			if(i - j >= 0) {
				table[i] = ((table[i] % MODULUS) + (table[i - j] % MODULUS)) % MODULUS;
			}
		}
	}
	return table[n];
}
