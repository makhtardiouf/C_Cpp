// Go 2D vectors
// slices: dynamically-sized, flexible view into the elements of an array
// Makhtar Diouf

package main

import "fmt"
import "math/rand"

func main() {
	// row, cols sizes
	xSz := 5
	ySz := 10

	// Allocate the top-level slice.
	v := make([][]int, ySz)

	// allocate the slice for each row.
	for i := range v {
		v[i] = make([]int, xSz)

		// Set random values
		var el *int
		fmt.Printf("%2d:", i)
		for j := range v[i] {
			el = &v[i][j]
			*el = rand.Intn(200)
			fmt.Printf("%4d ", *el)
		}
		println()
	}

}
