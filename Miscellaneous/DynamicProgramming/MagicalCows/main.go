package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

//https://open.kattis.com/problems/magicalcows

const (
	LimMaxCowsPerFarm         = 1000
	LimMaxFarmsWithOneCowDay0 = 1000
	LimRegulatorVisitDay      = 50
)

func getFarmConfig(maxCowsPerFarm int, initialFarmConfig []int, visits []int) [LimRegulatorVisitDay + 1][]int {
	// [x][y] ==> here, x = day on which regulator visits i.e. the state of farms on day x
	// y = maxCowsPerFarm + 1. The plus 1 is added because only maxCowsPerFarm number of cows can fit in a farm after which
	// we need to split the number of cows into half and in this process the number of farms doubles while the number of cows
	// in the farm <= maxCowsPerFarm. Remember y denotes the number of cows in the farm and allConfigs[x][y denotes
	// the number of farms such that number of cows = y on day x.
	var allConfigs = [LimRegulatorVisitDay + 1][]int{}
	for i := 0; i < LimRegulatorVisitDay+1; i++ {
		allConfigs[i] = make([]int, maxCowsPerFarm+1)
	}
	for _, cowFreq := range initialFarmConfig {
		allConfigs[0][cowFreq] += 1
	}
	lastVisit := -1
	for _, visit := range visits {
		if visit > lastVisit {
			lastVisit = visit
		}
	}
	if lastVisit >= LimRegulatorVisitDay {
		lastVisit = LimRegulatorVisitDay
	}
	for i := 0; i < lastVisit; i++ {
		for j := 1; j <= maxCowsPerFarm; j++ {
			if j <= maxCowsPerFarm/2 {
				allConfigs[i+1][2*j] += allConfigs[i][j]
			} else {
				allConfigs[i+1][j] += 2 * allConfigs[i][j]
			}
		}
	}
	return allConfigs
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	in, err := reader.ReadString('\n')
	if err != nil {
		panic(err)
	}
	splits := strings.Split(strings.TrimSpace(in), " ")
	maxCowsPerFarm, err := strconv.Atoi(splits[0])
	if err != nil {
		panic(err)
	}
	initialFarms, err := strconv.Atoi(splits[1])
	if err != nil {
		panic(err)
	}
	queries, err := strconv.Atoi(splits[2])
	if err != nil {
		panic(err)
	}
	initialFarmConfig := []int{}
	for i := 0; i < initialFarms; i++ {
		in, err := reader.ReadString('\n')
		if err != nil {
			panic(err)
		}
		intVal, err := strconv.Atoi(strings.TrimSpace(in))
		if err != nil {
			panic(err)
		}
		initialFarmConfig = append(initialFarmConfig, intVal)
	}
	visits := []int{}
	for i := 0; i < queries; i++ {
		in, err := reader.ReadString('\n')
		if err != nil {
			panic(err)
		}
		intVal, err := strconv.Atoi(strings.TrimSpace(in))
		if err != nil {
			panic(err)
		}
		visits = append(visits, intVal)
	}
	finalFarmConfigs := getFarmConfig(maxCowsPerFarm, initialFarmConfig, visits)
	for _, day := range visits {
		fmt.Println(answerQuery(finalFarmConfigs, day))
	}
}

func answerQuery(configs [51][]int, day int) int {
	answer := 0
	for i := 0; i < len(configs[day]); i++ {
		answer += configs[day][i]
	}
	return answer
}
