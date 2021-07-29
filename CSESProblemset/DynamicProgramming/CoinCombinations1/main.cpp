#include <iostream>
#include <vector>

#define MODULUS 1000000007

int32_t coin_combinations(int32_t target, const std::vector<int32_t> &coins);

int main() {
	int32_t length, target;
	std::cin >> length >> target;
	std::vector<int32_t> coins(length);
	for (int32_t &i : coins)
		std::cin >> i;
	std::cout << coin_combinations(target, coins) << '\n';
	return 0;
}

int32_t coin_combinations(int32_t target, const std::vector<int32_t> &coins) {
	std::vector<int32_t> table(target + 1, 0);
	table[0] = 1;
	for (int32_t i = 0; i <= target; ++i) {
		for (const int32_t &coin : coins) {
			if (i + coin <= target) {
				table[i + coin] = ((table[i + coin] % MODULUS) + (table[i] % MODULUS)) % MODULUS;
			}
		}
	}
	return table[target];
}
