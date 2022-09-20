#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

enum SortType {
	numeric,
	lexicographic
};

std::vector<std::string> sort_strings(const std::vector<std::string>& in, bool reverse, SortType sort_t, int32_t key_pos);
std::string key_at(const std::string& str, size_t pos);

int32_t to_int(const std::string &in);

bool lexicographic_compare(const std::pair<std::string, std::string>& a, const std::pair<std::string, std::string>& b);

bool numeric_compare(const std::pair<std::string, std::string>& a, const std::pair<std::string, std::string>& b);

int main() {
	std::vector<std::string> in{
		"92, 022",
		"82, 12",
		"77, 13",
	};
	int32_t sort_key = 2;
	bool reverse = true;
	SortType sortType = lexicographic;
	std::vector<std::string> out = sort_strings(in, reverse, sortType, sort_key);
	for (std::string &i: out) {
		std::cout << i << '\n';
	}
	return 0;
}

std::vector<std::string> sort_strings(const std::vector<std::string>& in, bool reverse, SortType sort_t, int32_t key_pos) {
	std::vector<std::pair<std::string, std::string>> str_with_key;
	for (const auto & i : in) {
		str_with_key.emplace_back(
			i, key_at(i, key_pos)
		);
	}

	if(sort_t == lexicographic) {
		std::sort(str_with_key.begin(), str_with_key.end(), lexicographic_compare);
	} else {
		std::sort(str_with_key.begin(), str_with_key.end(), numeric_compare);
	}
	if (reverse) {
		std::reverse(str_with_key.begin(), str_with_key.end());
	}
	std::vector<std::string> out;
	for (auto &[str, _]: str_with_key) {
		out.emplace_back(str);
	}
	return out;
}

std::string key_at(const std::string& str, size_t pos) {
	std::stringstream in(str);
	std::string tok;
	while (in.good() and pos > 1) {
		in >> tok;
	}
	return tok;
}

int32_t to_int(const std::string &in) {
	int32_t res = 0;
	int32_t pow = 1;
	for(size_t i = in.length(); i > 0; --i) {
		res += (in[i] - '0') * pow;
		pow *= 10;
	}
	return res;
}

bool lexicographic_compare(const std::pair<std::string, std::string>& a, const std::pair<std::string, std::string>& b) {
	std::string k1 = a.second;
	std::string k2 = b.second;
	return k1 < k2;
}

bool numeric_compare(const std::pair<std::string, std::string>& a, const std::pair<std::string, std::string>& b) {
	std::string k1 = a.second;
	std::string k2 = b.second;
	return to_int(k1) < to_int(k2);
}