#include <iostream>

bool can_empty(uint64_t a, uint64_t b);

int main() {
	uint64_t t;
	std::cin >> t;
	while (t-- > 0) {
		uint64_t a, b;
		std::cin >> a >> b;
		std::cout << (can_empty(a, b) ? "YES" : "NO") << '\n';
	}
	return 0;
}

inline bool can_empty(uint64_t a, uint64_t b) {
	return (a + b) % 3 == 0 and std::max(a, b) <= 2 * std::min(a, b);
}
