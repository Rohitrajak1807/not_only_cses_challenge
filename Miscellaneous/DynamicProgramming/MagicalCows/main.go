package main

import "fmt"

//https://open.kattis.com/problems/magicalcows

func getFarmConfig(maxCowsPerFarm int, initialFarmConfig []int, visits []int) [][]int {
	allConfigs := [][]int{
		initialFarmConfig,
	}
	lastVisit := -1
	for _, visit := range visits {
		if visit > lastVisit {
			lastVisit = visit
		}
	}
	for i := 1; i <= lastVisit; i++ {
		todaysConfig := []int{}
		previousDayCfg := allConfigs[i-1]
		for _, cows := range previousDayCfg {
			newCount := 2 * cows
			if newCount > maxCowsPerFarm {
				todaysConfig = append(todaysConfig, maxCowsPerFarm, newCount-maxCowsPerFarm)
			} else {
				todaysConfig = append(todaysConfig, newCount)
			}
		}
		allConfigs = append(allConfigs, todaysConfig)
	}
	return allConfigs
}

func main() {
	maxCowsPerFarm := 2
	initialFarms := 5
	queries := 3
	_ = queries
	_ = initialFarms
	initialFarmConfig := []int{1, 2, 1, 2, 1}
	visits := []int{0, 1, 2, 3, 4, 10}
	finalFarmConfigs := getFarmConfig(maxCowsPerFarm, initialFarmConfig, visits)
	fmt.Println(finalFarmConfigs)
	for _, day := range visits {
		fmt.Println(len(finalFarmConfigs[day]))
	}
}
