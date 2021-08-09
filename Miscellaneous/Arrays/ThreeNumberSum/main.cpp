#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

typedef std::array<int64_t, 3> triplet_t;


// Write a function that takes in a non-empty array of distinct integers and an
// integer representing a target sum. The function should find all triplets in
// the array that sum up to the target sum and return a two-dimensional array of
// all these triplets. The numbers in each triplet should be ordered in ascending
// order, and the triplets themselves should be ordered in ascending order with
// respect to the numbers they hold.
// If no three numbers sum up to the target sum, the function should return an
// empty array.
// Sample Input
// array = [12, 3, 1, 2, -6, 5, -8, 6]
// targetSum = 0
std::vector<triplet_t> get_triplets(std::vector<int64_t> &arr, int64_t target);

int main() {
	size_t size;
	int64_t target;
	std::cin >> size;
	std::vector<int64_t> arr(size);
	for (int64_t &i : arr)
		std::cin >> i;
	std::cin >> target;
	auto &&res = get_triplets(arr, target);
	for (auto &i : res) {
		for (int64_t j : i)
			std::cout << j << ' ';
		std::cout << '\n';
	}
	return 0;
}

std::vector<triplet_t> get_triplets(std::vector<int64_t> &arr, int64_t target) {

	std::sort(arr.begin(), arr.end());
	std::vector<triplet_t> results;
	for (size_t i = 0; i < arr.size(); ++i) {
		for (size_t l = i + 1, r = arr.size() - 1; l < r;) {
			int64_t curr_sum = arr[i] + arr[l] + arr[r];
			if (curr_sum == target) {
				results.push_back({arr[i], arr[l], arr[r]});
				++l;
			}
			if (curr_sum < target) {
				++l;
			}
			if (curr_sum > target) {
				--r;
			}
		}
	}
	return results;
}
