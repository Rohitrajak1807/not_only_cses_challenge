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

int32_t grid_paths(const std::vector<std::string> &grid, int32_t size) {
	std::vector<std::vector<int32_t>> paths(grid.size(), std::vector<int32_t>(grid.size(), 0));
	if (grid.front().front() != TRAP)
		paths.front().front() = 1;
	for (int32_t i = 0; i < size; ++i) {
		for (int32_t j = 0; j < size; ++j) {
			if (grid[i][j] != TRAP) {
				if (i - 1 >= 0) {
					paths[i][j] += paths[i - 1][j];
					paths[i][j] %= MODULUS;
				}
				if (j - 1 >= 0) {
					paths[i][j] += paths[i][j - 1];
					paths[i][j] %= MODULUS;
				}
			}
		}
	}
	return paths.back().back();
}
