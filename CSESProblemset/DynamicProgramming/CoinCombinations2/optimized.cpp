#include <iostream>
#include <vector>

#define MODULUS 1000000007

int32_t coin_combinations_ordered(int32_t target, const std::vector<int32_t> &coins);

int main() {
	int32_t coins_len, target;
	std::cin >> coins_len >> target;
	std::vector<int32_t> coins(coins_len);
	for (int32_t &i : coins)
		std::cin >> i;
	std::cout << coin_combinations_ordered(target, coins);
	return 0;
}

int32_t coin_combinations_ordered(int32_t target, const std::vector<int32_t> &coins) {
	std::vector<int32_t> table(target + 1, 0);
	table[0] = 1;
	for(const int32_t& i : coins) {
		for(int32_t j = 0; j + i <= target; ++j) {
			table[j + i] += table[j];
			table[j + i] %= MODULUS;
		}
	}
	return table.back();
}

