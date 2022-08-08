#include <iostream>
#include <cstring>

#define MAX_LEN 10000

// Given a string, write a function to replace all the spaces in a string with '%20'. It is given that the string has
// sufficient space at the end to hold the additional characters.
// Example:
// Input: 'hello world'
// Output: 'hello%20world'
// Explanation: 'hello world' has one space as indicated which is replaced by '%20'
//                    ^
void replace_20pct(char *str);

int main() {
	char input[MAX_LEN];
	std::cin.getline(input, MAX_LEN);
	replace_20pct(input);
	std::cout << input;
	return 0;
}


void replace_20pct(char *str) {
	size_t spaces = 0;
	for (size_t i = 0; str[i] != '\0'; ++i) {
		if (str[i] == ' ') {
			++spaces;
		}
	}
	size_t final_idx = strlen(str) + (2 * spaces);
	str[final_idx] = '\0';
	for (size_t i = strlen(str); i > 0; --i) {
		if (str[i - 1] == ' ') {
			str[final_idx - 1] = '0';
			str[final_idx - 2] = '2';
			str[final_idx - 3] = '%';
			final_idx = final_idx - 3;
		} else {
			str[final_idx - 1] = str[i - 1];
			--final_idx;
		}
	}
}