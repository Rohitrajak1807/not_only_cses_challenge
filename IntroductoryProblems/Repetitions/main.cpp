#include <iostream>

size_t max_substr_len(const std::string& sequence);

int main() {
	std::string sequence;
	std::cin >> sequence;
	std::cout << max_substr_len(sequence) << '\n';
	return 0;
}

size_t max_substr_len(const std::string& sequence) {
	size_t max_len = 1, curr_len = 1;
	for (size_t i = 1; i < sequence.length(); ++i) {
		if(sequence[i] == sequence[i - 1]) {
			curr_len++;
		} else {
			max_len = std::max(max_len, curr_len);
			curr_len = 1;
		}
	}
	max_len = std::max(max_len, curr_len);
	return max_len;
}
