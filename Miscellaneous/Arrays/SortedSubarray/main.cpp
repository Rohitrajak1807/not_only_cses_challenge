#include <iostream>
#include <vector>
#include <limits>

typedef struct {
	size_t start;
	size_t end;
} Range;

// Given an array of size at least two, find the smallest subarray that needs
// to be sorted in place, so that the entire input array becomes sorted.
// If the input array is already sorted, the function should return [0, 0],
// otherwise return the start and the end index of the smallest subarray.
// Example:
// Input: [1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11]
// Output: [5, 7]
// Explanation: given                               [1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11]
// we have these indices:                           [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
// to sort the entire array, we only need to sort:                  ^     ^
// which correspond to indices: [5, 7]
Range sorted_subarr(const std::vector<int32_t>& arr);

bool is_out_of_order(const std::vector<int32_t>& arr, size_t i);

int main() {
	std::vector<int32_t> v{1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
	auto res = sorted_subarr(v);
	std::cout << res.start << "\t" << res.end;
	return 0;
}

Range sorted_subarr(const std::vector<int32_t>& arr) {
	int32_t smallest = std::numeric_limits<int32_t>::max();
	int32_t largest = std::numeric_limits<int32_t>::min();
	for (size_t i = 0; i < arr.size(); ++i) {
		if (is_out_of_order(arr, i)) {
			smallest = std::min(smallest, arr[i]);
			largest = std::max(largest, arr[i]);
		}
	}
	if (smallest == std::numeric_limits<int32_t>::max()) {
		return {.start=0, .end=0};
	}
	size_t left = 0, right = arr.size() - 1;
	while(smallest >= arr[left]) {
		++left;
	}
	while(largest <= arr[right]) {
		--right;
	}
	return {.start=left, .end=right};
}


bool is_out_of_order(const std::vector<int32_t>& arr, size_t i) {
	if (i == 0) {
		return arr[i] > arr[i + 1];
	}
	if (i == arr.size() - 1) {
		return arr[i] < arr[i - 1];
	}

	return (arr[i] < arr[i - 1]) or (arr[i] > arr[i + 1]);
}