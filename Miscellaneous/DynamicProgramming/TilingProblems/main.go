package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// input for n-1 and n-2 tile sizes:
// Line1: <length of board>
// input for the general case:
// Line1: <len of board> <number of tiles>
// Line2: <size of tile1> <size of tile 2> ...
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
	fmt.Println(calculateTilingsRecursive(boardLen, tileSize1, tileSize2))
	fmt.Println(calculateTilingsMemo(boardLen, tileSize1, tileSize2))
	fmt.Println(calculateTilingsIterative(boardLen, tileSize1, tileSize2))

	line1, err := reader.ReadString('\n')
	if err != nil {
		panic(err)
	}
	line1 = strings.TrimSpace(line1)
	line1Splits := strings.Split(line1, " ")
	boardLen64, err := strconv.ParseInt(line1Splits[0], 10, 64)
	if err != nil {
		panic(err)
	}
	numTiles, err := strconv.Atoi(line1Splits[1])
	if err != nil {
		panic(err)
	}
	var tiles []int64
	tilesStr, err := reader.ReadString('\n')
	if err != nil {
		panic(err)
	}
	tilesStr = strings.TrimSpace(tilesStr)
	tilesSplits := strings.SplitN(tilesStr, " ", numTiles)
	for _, split := range tilesSplits {
		ti, err := strconv.ParseInt(split, 10, 64)
		if err != nil {
			panic(err)
		}
		tiles = append(tiles, ti)
	}

	fmt.Println(generalCalculateTilingsIterative(boardLen64, tiles))
	fmt.Println(generalCalculateTilingsRecursive(boardLen64, tiles))
}

// calculateTilingsRecursive is a function which solves the following:
// recurrence relation: f(n) = f(n - 1) + f(n - 2)
// then f(n) = f(n - 1) + f(n - 2)
// which means the ways to arrange tiles such that the length is n is
// the sum of number of ways to arrange these tiles to get the boards of length n-1 and n-2
// say = 5, then f(5) = f(4) + f(3)
// number of ways to arrange tiles on a board of length 5 where the size of each tile is either 1
// or 2 is equal to the number of ways to arrange tiles on a board of length 4 and that of length 5.
//
// This is a topdown approach.
func calculateTilingsRecursive(boardLen, tileSize1, tileSize2 int) int64 {
	if boardLen == 0 {
		return 1
	}
	if boardLen < 0 {
		return 0
	}
	return calculateTilingsRecursive(boardLen-tileSize1, tileSize1, tileSize2) + calculateTilingsRecursive(boardLen-tileSize2, tileSize1, tileSize2)
}

// calculateTilingsMemo is a memoized variant of calculateTilingsRecursive and solves the exact problem, but supplements
// itself with a table of pre-computed values to decrease recursion depth.
func calculateTilingsMemo(boardLen, tileSize1, tileSize2 int) int64 {
	memoTable := make([]int64, boardLen+1)
	memoTable[0] = 1
	memoTable[len(memoTable)-1] = _calculateTilingsMemo(boardLen, tileSize1, tileSize2, memoTable)
	return memoTable[len(memoTable)-1]
}

// _calculateTilingsMemo is the implementation, func for calculateTilingsMemo and this function starts the recursion by
// setting the correct parameters and making the initial recursion call.
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

// calculateTilingsIterative is an iterative approach for solving the problem discussed in calculateTilingsRecursive.
// This makes it a bottom up approach, as we form the solution for the final board by combining the solutions from
// boards of smaller lengths.
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

/*
generalCalculateTilingsIterative solves the general case of the problem solved by calculateTilingsRecursive.
Solving the general problem:
The general form of the problem can be described as the recursion:

f(n) = c_n-k*f(n - k) + c_n-(k-1)*f(n - k - 1) + c_n-(k-2)*f(n - k -2) ... + c_0*f(0)

where f(0) = 1, and f(n) = 0 when n <= 0

c_n-k is the number of types(frequency) of the tiles of length k

k is the max tile length

Meaning that if we want to solve for f(n) and we have a tile of size k,
then we can get the number of all the tilings of length n - k and append
a block of tile of size k to make the final size of the board as n.
Further, if there are c_k different types of tiles of length k, then we need to account
for all those types by multiplying the number of tilings by the frequency for the block of
that length.
*/
func generalCalculateTilingsIterative(boardLen int64, tiles []int64) int64 {
	memoTable := make([]int64, boardLen+1)
	memoTable[0] = 1
	tileFreq := map[int64]int64{}
	for _, tile := range tiles {
		tileFreq[tile] += 1
	}
	var i int64 = 1
	for ; i < boardLen+1; i++ {
		for tile, freq := range tileFreq {
			if tile > i {
				continue
			}
			memoTable[i] += memoTable[i-tile] * freq
		}
	}
	return memoTable[len(memoTable)-1]
}

// generalCalculateTilingsRecursive is a bottom up recursive approach to solve the problem discussed in generalCalculateTilingsIterative.
func generalCalculateTilingsRecursive(boardLen int64, tiles []int64) int64 {
	memoTable := make([]int64, boardLen+1)
	memoTable[0] = 1
	tileFreq := map[int64]int64{}
	for _, tile := range tiles {
		tileFreq[tile] += 1
	}
	return _generalCalculateTilingsRecursive(boardLen, memoTable, tileFreq)
}

// _generalCalculateTilingsRecursive is a helper that starts the recursion chain with the proper parameters
func _generalCalculateTilingsRecursive(boardLen int64, memoTable []int64, tileFreq map[int64]int64) int64 {
	if boardLen < 0 {
		return 0
	}
	if boardLen == 0 {
		return 1
	}
	if memoTable[boardLen] > 0 && boardLen > 0 {
		return memoTable[boardLen]
	}
	var count int64 = 0
	for tile, freq := range tileFreq {
		count += freq * _generalCalculateTilingsRecursive(boardLen-tile, memoTable, tileFreq)
	}
	memoTable[boardLen] = count
	return count
}
