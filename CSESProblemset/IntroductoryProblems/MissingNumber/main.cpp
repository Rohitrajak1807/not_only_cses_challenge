#include <iostream>
#include <vector>
#include <numeric>

int64_t missing_number(int64_t n, const std::vector<int64_t> &numbers);

int main() {
	int64_t n;
	std::cin >> n;
	std::vector<int64_t> numbers(n - 1);
	for (int64_t &number: numbers)
		std::cin >> number;
	std::cout << missing_number(n, numbers) << '\n';
	return 0;
}

int64_t missing_number(int64_t n, const std::vector<int64_t> &numbers) {
	int64_t sum = std::accumulate(numbers.begin(), numbers.end(), 0l);
	int64_t actual_sum = (n * (n + 1)) / 2;
	return actual_sum - sum;
}
