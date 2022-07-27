#include <iostream>
#include <vector>

// Given `n` non-negative integers representing an elevation map where the width of each bar is 1 unit, compute how much
// water it can trap after raining.
// Example:
// Input: [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
// Output: 6
// 4|
// 3|                     __
// 2|         __ ........|  |__ .. __
// 1|   __ ..|  |__    __|  |  |__|  |__
// 0|__|__|__|__|__|__|__|__|__|__|__|__|
// Here, in the diagram the region with `.` indicates water. In total, this elevation map captures 6 units of water.
size_t trapped_rain(const std::vector<int32_t> &elevations);

int main() {
	std::vector<int32_t> v{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	std::cout << trapped_rain(v);
	return 0;
}

size_t trapped_rain(const std::vector<int32_t> &elevations) {
	if (elevations.size() <= 2) {
		return 0;
	}
	std::vector<int32_t> max_left(elevations.size(), 0), max_right(elevations.size(), 0);
	max_left[0] = elevations[0];
	max_right[max_right.size() - 1] = elevations[elevations.size() - 1];
	for (size_t i = 1; i < elevations.size(); ++i) {
		max_left[i] = std::max(max_left[i - 1], elevations[i]);
		max_right[elevations.size() - i - 1] = std::max(max_right[elevations.size() - i],
		                                                elevations[elevations.size() - i - 1]);
	}
	size_t total_rain = 0;
	for (size_t i = 0; i < elevations.size(); ++i) {
		total_rain += std::min(max_left[i], max_right[i]) - elevations[i];
	}
	return total_rain;
}
