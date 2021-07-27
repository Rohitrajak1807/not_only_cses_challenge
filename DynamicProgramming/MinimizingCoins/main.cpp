#include <iostream>
#include <vector>

/*
 * This is a correct solution, but it produces TLE due to inefficiencies in memory allocation and stack overflow on
 * large inputs. The memory issue can be solved by not using `ResultCombination` as the return type for `minimizing_coins`,
 * but rather using an int.
 */
struct ResultCombination {
	bool is_valid = false;
	std::vector<int32_t> sequence{};
};

ResultCombination minimizing_coins(int32_t target, const std::vector<int32_t> &coins);

int main() {
	int32_t coins_count, target;
	std::cin >> coins_count >> target;
	std::vector<int32_t> coins(coins_count);
	for (int32_t &i : coins)
		std::cin >> i;
	auto&&[is_valid, sequence] = minimizing_coins(target, coins);
	if (!is_valid)
		std::cout << -1 << '\n';
	else
		std::cout << sequence.size() << '\n';
	return 0;
}

ResultCombination minimizing_coins(int32_t target, const std::vector<int32_t> &coins) {
	if (target == 0)
		return {.is_valid = true};
	if (target < 0)
		return {.is_valid = false};
	ResultCombination combination;
	for (const int32_t &coin : coins) {
		ResultCombination &&partial_combination = minimizing_coins(target - coin, coins);
		if (partial_combination.is_valid) {
			if (combination.sequence.empty() or partial_combination.sequence.size() + 1 < combination.sequence.size()) {
				combination.sequence = partial_combination.sequence;
				combination.sequence.emplace_back(coin);
				combination.is_valid = true;
			}
		}
	}
	return combination;
}
