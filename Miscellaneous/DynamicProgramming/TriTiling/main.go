package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

/*
Problem: in how many ways can you tile a 3xN rectangle grid with 2x1 dominoes
where N is an integer between 0 and 30

https://open.kattis.com/problems/tritiling
*/

func main() {
	scanner := bufio.NewReader(os.Stdin)
	for {
		line, err := scanner.ReadString('\n')
		if err != nil {
			panic(err)
		}
		line = strings.TrimSpace(line)
		num, err := strconv.Atoi(line)
		if err != nil {
			panic(err)
		}
		if num == -1 {
			break
		}
		if num > 30 {
			break
		}
		fmt.Println(tile(num))
	}
}

/*
Observations: can we determine all the ways of tiling the board up to the column index i+1 given
we know all the ways to tile the board upto ith column? Yes!
But to do it, we need more information than just the number of columns which are fully filled up to
index i. We will also need to account for cases where a column is partially filled, because on adding
tiles to such states, a complete state can be generated.

For example:

	0		 1		   2		 3		   4        5

---------|---------|---------|---------|--------|--------|
|   x    |    x    |    x    |         |        |        |
|________|_________|_________|_________|________|________|
|   x    |    x    |    x    |         |        |        |
|________|_________|_________|_________|________|________|
|   x    |    x    |    x    |    x    |        |        |
|________|_________|_________|_________|________|________|

If in the above diagram the cells marked with x are filled with a domino, then the column at index 3 is
partially filled which can be fully filled by putting a 2x1 domino covering [3][0] and [3][1] positions.
If we examine a column, then there are 3 cells and in each cell, there are two possibilities, either the
cell is filled or empty which totals to 2^3 = 8 states per column.
We assign a number to each of them from 0 to 7

000 -> 0

001 -> 1

010 -> 2

011 -> 3

100 -> 4

101 -> 5

110 -> 6

111 -> 7

See this like so:

000 translates to

|---|
|   |
|___|
|   |
|___|
|   |
|___|

i.e. all the cells of the column being empty.
001 translates to the top cell being occupied and the bottom two being empty. Similarly, 011(3)
translates to the top two cells being occupied and the bottom one being empty.

The goal of our approach is to find all the partially filled column states column wise until we
reach the end and find the total number of fully filled states of the grid. Also, note that not
all states can be created with 2x1 dominoes. This is expected, and such arrangements just won't
contribute to the total number of possible tilings, but we still track it. For example, a partially
filled column of state 2 doesn't contribute to total number of arrangements.

The last part is transitioning between states in the dp table.
dp[i][1] += dp[i -1][6]

dp[i][2] += dp[i -1][5]

dp[i][3] += dp[i - 1][7] + dp[i - 1][4]

dp[i][4] += dp[i - 1][3]

dp[i][5] += dp[i - 1][2]

dp[i][6] += dp[i - 1][7] + dp[i - 1][1]

dp[i][7] += dp[i - 1][6] + dp[i - 1][3] + dp[i - 1][0]

The last thing is deciding on how to tile the empty state, (state 0).
This is an edge case we must handle. Think about it! It's always:

dp[i][0] = dp[i-1][7]
*/
func tile(num int) int {
	dp := make([][8]int, num+1)
	dp[0][7] = 1
	for i := 1; i < len(dp); i++ {
		dp[i][0] += dp[i-1][7]
		dp[i][1] += dp[i-1][6]
		//dp[i][2] += dp[i-1][5]
		dp[i][3] += dp[i-1][7]
		dp[i][3] += dp[i-1][4]
		dp[i][4] += dp[i-1][3]
		//dp[i][5] += dp[i-1][2]
		dp[i][6] += dp[i-1][1]
		dp[i][6] += dp[i-1][7]
		dp[i][7] += dp[i-1][0]
		dp[i][7] += dp[i-1][3]
		dp[i][7] += dp[i-1][6]
	}
	return dp[num][7]
}
