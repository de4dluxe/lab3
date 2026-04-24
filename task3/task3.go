package main

import (
	"fmt"
	"math/big"
)

func main() {
	var a, b int
	fmt.Scan(&a, &b)

	if b == 1 {
		fmt.Println("infinity")
		return
	}

	// Stirling numbers S(n,k)
	S := make([][]int64, a+1)
	for i := range S {
		S[i] = make([]int64, a+1)
	}
	S[0][0] = 1

	for n := 1; n <= a; n++ {
		for k := 1; k <= n; k++ {
			S[n][k] = S[n-1][k-1] + int64(k)*S[n-1][k]
		}
	}

	// factorial
	fact := make([]int64, a+1)
	fact[0] = 1
	for i := 1; i <= a; i++ {
		fact[i] = fact[i-1] * int64(i)
	}

	bBig := big.NewInt(int64(b))
	bm1 := big.NewInt(int64(b - 1))

	num := big.NewInt(0)
	den := big.NewInt(1)

	// denominator = (b-1)^(a+1)
	den.Exp(bm1, big.NewInt(int64(a+1)), nil)

	for k := 1; k <= a; k++ {
		if S[a][k] == 0 {
			continue
		}

		term := big.NewInt(S[a][k])
		term.Mul(term, big.NewInt(fact[k]))
		term.Mul(term, bBig)

		// (b-1)^(a-k)
		pow := big.NewInt(1)
		pow.Exp(bm1, big.NewInt(int64(a-k)), nil)

		term.Mul(term, pow)
		num.Add(num, term)
	}

	// simplify fraction
	gcd := new(big.Int).GCD(nil, nil, num, den)
	num.Div(num, gcd)
	den.Div(den, gcd)

	fmt.Printf("%s/%s\n", num.String(), den.String())
}