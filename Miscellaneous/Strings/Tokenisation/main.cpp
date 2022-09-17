#include <iostream>
#include <sstream>
#include <vector>

std::vector<std::string> using_sstream(const std::string& in);

std::string tokenize(char *str, char delim);

int main() {
	std::string in;
	std::getline(std::cin, in, '\n');
	auto tokens = using_sstream(in);
	for (std::string& a: tokens) {
		std::cout << a << '\n';
	}
	char s[1000];
	std::cin.getline(s, 1000);
	std::string token = tokenize(s, ' ');
	while (!token.empty()) {
		std::cout << token << '\n';
		token = tokenize(nullptr, ' ');
	}
	return 0;
}

std::vector<std::string> using_sstream(const std::string& in) {
	std::stringstream stream(in);
	std::vector<std::string> tokens;
	while(stream.good()) {
		std::string tok;
		stream >> tok;
		tokens.emplace_back(tok);
	}
	return tokens;
}

std::string tokenize(char *str, char delim) {
	static char *input = nullptr;
	if (str != nullptr) {
		input = str;
	}
	if (input == nullptr) {
		return "";
	}
	std::string token;
	int32_t i = 0;
	for(;input[i] != '\0'; ++i) {
		if (input[i] != delim) {
			token.push_back(input[i]);
		} else {
			input = input + i + 1;
			return token;
		}
	}
	input = nullptr;
	return token;
}
