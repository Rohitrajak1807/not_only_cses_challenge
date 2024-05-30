package main

import (
	"fmt"
)

const modulo = 10e9 + 7

func main() {
	length := 4
	h := 2
	w := 2
	fmt.Println(mountainScenes(length, h, w))
	//fmt.Println(mountainScenesIterative(length, h, w))
}

func mountainScenes(length int, h int, w int) int {
	plainScenes := countPlainScenes(length, h, w)
	dp := make([][]int, w+1)
	for i := 0; i < len(dp); i++ {
		dp[i] = make([]int, length+1)
	}
	return ((_allScenes(h, w, 1, length, dp) - plainScenes) + modulo) % modulo
}

func countPlainScenes(length, h, w int) int {
	maxRibbons := min(w*h, length)
	return (maxRibbons / w) + 1
}

func _allScenes(hMax int, wMax int, w int, ribbonLen int, dp [][]int) int {
	if ribbonLen < 0 {
		return 0
	}
	if w > wMax {
		return 1
	}
	if dp[w][ribbonLen] != 0 {
		return dp[w][ribbonLen]
	}
	scenes := 0
	for i := 0; i < hMax+1; i++ {
		scenes = (scenes + _allScenes(hMax, wMax, w+1, ribbonLen-i, dp)) % modulo
	}
	dp[w][ribbonLen] = scenes
	return scenes
}

//func mountainScenesIterative(length, h, w int) int {
//	plainScenes := countPlainScenes(length, h, w)
//	dp := make([][]int, w+1)
//	for i := 0; i < len(dp); i++ {
//		dp[i] = make([]int, length+1)
//	}
//	dp[0][0] = 1
//	for i := 0; i < len(dp); i++ {
//		dp[i][0] = 1
//	}
//	return plainScenes
//}
