#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int64_t get_weight_diff(const std::vector<int64_t> &v);

int64_t get_min_diff(const std::vector<int64_t> &v, size_t i, int64_t total, int64_t curr_score_a);

int main() {
	size_t size;
	std::cin >> size;
	std::vector<int64_t> v(size);
	for (int64_t &i : v)
		std::cin >> i;
	std::cout << get_weight_diff(v) << '\n';
	return 0;
}

/*
 * In all honesty, I think It'd have been better if I'd recursed on the vector from start to end and not the other way
 * around. Otherwise, the idea is to take the min of the total score and then return it. There's another approach that
 * could be investigated as well- the idea being that `total` and `curr_score_a` will have the least difference when
 * `total ~ curr_score_a / 2`
 */
int64_t get_weight_diff(const std::vector<int64_t> &v) {
	int64_t total = std::accumulate(v.begin(), v.end(), 0L);
	size_t i = v.size() - 1;
	int64_t curr_score_a = 0L;
	int64_t score = get_min_diff(v, i, total, curr_score_a);
	return score;
}

int64_t get_min_diff(const std::vector<int64_t> &v, size_t i, int64_t total, int64_t curr_score_a) {
	if (i == 0)
		return std::abs((total - curr_score_a) - curr_score_a);
	curr_score_a = std::min(std::abs(get_min_diff(v, i - 1, total, curr_score_a + v[i])),
	                        std::abs(get_min_diff(v, i - 1, total, curr_score_a)));
	return curr_score_a;
}
