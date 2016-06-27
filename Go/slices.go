/**
* Vectors, Slices wrap arrays to give a more general
 interface to sequences of data.
 hold references to an underlying array, and if you assign
 one slice to another, both refer to the same array.
 Makhtar Diouf
*/

package main

import (
	"fmt"
	"math/rand"
	"sort"
)

func main() {
	// Create and init a slice
	v := []int{5, -10, 15, -23}
	v = append(v, rand.Intn(100))

	// can add more than one element at a time
	v = append(v, -2, 30, 9)

	// appending another slice
	y := []int{40, 12, 6}
	v = append(v, y...)

	sort.Ints(v)
	println("\nSorted vector of length:", len(v), "\nIndexes: ")

	// range form of the for loop
	for i, el := range v {
		fmt.Printf("%2d:\t%3d\n", i, el)
	}
	println()

	// With len and cap for the underlying array
	scores := make([]int, 6, 10)
	// Copy at most min len(src) or len(dst)
	copy(scores, v[0:9])
	fmt.Println("Copied slice content:", scores, "length:", len(scores), "capacity:", cap(scores))
	println()
}
