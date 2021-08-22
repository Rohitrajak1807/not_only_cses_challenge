#include <iostream>
#include <set>
#include <vector>

// this is a time optimal approach. If we require a space optimal approach for increased complexity, then we can sort the
// array. Given `a` is input array, the pseudocode for that idea is:
// a.sort()
// last = None
// count = 0
// for i in a:
//  if last != i:
//	    count+=1
//	last = i
// return count
size_t distinct_numbers(const std::vector<int32_t> &v);

int main() {
	size_t size;
	std::cin >> size;
	std::vector<int32_t> v(size);
	for(int32_t& i : v)
		std::cin >> i;
	std::cout << distinct_numbers(v);
	return 0;
}

size_t distinct_numbers(const std::vector<int32_t> &v) {
	std::set<int32_t> numbers;
	for(const int32_t& i : v)
		numbers.emplace(i);
	return numbers.size();
}
