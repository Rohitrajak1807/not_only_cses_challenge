#include <iostream>
#include <unordered_map>
#define NO_SOLUTION "NO SOLUTION"

std::string get_palindrome(const std::string &str);
/*
 * The idea is to get the frequency of each character. This is done using a hash map containing <char: freq> pairs.
 * After that we find the number of characters with odd frequencies. If this number is equal to 1, but the length of
 * input string is even, then we cannot form a palindrome, or if the number of odd characters is greater than one, then
 * we cannot form a palindrome. After these cases, we now form the palindrome by iterating on the hash map and construct
 * the two halves of the string, say l and r by appending and prepending respectively each character half of it's
 * frequency floored times to l and r. After that, if number of characters with odd
 */

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
		std::string odd_chars(1, odd_char);
		left.append(odd_chars);
	}
	return left + right;
}
