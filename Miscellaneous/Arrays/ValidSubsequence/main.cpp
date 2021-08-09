#include <iostream>
#include <vector>
// A subsequence of an array is a set of numbers that aren't necessarily adjacent in the array but that are in the same
// order as they appear in the array. For instance, the numbers [1, 3, 4]  form a subsequence of the array [1, 2, 3, 4],
// and so do the numbers [2, 4]. Note that a single number in an array and the array itself are both valid subsequences of
// the array.

bool validate_subsequence(const std::vector<int64_t> &arr, const std::vector<int64_t> &sequence);

int main() {
	size_t arr_size, seq_size;
	std::cin >> arr_size >> seq_size;
	std::vector<int64_t> arr(arr_size);
	std::vector<int64_t> sequence(seq_size);
	for (int64_t &i : arr)
		std::cin >> i;
	for (int64_t &i : sequence)
		std::cin >> i;
	std::cout << std::boolalpha << validate_subsequence(arr, sequence);
	return 0;
}

bool validate_subsequence(const std::vector<int64_t> &arr, const std::vector<int64_t> &sequence) {
	size_t seq_idx = 0;
	for(const int64_t& i : arr) {
		if(seq_idx == sequence.size())
			break;
		if(i == sequence[seq_idx]) {
			seq_idx++;
		}
	}
	return seq_idx == sequence.size();
}
