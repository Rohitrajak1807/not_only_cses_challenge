#include <iostream>
#include <unordered_map>
#define NO_SOLUTION "NO SOLUTION"

std::string get_palindrome(const std::string &str);

int main() {
	std::string in;
	std::cin >> in;
	std::cout << get_palindrome(in) << '\n';
	return 0;
}

std::string get_palindrome(const std::string &str) {
	std::unordered_map<char, uint64_t> char_count;
	for(const char& c : str) {
		if (char_count.find(c) == char_count.end()) {
			char_count.emplace(c, 1);
		} else {
			++char_count[c];
		}
	}
	uint64_t odd_count = 0L;
	char odd_char;
	for(auto&[c,count] : char_count) {
		if(count % 2 != 0) {
			++odd_count;
			odd_char = c;
		}
	}
	if(odd_count > 1 or (odd_count == 1 and str.length() % 2 == 0)) {
		return NO_SOLUTION;
	}
	std::string left, right;
	left.reserve((str.length() / 2 )+ 1);
	right.reserve((str.length() / 2 )+ 1);
	for(auto&[c,count] : char_count) {
		std::string s(count / 2, c);
		left.append(s);
		right.insert(0, s);
	}
	if (odd_count == 1) {
		std::string odd_chars(odd_count, odd_char);
		left.append(odd_chars);
	}
	return left + right;
}
