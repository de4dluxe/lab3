package main

import (
	"fmt"
	"math"
)

func main() {
	var x, y float64
	var xn, xk, dx float64

	fmt.Print("Введите Xнач: ")
	fmt.Scan(&xn)

	fmt.Print("Введите Xкон: ")
	fmt.Scan(&xk)

	fmt.Print("Введите шаг dx: ")
	fmt.Scan(&dx)

	fmt.Println("\n----------------------")
	fmt.Println("|    X    |    Y    |")
	fmt.Println("----------------------")

	for x = xn; x <= xk; x += dx {
		if x <= -3 {
			y = -x - 6
		} else if x <= 0 {
			y = -3 + math.Sqrt(9-4*(x+1.5)*(x+1.5))
		} else if x <= 3 {
			y = 2*x*x*x/9 - 3
		} else {
			y = -1.5*x + 7.5
		}

		fmt.Printf("|%8.2f|%8.2f |\n", x, y)
	}

	fmt.Println("----------------------")
}