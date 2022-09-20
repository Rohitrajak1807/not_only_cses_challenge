#include <iostream>
#include <string>

bool is_subseq(const std::string &str, const std::string &subseq);

int main() {
	std::string str = "here i am this is me";
	std::string subseq = "hiie";
	std::cout << std::boolalpha << is_subseq(str, subseq);
	return 0;
}

bool is_subseq(const std::string &str, const std::string &subseq) {
	bool is_subseq = false;
	size_t i = 0, j = 0;
	for (; i < str.length() && j < subseq.length();) {
		if (str[i] == subseq[j]) {
			++i;
			++j;
		}
		++i;
	}
	if (j == subseq.length()) {
		is_subseq = true;
	}
	return is_subseq;
}
