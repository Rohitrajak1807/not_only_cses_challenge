#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <unordered_set>
// Given an array containing `N` integers, and a target number `S` denoting a
// target sum. Find all distinct integers that can add up to form the target
// sum `S`. The numbers in each triplet should be ordered in ascending order,
// and the triplets should be ordered in ascending order too. Return an empty
// array if no such triplets exist.
// Example: array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 15], N = 10
// target = 18
// Output = [
//  [1, 2, 15],
//  [1, 8, 9],
//  [2, 7, 9],
//  [3, 6, 9],
//  [3, 7, 8],
//  [4, 5, 9],
//  [4, 6, 8],
//  [5, 6, 7],
// ]

typedef std::array<int32_t, 3> triplet;

std::vector<triplet> triplet_sum_brute(std::vector<int32_t> numbers, const int32_t& target);
std::vector<triplet> triplet_sum(std::vector<int32_t> numbers, const int32_t& target);

int main() {
	std::vector<int32_t> array = std::vector{1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
	int32_t target = 18;
	std::vector<triplet> bruteforce_result = triplet_sum_brute(array, target);
	for(const auto &result : bruteforce_result) {
		for(const auto &n: result) {
			std::cout << n << " ";
		}
		std::cout << '\n';
	}
	std::cout << '\n';
	std::vector<triplet> results = triplet_sum(array, target);
	for(const auto &result : results) {
		for(const auto &n: result) {
			std::cout << n << " ";
		}
		std::cout << '\n';
	}
	return 0;
}

std::vector<triplet> triplet_sum_brute(std::vector<int32_t> numbers, const int32_t& target) {
	std::vector<triplet> results;
	std::sort(numbers.begin(), numbers.end());
	for (size_t i = 0; i < numbers.size(); ++i) {
		for (size_t j = i + 1; j < numbers.size(); ++j) {
			for (size_t k = j + 1; k < numbers.size(); ++k) {
				if (numbers[i] + numbers[j] + numbers[k] == target) {
					results.emplace_back(triplet{numbers[i], numbers[j], numbers[k]});
				}
			}
		}
	}
	return results;
}

std::vector<triplet> triplet_sum(std::vector<int32_t> numbers, const int32_t& target) {
	std::sort(numbers.begin(), numbers.end());
	std::vector<triplet> results;
	for(ssize_t i = 0; i < numbers.size() - 2; ++i) {
		int32_t intermediate_target = target - numbers[i];
		for(size_t start = i + 1, end = numbers.size() - 1; start < end;) {
			if (numbers[start] + numbers[end] < intermediate_target) {
				++start;
			}
			if (numbers[start] + numbers[end] > intermediate_target) {
				--end;
			}
			if (numbers[start] + numbers[end] == intermediate_target) {
				results.emplace_back(triplet{numbers[i], numbers[start], numbers[end]});
				++start;
				--end;
			}
		}
	}
	return results;
}
