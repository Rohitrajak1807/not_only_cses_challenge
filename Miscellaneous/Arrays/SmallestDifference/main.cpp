#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int32_t> smallest_difference(std::vector<int32_t> &v1, std::vector<int32_t> &v2);

int main() {
	std::vector<int32_t> v1{-1, 5, 10, 20, 28, 3};
	std::vector<int32_t> v2{26, 134, 135, 15, 17};
	auto &&numbers = smallest_difference(v1, v2);
	return 0;
}

std::vector<int32_t> smallest_difference(std::vector<int32_t> &v1, std::vector<int32_t> &v2) {
	std::vector<int32_t> res;
	std::sort(v1.begin(),  v1.end());
	std::sort(v2.begin(),  v2.end());
	int32_t min_diff = INT32_MAX;
	auto l1 = v1.begin();
	auto r2 = v2.begin();
	while(l1 != v1.end() and r2 != v2.end()) {
		int32_t curr_diff = *l1 - *r2;
		if(curr_diff == 0) {
			res = {*l1, *r2};
			break;
		}

	}
	return res;
}
