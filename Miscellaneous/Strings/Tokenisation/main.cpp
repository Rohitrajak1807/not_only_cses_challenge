#include <iostream>
#include <sstream>
#include <vector>

std::vector<std::string> using_sstream(const std::string& in);

int main() {
	std::string in;
	std::getline(std::cin, in, '\n');
	auto tokens = using_sstream(in);
	for (std::string& a: tokens) {
		std::cout << a << '\n';
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
