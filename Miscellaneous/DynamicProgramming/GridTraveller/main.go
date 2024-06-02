package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	str, err := reader.ReadString('\n')
	if err != nil {
		panic(err)
	}
	str = strings.TrimSpace(str)
	splits := strings.SplitN(str, " ", 2)
	rows, err := strconv.Atoi(splits[0])
	if err != nil {
		panic(err)
	}
	cols, err := strconv.Atoi(splits[1])
	if err != nil {
		panic(err)
	}
	fmt.Println(travelRecurse(rows, cols))
	fmt.Println(travelRecurseMemo(rows, cols))
	fmt.Println(travelIterMemo(rows, cols))
	for i := range 30 {
		for j := range 30 {
			a2 := travelRecurseMemo(i, j)
			a3 := travelIterMemo(i, j)
			if a2 != a3 {
				panic(fmt.Sprintf("unequal answers i=%d, j=%d, a2=%d, a3=%d", i, j, a2, a3))
			}
		}
	}
}

func travelRecurse(rows int, cols int) int {
	return _travelRecurse(rows, cols)
}

func _travelRecurse(rows int, cols int) int {
	if rows == 0 || cols == 0 {
		return 0
	}
	if (rows == 1 && cols > 0) || (cols == 1 && rows > 0) {
		return 1
	}
	return _travelRecurse(rows-1, cols) + _travelRecurse(rows, cols-1)
}

func travelRecurseMemo(rows, cols int) int {
	if rows == 0 || cols == 0 {
		return 0
	}
	mem := make([][]int, rows+1)
	for i := 0; i < len(mem); i++ {
		mem[i] = make([]int, cols+1)
	}
	if rows >= 1 && cols >= 1 {
		mem[1][1] = 1
	}
	return _travelRecurseMemo(rows, cols, mem)
}

func _travelRecurseMemo(rows int, cols int, mem [][]int) int {
	if rows == 0 || cols == 0 {
		return 0
	}
	if mem[rows][cols] != 0 {
		return mem[rows][cols]
	}
	ans := _travelRecurseMemo(rows-1, cols, mem) + _travelRecurseMemo(rows, cols-1, mem)
	mem[rows][cols] = ans
	return ans
}

func travelIterMemo(rows, cols int) int {
	if rows == 0 || cols == 0 {
		return 0
	}
	mem := make([][]int, rows+1)
	for i := 0; i < len(mem); i++ {
		mem[i] = make([]int, cols+1)
	}
	if rows >= 1 && cols >= 1 {
		mem[1][1] = 1
	}
	for i := 0; i < len(mem); i++ {
		for j := 0; j < len(mem[0]); j++ {
			if i+1 <= rows {
				mem[i+1][j] += mem[i][j]
			}
			if j+1 <= cols {
				mem[i][j+1] += mem[i][j]
			}
		}
	}
	return mem[rows][cols]
}
