#include <iostream>
#include <vector>


// Write a function that takes in an array of positive integers and returns the maximum sum of non-adjacent elements in the array.
// If the input array is empty, the function should return 0.
// Sample Input
// array  = [75, 105, 120, 75, 90, 135]
//
// Sample Output
// 330

int32_t max_sum_no_adj(const std::vector<int32_t> &v);

int main() {
	std::vector<int32_t> v = {75, 105, 120, 75, 90, 135};
	std::cout << max_sum_no_adj(v);
	return 0;
}

int32_t max_sum_no_adj(const std::vector<int32_t> &v) {
	if (v.empty())
		return 0;

	int32_t s0 = v[0], s1 = std::max(v[0], v[1]), s = std::max(s0, s1);
	for (size_t i = 2; i < v.size(); ++i) {
		s = std::max(s0 + v[i], s1);
		s0 = s1;
		s1 = s;
	}
	return s;
}
