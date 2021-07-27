#include <iostream>
#include <vector>

int32_t minimizing_coins(int32_t target, const std::vector<int32_t> &coins);

int main() {
	int32_t coins_count, target;
	std::cin >> coins_count >> target;
	std::vector<int32_t> coins(coins_count);
	for (int32_t &i : coins)
		std::cin >> i;
	std::cout << minimizing_coins(target, coins);
}

int32_t minimizing_coins(int32_t target, const std::vector<int32_t> &coins) {
	std::vector<int32_t> combination_len(target + 1, -1);
	combination_len[0] = 0;
	for(int32_t i = 0; i <= target; ++i) {
		if(combination_len[i] != -1) {
			for(const int32_t &coin : coins) {
				if(i + coin <= target) {
					if(combination_len[i + coin] == -1 or combination_len[i + coin] > combination_len[i] + 1) {
						combination_len[i + coin] = 1 + combination_len[i];
					}
				}
			}
		}
	}
	return combination_len[target];
}
