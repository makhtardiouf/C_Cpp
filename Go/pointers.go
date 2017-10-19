// https://tour.golang.org/moretypes/1
// Go Pointers

package main

import "fmt"

func main() {
	i, j := 42, 2701

	p := &i                                       // point to i
	fmt.Printf("Pointer address %x: %d\n", p, *p) // read i through the pointer

	*p = 21        // set i through the pointer
	fmt.Println(i) // see the new value of i

	p = &j         // point to j
	*p = *p / 37   // divide j through the pointer
	fmt.Println(j) // see the new value of j
}
