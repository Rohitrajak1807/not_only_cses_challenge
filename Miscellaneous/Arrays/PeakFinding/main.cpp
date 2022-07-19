#include <iostream>
#include <vector>
#include <numeric>
// Write a function that takes an input array of distinct integers and returns the length of the highest peak.
// A peak is defined as adjacent integers that strictly increase until reaching a maxima after which they start
// strictly decreasing.
// At least 3 integers are needed for a peak.
// Example array = [5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4]
// Output = 9 // subsequence of [1, 2, 3, 4, 5, 4, 3, 2, 0]

int32_t find_max_peak_width(const std::vector<int32_t> &array);
int32_t peak_width(const std::vector<int32_t>& array, size_t peak);

int main() {
	std::vector<int32_t> array = {5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};
	std::cout << find_max_peak_width(array);
	return 0;
}

int32_t find_max_peak_width(const std::vector<int32_t> &array) {
	int32_t max_width = std::numeric_limits<int32_t>::min();
	for (size_t i = 1; i < array.size() - 1; ++i) {
		if(array[i - 1] < array[i] and array[i + 1] < array[i]) {
			int32_t width = peak_width(array, i);
			max_width = std::max(max_width, width);
		}
	}
	return max_width;
}

int32_t peak_width(const std::vector<int32_t>& array, size_t peak) {
	int32_t size = 0;
	for (size_t i = peak - 1; array[i] < array[i + 1] and i >= 0; --i) {
		++size;
	}
	for (size_t i = peak + 1; array[i] < array[i - 1] and i < array.size(); ++i) {
		++size;
	}
	return size + 1;
}