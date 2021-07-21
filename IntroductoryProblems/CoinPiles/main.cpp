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

bool can_empty(uint64_t a, uint64_t b) {
	uint64_t min = std::min(a, b), max = std::max(a, b);
	if (max > 2 * min) {
		return false;
	} else if((min + max) % 3 == 0){
		return true;
	}
	return false;
}
