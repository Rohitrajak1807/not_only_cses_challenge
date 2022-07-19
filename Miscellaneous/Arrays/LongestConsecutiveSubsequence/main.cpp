#include <iostream>
#include <vector>
#include <unordered_set>
#include <limits>

// Given an array of N integers, find the length of the longest band. A band is
// defined as a subsequence which can be rearranged in such a manner that all
// elements appear consecutive. The longest band is the subsequence which
// contains the largest number of such integers
// Example:
// Input = [1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6]
// Output = 9   // [0, 1, 2, 3, 4, 5, 6, 7] forms the longest band of length 8
size_t longest_band(const std::vector<int32_t> &v);

int main() {
	std::vector<int32_t> v{1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};
	std::cout << longest_band(v);
	return 0;
}

size_t longest_band(const std::vector<int32_t> &v) {
	std::unordered_set<int32_t> numbers{v.begin(), v.end()};
	size_t max_len = std::numeric_limits<size_t>::min();
	for (auto i : numbers) {
		if(numbers.contains(i - 1)) {
			continue;
		}
		size_t current_len = 1;
		while (numbers.contains(++i)) {
			current_len++;
		}
		max_len = std::max(current_len, max_len);
	}
	return max_len;
}
