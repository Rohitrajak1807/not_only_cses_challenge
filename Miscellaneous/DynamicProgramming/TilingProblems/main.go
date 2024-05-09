package main

import (
	"bufio"
	"fmt"
	"os"
	"runtime/pprof"
	"strconv"
	"strings"
)

// input:
// Line1: <length of board>
func main() {
	reader := bufio.NewReader(os.Stdin)
	str, err := reader.ReadString('\n')
	if err != nil {
		panic(err)
	}
	str = strings.TrimSpace(str)
	boardLen, err := strconv.Atoi(str)
	if err != nil {
		panic(err)
	}
	tileSize1 := 1
	tileSize2 := 2
	f, err := os.Create("recurse.prof")
	if err != nil {
		panic(err)
	}
	defer func() {
		_ = f.Close()
	}()
	_ = pprof.StartCPUProfile(f)
	defer pprof.StopCPUProfile()
	fmt.Println(calculateTilingsRecursive(boardLen, tileSize1, tileSize2))
	fmt.Println(calculateTilingsMemo(boardLen, tileSize1, tileSize2))
	fmt.Println(calculateTilingsIterative(boardLen, tileSize1, tileSize2))
}

// calculateTilingsRecursive is a function which solves the following:
// recurrence relation: f(n) = f(n - 1) + f(n - 2)
// then f(n) = f(n - 1) + f(n - 2)
// which means the ways to arrange tiles such that the length is n is
// the sum of number of ways to arrange these tiles to get the boards of length n-1 and n-2
// say = 5, then f(5) = f(4) + f(3)
// number of ways to arrange tiles on a board of length 5 where the size of each tile is either 1
// or 2 is equal to the number of ways to arrange tiles on a board of length 4 and that of length 5
// this is a topdown approach
func calculateTilingsRecursive(boardLen, tileSize1, tileSize2 int) int64 {
	if boardLen == 0 {
		return 1
	}
	if boardLen < 0 {
		return 0
	}
	return calculateTilingsRecursive(boardLen-tileSize1, tileSize1, tileSize2) + calculateTilingsRecursive(boardLen-tileSize2, tileSize1, tileSize2)
}

// this is also a topdown approach
func calculateTilingsMemo(boardLen, tileSize1, tileSize2 int) int64 {
	memoTable := make([]int64, boardLen+1)
	memoTable[0] = 1
	memoTable[len(memoTable)-1] = _calculateTilingsMemo(boardLen, tileSize1, tileSize2, memoTable)
	return memoTable[len(memoTable)-1]
}

func _calculateTilingsMemo(boardLen int, size1 int, size2 int, memoTable []int64) int64 {
	if boardLen < 0 {
		return 0
	}
	if boardLen == 0 {
		return memoTable[0]
	}
	if memoTable[boardLen] != 0 {
		return memoTable[boardLen]
	}
	memoTable[boardLen] = _calculateTilingsMemo(boardLen-size1, size1, size2, memoTable) + _calculateTilingsMemo(boardLen-size2, size1, size2, memoTable)
	return memoTable[boardLen]
}

func calculateTilingsIterative(boardLen, tileSize1, tileSize2 int) int64 {
	if boardLen == 0 || boardLen == 1 {
		return 1
	}
	memoTable := make([]int64, boardLen+1)
	memoTable[0], memoTable[1] = 1, 1
	for i := 2; i < len(memoTable); i++ {
		memoTable[i] = memoTable[i-tileSize1] + memoTable[i-tileSize2]
	}
	return memoTable[len(memoTable)-1]
}
