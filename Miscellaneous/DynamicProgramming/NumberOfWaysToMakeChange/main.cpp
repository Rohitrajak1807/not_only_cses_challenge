#include <iostream>
#include <vector>

// Given an array of distinct positive integers representing coin denominations and a single non-negative integer n(target)
// representing a target amount of money, write a function that returns the number of ways to make change for that target
// amount using the given coin denominations.
// Note that an unlimited amount of coins is at your disposal.
// Sample Input
// target = 6
// denoms = [1, 5]
// Sample Output
// 2   (1x1 + 1x5 and 6x1)
int32_t ways_to_make_change(int32_t target, const std::vector<int32_t> &denoms);

int main() {
	int32_t target = 10;
	std::vector<int32_t> denoms{1, 5, 10, 25};
	std::cout << ways_to_make_change(target, denoms);
	return 0;
}

int32_t ways_to_make_change(int32_t target, const std::vector<int32_t> &denoms) {
	std::vector<int32_t> ways(target + 1);
	ways[0] = 1;
	for (const int &coin: denoms) {
		for (int32_t i = 0; i <= target; ++i) {
			if (coin + i <= target) {
				ways[i + coin] += ways[i];
			}
		}
	}
	return ways.back();
}
