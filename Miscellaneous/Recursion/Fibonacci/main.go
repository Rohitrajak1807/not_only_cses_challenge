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
	n, err := strconv.Atoi(str)
	if err != nil {
		panic(err)
	}
	fmt.Println(fibonacciRecurse(n))
	fmt.Println(fibonacciRecurseMemo(n))
	fmt.Println(fibonacciMemoIter(n))
	fmt.Println(fibonacciIter(n))
}

func fibonacciRecurse(n int) int {
	return _fibonacciRecurse(n)
}

func _fibonacciRecurse(n int) int {
	if n == 0 {
		return 0
	}
	if n == 1 || n == 2 {
		return 1
	}
	return _fibonacciRecurse(n-1) + _fibonacciRecurse(n-2)
}

func fibonacciRecurseMemo(n int) int {
	mem := make([]int, n+1)
	return _fibonacciRecurseMemo(n, mem)
}

func _fibonacciRecurseMemo(n int, mem []int) int {
	if n == 0 {
		mem[n] = 0
		return 0
	}
	if n == 1 || n == 2 {
		mem[n] = 1
		return 1
	}

	ans := _fibonacciRecurseMemo(n-1, mem) + _fibonacciRecurseMemo(n-2, mem)
	mem[n] = ans
	return mem[n]
}

func fibonacciMemoIter(n int) int {
	if n == 0 {
		return 0
	}
	mem := make([]int, n+1)
	mem[0] = 0
	mem[1] = 1
	for i := 2; i < len(mem); i++ {
		mem[i] = mem[i-1] + mem[i-2]
	}
	return mem[len(mem)-1]
}

func fibonacciIter(n int) int {
	if n == 0 {
		return 0
	}
	if n == 1 {
		return 1
	}
	fn := 1
	fn1 := 0
	for i := 2; i <= n; i++ {
		sum := fn + fn1
		fn1 = fn
		fn = sum
	}
	return fn
}
