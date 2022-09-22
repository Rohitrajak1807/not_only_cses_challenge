#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> sorted_subseqs(std::string &in);

void sorted_subseqs_impl(std::string &in, const std::string& curr_string, std::vector<std::string> &out);

int main() {
	std::string in = "abcd";
	std::vector<std::string> out = sorted_subseqs(in);
	for (const std::string &s: out) {
		std::cout << s << '\n';
	}
	return 0;
}

std::vector<std::string> sorted_subseqs(std::string &in) {
	std::vector<std::string> out;
	sorted_subseqs_impl(in, "", out);
	std::sort(out.begin(), out.end(), [](const std::string &a, const std::string &b) {
		if (a.length() == b.length()) {
			return a < b;
		}
		return a.length() < b.length();
	});
	return out;

}

void sorted_subseqs_impl(std::string &in, const std::string& curr_string, std::vector<std::string> &out) {
	if (in.empty()) {
		out.emplace_back(curr_string);
		return;
	}
	char ch = in[0];
	std::string reduced_str = in.substr(1);
	sorted_subseqs_impl(reduced_str, curr_string + ch, out);
	sorted_subseqs_impl(reduced_str, curr_string, out);
}
