#include <iostream>
#include <set>
#include <algorithm>

void permute(std::string &str, size_t l, size_t r, std::set<std::string>& words);

int main() {
	std::set<std::string> words;
	std::string str;
	std::cin >> str;
	std::sort(str.begin(), str.end());
	permute(str, 0, str.length() - 1, words);
	std::cout << words.size() << '\n';
	for(auto& word: words)
		std::cout << word << '\n';
}

void permute(std::string &str, size_t l, size_t r, std::set<std::string> &words) {
	if(l == r) {
		words.insert(str);
	} else {
		for(size_t i = l; i <= r; i++) {
			std::swap(str[l], str[i]);
			permute(str, l + 1, r, words);
			std::swap(str[l], str[i]);
		}
	}
}
