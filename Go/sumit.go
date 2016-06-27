/**
Go basics
https://tour.golang.org/flowcontrol/1
*/

package main

import "fmt"

func main() {
	sum := 0
	for i := 0; i < 10; i++ {
		sum += i
		println(i, sum)
	}
	fmt.Println("Sum:", sum)

	// Equivalence of 'while'
	sum = 1
	for sum < 1e6 {
		sum++
	}
	fmt.Println("Sum2:", sum)

}
