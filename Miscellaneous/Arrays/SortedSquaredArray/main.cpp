#include <iostream>
#include <vector>

std::vector<int64_t> sort_squared(const std::vector<int64_t> &arr);

int main() {
	size_t size;
	std::cin >> size;
	std::vector<int64_t> arr(size);
	for (int64_t &i : arr)
		std::cin >> i;
	std::vector<int64_t> &&sorted = sort_squared(arr);
	for (int64_t &i : sorted)
		std::cout << i << ' ';
	return 0;
}

std::vector<int64_t> sort_squared(const std::vector<int64_t> &arr) {
	std::vector<int64_t> sorted(arr.size());
	auto i = arr.begin();
	auto j = arr.rbegin();
	for (auto k = sorted.rbegin(); k != sorted.rend(); ++k) {
		if (std::abs(*i) > std::abs(*j)) {
			*k = *i * *i;
			++i;
		} else {
			*k = *j * *j;
			++j;
		}
	}
	return sorted;
}
