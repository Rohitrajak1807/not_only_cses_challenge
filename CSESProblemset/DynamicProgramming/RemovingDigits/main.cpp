#include <iostream>
#include <vector>

int32_t remove_digits(int32_t n);

void remove_current_digit(int32_t current_idx, std::vector<int32_t>& table);

int main() {
	int32_t target;
	std::cin >> target;
	std::cout << remove_digits(target) << '\n';
	return 0;
}

int32_t remove_digits(int32_t n) {
	std::vector<int32_t> table(n + 1, -1);
	table.back() = 0;
	for (int32_t i = n; i >= 0; --i) {
		if (table[i] != -1) {
			remove_current_digit(i, table);
		}
	}
	return table.front();
}

void remove_current_digit(int32_t current_idx, std::vector<int32_t>& table) {
	int32_t i = current_idx;
	while (current_idx != 0) {
		int32_t digit = current_idx % 10;
		current_idx /= 10;
		if (i - digit >= 0) {
			if (table[i - digit] == -1) {
				table[i - digit] = table[i] + 1;
			} else {
				table[i - digit] = std::min(table[i] + 1, table[i - digit]);
			}
		}
	}
}
