#include <iostream>
#include <string>


// Convert absolute time in minutes into a format supported by a digital clock.
// Examples:
// 25 minutes can be displayed as 2:05
// 155 minutes can be displayed as 2:35
// (Assume the maximum value of minutes will be less than 24 X 60)
// Input is a single integer.
// 1180
// Output is a string denoting the digital clock time.
// 19:40

std::string to_digital(int32_t minutes) {
	int32_t hours = minutes / 60;
	minutes = minutes % 60;
	return std::to_string(hours) + ":" + (minutes < 10 ? "0" : "") + std::to_string(minutes);
}

int main() {
	std::cout << to_digital(123);
	return 0;
}
