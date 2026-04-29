package main

import "fmt"

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func bestMove(arr []int, pos, n, m, lastTake int) int {
	limit := min(m, n-pos)

	bestSum := -2000000000
	bestK := 1
	curSum := 0

	for k := 1; k <= limit; k++ {
		curSum += arr[pos+k-1]

		if k == lastTake {
			continue
		}

		if curSum > bestSum || (curSum == bestSum && k < bestK) {
			bestSum = curSum
			bestK = k
		}
	}

	return bestK
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}

	pavel := 0
	vika := 0

	lastPavel := 0
	lastVika := 0

	pos := 0
	turn := 0

	for pos < n {
		var take int

		if turn == 0 {
			take = bestMove(arr, pos, n, m, lastPavel)
		} else {
			take = bestMove(arr, pos, n, m, lastVika)
		}

		sum := 0
		for i := 0; i < take; i++ {
			sum += arr[pos+i]
		}

		if turn == 0 {
			pavel += sum
			lastPavel = take
		} else {
			vika += sum
			lastVika = take
		}

		pos += take
		turn = 1 - turn
	}

	if pavel > vika {
		fmt.Print(1)
	} else {
		fmt.Print(0)
	}
}