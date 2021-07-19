#include <iostream>

void count_arrangements(uint64_t size);

uint64_t controlled_squares(uint64_t size, uint64_t r, uint64_t c);

int main() {
	uint64_t size;
	std::cin >> size;
	count_arrangements(size);
	return 0;
}

void count_arrangements(uint64_t size) {
	for (uint64_t k = 1; k <= size; ++k) {
		uint64_t total_squares = k * k, arrangements = 0;
		for (uint64_t i = 0; i < k; ++i) {
			for(uint64_t j = 0; j < k; ++j) {
				arrangements += (total_squares - controlled_squares(k, i, j) - 1);
			}
		}
		std::cout << (arrangements / 2) << '\n';
	}
}

uint64_t controlled_squares(uint64_t size, uint64_t r, uint64_t c) {
	uint64_t r_con, c_con, controlled_squares = 0;

	r_con = r + 2;
	c_con = c - 1;
	if (r_con < size && c_con < size) {
		controlled_squares++;
	}

	r_con = r + 2;
	c_con = c + 1;
	if (r_con < size && c_con < size) {
		controlled_squares++;
	}

	r_con = r - 2;
	c_con = c + 1;
	if (r_con < size && c_con < size) {
		controlled_squares++;
	}

	r_con = r - 2;
	c_con = c - 1;
	if (r_con < size && c_con < size) {
		controlled_squares++;
	}

	r_con = r + 1;
	c_con = c + 2;
	if (r_con < size && c_con < size) {
		controlled_squares++;
	}

	r_con = r + 1;
	c_con = c - 2;
	if (r_con < size && c_con < size) {
		controlled_squares++;
	}

	r_con = r - 1;
	c_con = c + 2;
	if (r_con < size && c_con < size) {
		controlled_squares++;
	}

	r_con = r - 1;
	c_con = c - 2;
	if (r_con < size && c_con < size) {
		controlled_squares++;
	}
	return controlled_squares;
}
