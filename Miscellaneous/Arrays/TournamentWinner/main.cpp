#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>

#define AWAY_WIN static_cast<int32_t>(0)
#define HOME_WIN 1
#define HOME_TEAM_IDX 0
#define AWAY_TEAM_IDX 1

// There's an algorithms tournament taking place in which teams of programmers
// compete against each other to solve algorithmic problems as fast as possible.
// Teams compete in a round robin, where each team faces off against all other
// teams. Only two teams compete against each other at a time, and for each
// competition, one team is designated the home team, while the other team is the
// away team. In each competition there's always one winner and one loser; there
// are no ties. A team receives 3 points if it wins and 0 points if it loses. The
// winner of the tournament is the team that receives the most amount of points.
// Given an array of pairs representing the teams that have competed against each
// other and an array containing the results of each competition, write a
// function that returns the winner of the tournament. The input arrays are named competitions
// and results, respectively. The competitions  array has elements in the form of
// [homeTeam, awayTeam], where each team is a string of at most 30
// characters representing the name of the team. The results array
// contains information about the winner of each corresponding competition in the
// competitions array. Specifically, results[i] denotes
// the winner of competitions[i], where a 1 in the results array means that the home team in the corresponding
// competition won and a 0 means that the away team won.
// It's guaranteed that exactly one team will win the tournament and that each
// team will compete against all other teams exactly once. It's also guaranteed
// that the tournament will always have at least two teams.
// sample input in Python
//competitions = [
// ['HTML', 'C#'],
// ['C#', 'Python'],
// ['Python', 'HTML']
// ]
// results = [0, 0, 1]

std::string
get_winning_team(const std::vector<std::array<std::string, 2>> &competitions, const std::vector<int32_t> &results);

int main() {
	size_t comp_size;
	std::cin >> comp_size;
	std::vector<std::array<std::string, 2>> competitions(comp_size);
	std::vector<int32_t> results(comp_size);
	for (std::array<std::string, 2> &comp : competitions)
		std::cin >> comp[0] >> comp[1];
	for (int32_t &i : results)
		std::cin >> i;
	std::cout << get_winning_team(competitions, results);
	return 0;
}

std::string
get_winning_team(const std::vector<std::array<std::string, 2>> &competitions, const std::vector<int32_t> &results) {
	std::unordered_map<std::string, int32_t> teams;
	for (const auto &competition : competitions) {
		for (const std::string &team : competition) {
			teams.emplace(team, 0);
		}
	}

	for (size_t i = 0; i < results.size(); ++i) {
		const std::array<std::string, 2> &curr_competition = competitions[i];
		if (results[i] == HOME_WIN) {
			teams[curr_competition[HOME_TEAM_IDX]] += 3;
		}
		if (results[i] == AWAY_WIN) {
			teams[curr_competition[AWAY_TEAM_IDX]] += 3;
		}
	}
	std::string winner;
	int64_t max_score = -1;
	for (auto&[team, score] : teams) {
		if (score > max_score) {
			winner = team;
			max_score = score;
		}
	}
	return winner;
}
