package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	modulo int = 1000000000 + 7
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	nStr, err := reader.ReadString('\n')
	if err != nil {
		panic(err)
	}
	nStr = strings.TrimSpace(nStr)
	num, err := strconv.Atoi(nStr)
	if err != nil {
		panic(err)
	}
	fmt.Println(tileRecurse(num))
	fmt.Println(tileIterative(num))
	for i := range 1000 {
		val1 := tileRecurse(i)
		val2 := tileIterative(i)
		if val1 != val2 {
			panic(fmt.Sprintf("expected %d got %d iteration %d", val1, val2, i))
		}
	}
}

/*
there are 4 possible states to keep track of:
00,01,10,11
dp[i][0] += dp[i - 1][3]
dp[i][1] += dp[i - 1][2] + 1
dp[i][2] += dp[i - 1][1] + 1
dp[i][3] += dp[i - 1][3] + dp[i - 1][0]

^ Hold this thought for the iterative solution

|-----|------|------|------|
|     |      |   t1 |  t3  |
|-----|------|------|------|
|     |      |   t2 |  t4  |
|-----|------|------|------|

t1,t2,t3 and t4 represent the cells which can be filled in the ith iteration
*/
func tileRecurse(num int) int {
	dp := make([][4]int, num+1)
	val := _tileRecurse(0, num, true, true, dp)
	return val
}

func _tileRecurse(i, num int, isT1Free, isT2Free bool, dp [][4]int) int {
	if i == num {
		return 1
	}
	state := makeState(isT1Free, isT2Free)
	if dp[i][state] != 0 {
		return dp[i][state]
	}
	canTileT3, canTileT4 := i+1 < num, i+1 < num
	count := 0
	if isT1Free && isT2Free && canTileT3 {
		count += _tileRecurse(i+1, num, false, true, dp) % modulo
	}
	if isT1Free && isT2Free && canTileT4 {
		count += _tileRecurse(i+1, num, true, false, dp) % modulo
	}
	if isT1Free && !isT2Free && canTileT3 && canTileT4 {
		count += _tileRecurse(i+1, num, false, false, dp) % modulo
	}
	if !isT1Free && isT2Free && canTileT3 && canTileT4 {
		count += _tileRecurse(i+1, num, false, false, dp) % modulo
	}
	if isT1Free && isT2Free {
		count += _tileRecurse(i+1, num, true, true, dp) % modulo
	}
	if isT1Free && isT2Free && canTileT3 && canTileT4 {
		count += _tileRecurse(i+1, num, false, false, dp) % modulo
	}
	if isT1Free && !isT2Free && canTileT3 {
		count += _tileRecurse(i+1, num, false, true, dp) % modulo
	}
	if !isT1Free && isT2Free && canTileT4 {
		count += _tileRecurse(i+1, num, true, false, dp) % modulo
	}
	if !isT1Free && !isT2Free {
		count += _tileRecurse(i+1, num, true, true, dp)
	}
	dp[i][state] = count % modulo
	return dp[i][state]
}

func makeState(t1, t2 bool) int {
	state := 0 // 00 state
	if t1 {
		state |= 1 // 01 state
	}
	if t2 {
		state |= 2 // 10 state
	}
	return state // if both t1 and t2 are true then state becomes the 11 state
}

/*
there are 4 possible states to keep track of:
00,01,10,11
dp[i][0] += dp[i - 1][3]
dp[i][1] += dp[i - 1][2] + 1
dp[i][2] += dp[i - 1][1] + 1
dp[i][3] += dp[i - 1][3] + dp[i - 1][0]

|-----|------|------|------|
|     |      |   t1 |  t3  |
|-----|------|------|------|
|     |      |   t2 |  t4  |
|-----|------|------|------|

t1,t2,t3 and t4 represent the cells which can be filled in the ith iteration

The solution isn't complete, iterative solution seems to calculate a higher number, the first occurrence of this is at
i = 28
*/
func tileIterative(num int) int {
	dp := make([][4]int, num+1)
	dp[0][3] = 1
	for i := 1; i < len(dp); i++ {
		dp[i][0] += dp[i-1][3] % modulo
		dp[i][1] += (dp[i-1][2] % modulo) + (dp[i-1][0] % modulo)
		dp[i][2] += (dp[i-1][1] % modulo) + (dp[i-1][0] % modulo)
		dp[i][3] += (dp[i-1][3] % modulo) + (dp[i-1][0] % modulo) + (dp[i-1][1] % modulo) + (dp[i-1][2] % modulo)

	}
	return dp[num][3]
}
