#include <iostream>
#include <vector>

// Given an array of size N, return another vector of length N, where each
// element is equal to the product of every other number in the input array.
// In other words, result[i] is equal to the product of every number in the
// input array other than input[i].
// Solve this problem without division. You may assume that answer can be
// stored in a 32-bit integer without any overflow.
// Example:
// Input: [1, 2, 3, 4, 5]
// Output: [120, 60, 40, 30, 24]
std::vector<int32_t> product_array(const std::vector<int32_t> &v);

int main() {
	std::vector<int32_t> v{1, 2, 3, 4, 5};
	std::vector<int32_t> r = product_array(v);
	for (int &i: r) {
		std::cout << i << ' ';
	}
	return 0;
}

std::vector<int32_t> product_array(const std::vector<int32_t> &v) {
	std::vector<int32_t> result(v.size(), 1);
	int32_t left_product = 1;
	for (size_t i = 0; i < result.size(); ++i) {
		result[i] *= left_product;
		left_product *= v[i];
	}
	int32_t right_product = 1;
	for (size_t i = result.size(); i > 0; --i) {
		result[i - 1] *= right_product;
		right_product *= v[i - 1];
	}
	return result;
}
