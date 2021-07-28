#include <iostream>
/*
 * The classic Tower of Hanoi needs 2^n - 1 moves at the least.
 * We employ the recursive approach here. The idea is as follows:
 * assume 3 stacks namely, from, via and to numbered 1,2 and 3 respectively.
 * For a problem size of n we move n - 1 disks from 1 to 2 via 3, then move the last
 * disk from 1 to 3 and then move the n - 1 disks from 2 to 3 via 1.
 */
void print_steps(int32_t n);

void tower_of_hanoi(int32_t n, int32_t from = 1, int32_t via = 2, int32_t to = 3);

int main() {
	int32_t n;
	std::cin >> n;
	print_steps(n);
	return 0;
}

void print_steps(int32_t n) {
	std::cout << ((1 << n) - 1) << '\n';
	tower_of_hanoi(n);
}

void tower_of_hanoi(int32_t n, int32_t from, int32_t via, int32_t to) {
	if (n == 0) {
		return;
	}
	tower_of_hanoi(n - 1, from, to, via);
	std::cout << from << ' ' << to << '\n';
	tower_of_hanoi(n - 1, via, from, to);
}
