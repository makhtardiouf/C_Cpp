// https://tour.golang.org/moretypes/17

package main

import "fmt"

func main() {
	// Only looping construct in Golang is 'for'
	sum := 0
	for i := 0; i < 10; i++ {
		sum += i
	}
	fmt.Println("\n*** 1st sum", sum)

	// mimicing while; empty ';' are unneeded here
	for sum < 100 {
		sum += sum
	}
	fmt.Println("\n*** 2nd sum", sum)

	println("\n*** Powers range:")
	pow := make([]int, 10)
	for i := range pow {
		pow[i] = 1 << uint(i) // == 2**i
	}
	for _, val := range pow {
		fmt.Printf("%d\n", val)
	}

	// Infinite loop =
	// for {}

}
