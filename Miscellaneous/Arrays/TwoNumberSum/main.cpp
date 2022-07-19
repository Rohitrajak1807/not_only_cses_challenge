#include <iostream>
#include <vector>
#include <array>
#include <unordered_set>
// Write a function that takes in a non-empty array of distinct integers and an
// integer representing a target sum. If any two numbers in the input array sum
// up to the target sum, the function should return them in an array, in any
// order. If no two numbers sum up to the target sum, the function should return
// an empty array.

std::array<int64_t, 2> two_number_sum(const std::vector<int64_t> &v, int64_t target);


int main() {
	size_t size;
	int64_t target;
	std::cin >> size;
	std::vector<int64_t> v(size);
	for (int64_t &i : v)
		std::cin >> i;
	std::cin >> target;
	auto &&res = two_number_sum(v, target);
	std::cout << res.size() << '\n';
	for(int64_t& i : res)
		std::cout << i << ' ';
	std::cout << '\n';
	return 0;
}

std::array<int64_t, 2> two_number_sum(const std::vector<int64_t> &v, int64_t target) {
	std::unordered_set<int64_t> complements;
	for (const int64_t &i: v) {
		int64_t complement = target - i;
		if (complements.find(i) == complements.end()) {
			complements.emplace(complement);
		} else {
			return {i, complement};
		}
	}
	return {};
}
