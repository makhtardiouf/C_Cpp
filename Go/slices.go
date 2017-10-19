/**
* Vectors, Slices wrap arrays to give a more general
 interface to sequences of data.
 hold references to an underlying array; if you assign
 one slice to another, both refer to the same array.

 Slices are like references to arrays
 Makhtar Diouf
*/

package main

import "fmt"
import "sort"
import "math/rand"

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
	println("\nVector of length", len(v), "is sorted? ", sort.IntsAreSorted(v), "\nIndexes: ")

	for i, el := range v {
		fmt.Printf("%2d:\t%3d\n", i, el)
	}
	println()

	// Take a chunk
	var w []int = v[2:7]
	fmt.Printf("Sliced %v\n", w)

	// With len and cap for the underlying array
	scores := make([]int, 6, 10)

	// Copy at most min len(src) or len(dst)
	copy(scores, v[0:9])
	fmt.Println("Copied slice content:", scores, "sz:", len(scores), "capacity:", cap(scores))
	println()

	updateSlice()
}

func updateSlice() {
	names := []string{
		"Makhtar",
		"Paul",
		"Tarikha",
		"Ringo",
	}
	fmt.Println(names)

	a := names[0:2]
	// can omit high or low bounds
	b := names[1:]
	fmt.Println(a, b)

	b[0] = "MakX"
	fmt.Println(a, b)
	fmt.Println(names)
}
