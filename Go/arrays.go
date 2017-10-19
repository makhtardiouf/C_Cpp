// Fixed sized arrays: [n]T is an array of n values of type T
// https://tour.golang.org/moretypes/6

package main

import "fmt"

func main() {
	var a [2]string

	a[0] = "Hello"
	a[1] = "World"
	fmt.Println(a[0], a[1])
	fmt.Println(a)

	primes := []int{2, 3, 5, 7, 11, 13}
	fmt.Println(len(primes), "items:", primes)
	fmt.Printf("Types %T %T\n", a, primes)
}
