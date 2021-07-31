#include <iostream>
#include <vector>

#define MODULUS 1000000007
#define TRAP '*'

int32_t grid_paths(const std::vector<std::string> &grid, int32_t size);

int main() {
	int32_t n;
	std::cin >> n;
	std::vector<std::string> grid;
	grid.reserve(n);
	for (int32_t i = 0; i < n; ++i) {
		std::string row;
		std::cin >> row;
		grid.emplace_back(row);
	}
	std::cout << grid_paths(grid, n);
	return 0;
}

//same thing, but less space i.e., O(2n) space
int32_t grid_paths(const std::vector<std::string> &grid, int32_t size) {
	std::vector<std::vector<int32_t>> paths(2, std::vector<int32_t>(size, 0));
	for (int32_t i = 0; i < size; ++i) {
		if (grid.front()[i] == TRAP)
			break;
		paths.front()[i] = 1;
	}
	int32_t i = 1;
	for (int32_t r = 1; r < size; ++r) {
		int32_t j = 0;
		for (int32_t c = 0; c < size; ++c) {
			if (grid[r][c] == TRAP)
				paths[i][j] = 0;
			else {
				int32_t total_ways = 0;
				if (j - 1 >= 0) {
					total_ways += paths[i][j - 1];
					total_ways %= MODULUS;
				}
				total_ways += paths[i ^ 1][j];
				total_ways %= MODULUS;
				paths[i][j] = total_ways;
			}
			j += 1;
		}
		i ^= 1;
	}
	return paths[(size - 1) % 2].back();
}
