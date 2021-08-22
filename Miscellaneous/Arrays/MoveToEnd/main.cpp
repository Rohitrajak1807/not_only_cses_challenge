#include <iostream>
#include <vector>


//  You're given an array of integers and an integer. Write a function that moves
//  all instances of that integer in the array to the end of the array and returns
//  the array.
//  The function should perform this in place (i.e., it should mutate the input
//  array) and doesn't need to maintain the order of the other integers.
//  Sample Input
//  array = [2, 1, 2, 2, 2, 3, 4, 2]
//  to_move = 2
//  Sample Output
//  [1, 3, 4, 2, 2, 2, 2, 2] // the numbers 1, 3, and 4 could be ordered differently
void move_to_end(std::vector<int32_t> &v, int32_t to_move);

int main() {
	std::vector<int32_t> v = {2, 1, 2, 2, 2, 3, 4, 2};
	int32_t to_move = 2;
	move_to_end(v, to_move);
	for (int32_t &i : v)
		std::cout << i << '\n';
	return 0;
}

void move_to_end(std::vector<int32_t> &v, int32_t to_move) {
	// I could've used size_t but end runs in the risk of decrementing once more after reaching 0
	int64_t start = 0L,
			end = v.size() - 1;
	while (start < end) {
		while (start < end and v[end] == to_move)
			end--;
		if (v[start] == to_move)
			std::swap(v[start], v[end]);
		++start;
	}
}
