#include <iostream>
#include <vector>
#include <algorithm>

/*
 * After thinking on it for days, I couldn't figure it out completely. I was able to generate 2^(n - 1) codes (i.e. half
 * of the total codes) using a recursive strategy, but couldn't quite figure it out.
 * So I referred to this article: https://www.geeksforgeeks.org/generate-n-bit-gray-codes/
 */

/*
 * The idea is to generate the list of gray codes for n - 1 bits (say l1), then we make a reversed copy of it (say l2).
 * Then to each element of l1 we prepend `0` and to each element of l2, we prepend `1`, then we concatenate l1 and l2
 * into l1 and repeat.
 */
std::vector<std::string> gray_codes(uint64_t n);

int main() {
	uint64_t n;
	std::cin >> n;
	auto&& codes = gray_codes(n);
	for (std::string& str: codes) {
		std::cout << str << '\n';
	}
	return 0;
}

std::vector<std::string> gray_codes(uint64_t n) {
	if (n == 0) {
		return {};
	}
	std::vector<std::string> codes{
			"0",
			"1"
	};
	for (uint64_t i = 1; i < n; ++i) {
		std::vector<std::string> reverse;
		std::reverse_copy(codes.begin(), codes.end(), std::back_inserter(reverse));
		std::for_each(codes.begin(), codes.end(), [](std::string &str) {
			str.insert(0, 1, '0');
		});
		std::for_each(reverse.begin(), reverse.end(), [](std::string &str) {
			str.insert(0, 1, '1');
		});
		std::copy(reverse.begin(), reverse.end(), std::back_inserter(codes));
	}
	return codes;
}
