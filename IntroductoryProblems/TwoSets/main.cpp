#include <iostream>
#include <vector>

struct Vectors {
	std::vector<uint64_t> s1, s2;
};

void show_sets(uint64_t n);

Vectors make_sets(uint64_t n, uint64_t sum);


int main() {
	uint64_t n;
	std::cin >> n;
	show_sets(n);
	return 0;
}

void show_sets(uint64_t n) {
	uint64_t sum = (n * (n + 1)) / 2;
	if (sum % 2 != 0) {
		std::cout << "NO\n";
	} else {
		auto&&[s1, s2] = make_sets(n, sum);

		std::cout << s1.size() << '\n';
		for (uint64_t &i : s1)
			std::cout << i << ' ';
		std::cout << '\n';

		std::cout << s2.size() << '\n';
		for (uint64_t &j : s2)
			std::cout << j << ' ';
		std::cout << '\n';
	}
}


Vectors make_sets(uint64_t n, uint64_t sum) {
	uint64_t target_sum = sum / 2;
	std::cout << "YES\n";
	Vectors v;
	auto&[s1, s2] = v;
	while (n > 0) {
		if (n <= target_sum) {
			s1.emplace_back(n);
			target_sum -= n;
		} else {
			s2.emplace_back(n);
		}
		n--;
	}
	return v;
}