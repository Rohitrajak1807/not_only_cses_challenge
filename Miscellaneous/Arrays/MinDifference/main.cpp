#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

std::pair<int32_t, int32_t> min_difference(std::vector<int32_t> a, std::vector<int32_t> b);

int main() {
	std::vector<int32_t> a{1, 2, 11, 5};
	std::vector<int32_t> b{4, 12, 19, 23, 127, 235};
	std::pair<int32_t, int32_t> r = min_difference(a, b);
	std::cout << r.first << " " << r.second << std::endl;
	return 0;
}

std::pair<int32_t, int32_t> min_difference(std::vector<int32_t> a, std::vector<int32_t> b) {
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());
	int32_t min_abs_diff = std::numeric_limits<int32_t>::max();
	std::pair<int32_t, int32_t> res{};
	for (size_t i = 0, j = 0; i < a.size() and j < b.size();) {
		int32_t curr_abs_diff = std::abs(a[i] - b[j]);
		if (curr_abs_diff < min_abs_diff) {
			min_abs_diff = curr_abs_diff;
			res.first = a[i];
			res.second = b[j];
		}
		if (a[i] < b[j]) {
			++i;
		} else {
			++j;
		}

	}
	return res;
}
