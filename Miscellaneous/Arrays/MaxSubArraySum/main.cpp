#include <iostream>
#include <vector>

// Given an array of integers of size N, find the maximum sum formed by any subarray.
// A subarray is defined as consecutive elements of an array. If all the numbers are -ve,
// return 0
// Example:
// Input: [-1, 2, 3, 4, -2, 6, -8, 3]
// Output: 13
// Explanation: [-1, 2, 3, 4, -2, 6, -8, 3]
//                   ^____________^ the subarray [2, ..., 6] is the subarray with the highest sum.
int32_t max_subarray_sum(const std::vector<int32_t> &v);

int main() {
	std::vector<int32_t> v{-1, 2, 3, 4, -2, 6, -8, 3};
	std::cout << max_subarray_sum(v);
	return 0;
}

int32_t max_subarray_sum(const std::vector<int32_t> &v) {

	int32_t global_max = 0, curr_max = 0;
	for (int i : v) {
		curr_max = std::max(curr_max + i, i);
		global_max = std::max(global_max, curr_max);
	}
	return global_max;
}