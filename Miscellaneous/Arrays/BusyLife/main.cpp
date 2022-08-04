#include <iostream>
#include <vector>
#include <algorithm>

// Given a list of activities indicated by their start and end times, find the
// maximum number of activities that can be completed in a conflict-free
// manner: meaning that you cannot do two things at once. Once an activity
// has been selected, it must be done till completion before selecting the new task.
// At each such selection of tasks, only those tasks which have a start time of less
// than or equal to that of the previous task can be selected.
// Example:
// Input = [(7,9), (0,10), (4,5), (8,9), (4,10), (5,7)]
// Output = 3 // selected activities can be: [(4,5), (5,7), (8,9)]
int32_t count_activities(std::vector<std::pair<int32_t, int32_t>> activities);

int main() {
	std::vector<std::pair<int32_t, int32_t>> activities{
			{7, 9},
			{0, 10},
			{4, 5},
			{8, 9},
			{4, 10},
			{5, 7},

	};
	std::cout << count_activities(activities);
	return 0;
}

int32_t count_activities(std::vector<std::pair<int32_t, int32_t>> activities) {
	struct {
		bool operator() (const std::pair<int32_t, int32_t>& a, const std::pair<int32_t, int32_t>& b) {
			if (a.second == b.second) {
				return a.first < b.first;
			}
			return a.second < b.second;
		}

	} cmp;
	std::sort(activities.begin(), activities.end(), cmp);
	int32_t end_time = 0;
	int32_t total_activities = 0;
	for (auto& [start, end]: activities) {
		if (end_time <= start) {
			end_time = end;
			++total_activities;
		}
	}
	return total_activities;
}
