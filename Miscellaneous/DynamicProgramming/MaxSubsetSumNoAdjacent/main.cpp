#include <iostream>
#include <vector>

int32_t max_sum_no_adj(const std::vector<int32_t> &v);

int main() {
	std::vector<int32_t> v = {75, 105, 120, 75, 90, 135};
	std::cout << max_sum_no_adj(v);
	return 0;
}

int32_t max_sum_no_adj(const std::vector<int32_t> &v) {
	if (v.empty())
		return 0;
	std::vector<int32_t> max_sum(v.size());
	max_sum[0] = v[0];
	max_sum[1] = std::max(v[0], v[1]);
	for (size_t i = 2; i < v.size(); ++i)
		max_sum[i] = std::max(max_sum[i - 2] + v[i], max_sum[i - 1]);

	return max_sum.back();
}
