#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

// Given an array of size N, find the minimum number of swaps needed to sort it.
// Example:
// Input: [2, 4, 5, 1, 3]
// Output: 3
// Explanation:
// - Swap 2 with 1
// - Swap 4 with 2
// - Swap 5 with 3
size_t count_min_swaps(const std::vector<int32_t> &v);

int main() {
	std::vector<int32_t> v{2, 4, 5, 1, 3};
	std::cout << count_min_swaps(v);
	return 0;
}

size_t count_min_swaps(const std::vector<int32_t> &v) {
	size_t ans = 0;
	std::vector<std::pair<int32_t, size_t>> sorted{};
	for (size_t i = 0; i < v.size(); ++i) {
		sorted.emplace_back(std::make_pair(v[i], i));
	}
	std::sort(sorted.begin(), sorted.end());
	std::vector<bool> visited(v.size(), false);
	for (size_t i = 0; i < sorted.size(); ++i) {
		auto &[_, old_idx] = sorted[i];
		if (visited[i] or old_idx == i) {
			continue;
		}
		size_t node = i;
		size_t cycle = 0;
		while (!visited[node]) {
			visited[node] = true;
			size_t next_node = sorted[node].second;
			node = next_node;
			++cycle;
		}
		ans += cycle - 1;
	}
	return ans;
}
