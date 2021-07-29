#include <iostream>
#include <vector>

#define MODULUS 1000000007
/*
 * The idea is same as before, but now instead of considering all sub array for a given sum `s` we flip the question, and
 * ask given a subarray `coins[: k]` if we can or cannot reach the sum `s` in this manner we preserve the order.
 */
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

