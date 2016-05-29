/**
* Vectors
* Slices wrap arrays to give a more general, powerful,
 and convenient interface to sequences of data.
 hold references to an underlying array, and if you assign
 one slice to another, both refer to the same array.
*/

package main

import (
	"fmt"
	"math/rand"
	"sort"
)

func main() {

	v := []int{0, 5, -10, 15, -23}
	v = append(v, rand.Intn(100))
	// can add more than one element at a time
	v = append(v, -2, 30, 4)

	// appending another slice
	y := []int{40, 12, 6}
	v = append(v, y...)

	sort.Ints(v)
	for i := 0; i < len(v); i++ {
		print(v[i], " ")
	}
	println("\nSorted vector of length:", len(v), "\nIndexes: ")

	// range form of the for loop
	for i, el := range v {
		fmt.Printf("%2d:\t%3d\n", i, el)
	}
	println()
}
