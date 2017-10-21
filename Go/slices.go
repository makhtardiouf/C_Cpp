/**
* Vectors, Slices wrap arrays to give a more general
 interface to sequences of data.
 Hold references to an underlying array; if you assign
 one slice to another, both refer to the same array.

 A slice has both a length and a capacity.
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

	// add more than one element at a time
	v = append(v, -2, 30, 9)

	// append another slice
	y := []int{40, 12, 6}
	v = append(v, y...)

	sort.Ints(v)
	fmt.Printf("\nVector of length %d, is sorted? %v", len(v), sort.IntsAreSorted(v))

	println("\nIndexes:")
	for i, el := range v {
		fmt.Printf("%2d:\t%3d\n", i, el)
	}

	// Take a chunk
	var w = v[2:7]
	fmt.Printf("\nSliced v[2:7] %v len: %d\n", w, len(w))

	// With len and cap for the underlying array
	scores := make([]int, 6, 10)

	// Copy at most min len(src) or len(dst)
	copy(scores, v[0:9])

	// Extend length
	scores = scores[:8]

	fmt.Printf("Copied slice content: %v, len:%d, cap:%d\n", scores, len(scores), cap(scores))

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
