// Error handling in Go

package main

import (
	"fmt"
	"math"
)

type ErrNegativeSqrt float64

func (e ErrNegativeSqrt) Error() string {
	return fmt.Sprintf("Error: given value is negative %v", float64(e))
}

func Sqrt(x float64) (float64, error) {
	if x < 0 {
		return 0.0, ErrNegativeSqrt(x)
	}
	return math.Sqrt(x * x), nil
}

func main() {
	fmt.Println(Sqrt(2))
	fmt.Println(Sqrt(-2))
}
