#include <iostream>
#include <vector>
#define IDX_TO_COIN(idx, coins) ((coins)[(idx) - 1])

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
	std::vector<std::vector<int32_t>> table(target + 1, std::vector<int32_t>(coins.size() + 1, 0));
	for(int32_t &i : table[0]) i = 1;
	for(size_t i = 1; i <= target; ++i) {
		for(int32_t j = 1; j <= coins.size(); ++j) {
			if(j >= 0)
				table[i][j] = (table[i][j] + table[i][j - 1]) % MODULUS;
			if(i - IDX_TO_COIN(j, coins) >= 0) {
				table[i][j] = (table[i][j] + table[i - IDX_TO_COIN(j, coins)][j]) % MODULUS;
			}
		}
	}
	return table.back().back();
}
