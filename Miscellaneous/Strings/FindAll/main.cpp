#include <iostream>
#include <string>
#include <vector>

std::vector<size_t> find_all(std::string_view str, std::string_view target);

int main() {
	std::string longer = "I liked the movie, acting in movie was great!";
	std::string shorter = "movie";
	auto res = find_all(longer, shorter);
	for (size_t &i: res) {
		std::cout << i << ' ';
	}
	return 0;
}

std::vector<size_t> find_all(const std::string_view str, const std::string_view target) {
	std::vector<size_t> result{};
	size_t pos = str.find(target);
	while (pos != std::string::npos) {
		result.emplace_back(pos);
		pos = str.find(target, pos + 1);
	}
	return result;
}
