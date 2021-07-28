#include <iostream>

void sequence(int32_t n);

int main() {
	int32_t n;
	std::cin >> n;
	sequence(n);
	return 0;
}

void sequence(int32_t n) {
	if (n == 2 || n == 3) {
		std::cout << "NO SOLUTION\n";
		return;
	}
	for (int32_t i = 2; i <= n; i = i + 2) {
		std::cout << i << ' ';
	}
	for (int32_t i = 1; i <= n; i = i + 2) {
		std::cout << i << ' ';
	}
}
