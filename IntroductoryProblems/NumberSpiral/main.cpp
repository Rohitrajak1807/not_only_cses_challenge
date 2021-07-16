#include <iostream>

int64_t get_number_at(int64_t r, int64_t c);

int main() {
	int32_t t;
	std::cin >> t;
	while (t-- > 0) {
		int64_t r, c;
		std::cin >> r >> c;
		std::cout << get_number_at(r, c) << '\n';
	}
	return 0;
}

int64_t get_number_at(int64_t r, int64_t c) {
	int64_t layer = std::max(r, c);
	int64_t max_element_at_layer = layer * layer;
	int64_t r_dist, c_dist;
	if (layer % 2 == 0) {
//		element at (x, 1)
		r_dist = layer - r;
		c_dist = c - 1;
	} else {
//		element at (1, y)
		r_dist = r - 1;
		c_dist = layer - c;
	}
	return max_element_at_layer - r_dist - c_dist;
}
