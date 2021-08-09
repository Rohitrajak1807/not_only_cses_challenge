#include <iostream>
#include <vector>
#include <algorithm>

// Given an array of positive integers representing the values of coins in your possession, write a function that
// returns the minimum amount of change (the minimum sum of money) that you cannot create. The given coins can have
// any positive integer value and aren't necessarily unique (i.e., you can have multiple coins of the same value).
// For example, if you're given coins = [1, 2, 5], the minimum amount of change that you can't create is 4. If you're
// given no coins, the minimum amount of change that you can't create is 1. Note that you cannot use the ith coin more
// than once. Example if coins = [1, 1, 2, 4], then you can use `1` atmost twice as coins[0] = 1 and coins[1] = 1 as well.

int64_t min_non_change(std::vector<int64_t> &coins);

int main() {
	size_t size;
	std::cin >> size;
	std::vector<int64_t> coins(size);
	for (int64_t &i : coins)
		std::cin >> i;
	std::cout << min_non_change(coins);
	return 0;
}

int64_t min_non_change(std::vector<int64_t> &coins) {
	if (coins.empty())
		return 1;
	std::sort(coins.begin(), coins.end());
	int64_t min_amount = 0;
	for (int64_t &coin : coins) {
		if (coin > min_amount + 1)
			return min_amount + 1;
		else
			min_amount += coin;
	}
	return min_amount + 1;
}
