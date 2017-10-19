/**
Golang trivia
https://tour.golang.org/
*/
package main

import (
	"fmt"
	"math"
	"runtime"
	"time"
)

// var statement declares a list of variables
var c, python, java bool

// initializers
var j, k int = 1, 2

func main() {
	salut()

	// run this after the surrounding block
	defer checkOs()

	var i int
	fmt.Println("Default vars values:", i, j, k, c, python, java)

	// If initializers are presents, the types can be omitted
	var c, python, java = true, false, "no!"
	fmt.Println("Default vars values:", j, k, c, python, java)

	// type casting
	f := math.Sqrt(5 + 7)
	println("Casting", f, "to int =", uint(f))

	const world = "世界"
	fmt.Printf("Hello %s (%T)\n", world, world)

}

func salut() {
	// Inside a function, the := short assignment statement can be used
	t := time.Now()

	switch {
	case t.Hour() < 12:
		print("Good morning!")
	case t.Hour() < 18:
		print("Good afternoon.")
	default:
		print("Good evening.")
	}

	fmt.Printf(" It's the %dth\n", t.Day())
}

func checkOs() {
	fmt.Print("This program ran on ")

	// case body breaks automatically, unless it ends with a fallthrough statement

	switch os := runtime.GOOS; os {
	case "darwin":
		fmt.Println("OS X.")
	case "linux":
		fmt.Println("Linux.")
		fallthrough

	default:
		// freebsd, openbsd,
		// plan9, windows...
		fmt.Printf("%s\n", os)
	}
}
