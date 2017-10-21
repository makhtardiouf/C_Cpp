// +build OMIT
// Channels are a typed conduit through which you can
// send and receive values with the channel operator, <-.
// Feels like a Pipe

package main

import "fmt"

func main() {
	s := []int{7, 2, 8, -9, 4, 0}

	c := make(chan int)
	go sum(s[:len(s)/2], c)
	go sum(s[len(s)/2:], c)

	x, y := <-c, <-c // receive from c
	fmt.Println("Sum of:", x, y, " = ", x+y)

}

func sum(s []int, c chan int) {
	tot := 0
	fmt.Printf("Running with %T %v\n", c, c)
	for _, v := range s {
		tot += v
	}
	c <- tot // send sum to c
}
