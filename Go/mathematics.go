// Go math package trivia
// Makhtar Diouf

package main

import "fmt"
import "math"
import "math/cmplx"

func main() {
	fmt.Println("PI", math.Pi)

	fmt.Println(
		"Powers:",
		pow(3, 2, 10),
		pow(3, 3, 20),
	)

	fmt.Printf("Now you have %g ideas\n", math.Sqrt(7))

	fmt.Printf("Type: %T val: %v\n", toBe, toBe)
	fmt.Printf("Type: %T val: %v\n", maxInt, maxInt)

	z := cmplx.Sqrt(-5 + 12i)
	fmt.Printf("Type: %T val: %v\n", z, z)

	fmt.Println(Sqrt(2))
}

var (
	toBe   bool   = false
	maxInt uint64 = 1<<64 - 1
)

func pow(x, n, lim float64) float64 {
	// If statement can start with a short statement to execute before the condition
	if v := math.Pow(x, n); v < lim {
		return v
	} else {
		// v is accessible in the else

		fmt.Printf("Hit limit: %g >= %g\n", v, lim)
	}
	// can't use v here, though
	return lim
}

func Sqrt(x float64) float64 {
	z := 1.0
	var res float64
	for z > 0 {
		res = z - ((z * z) - x/(2*z))
		println(z, res)
		z = res
	}
	return res
}
