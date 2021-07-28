#include <iostream>
#include <vector>

size_t move_count(std::vector<int32_t>& arr);

int main() {
	size_t n;
	std::cin >> n;
	std::vector<int32_t> arr(n);
	for(int32_t& i : arr)
		std::cin >> i;
	std::cout << move_count(arr) << '\n';
	return 0;
}

size_t move_count(std::vector<int32_t>& arr) {
	size_t moves = 0;
	for (size_t i = 1; i < arr.size(); ++i) {
		if(arr[i] < arr[i - 1]) {
			moves += (arr[i - 1] - arr[i]);
			arr[i] += (arr[i - 1] - arr[i]);
		}
	}
	return moves;
}