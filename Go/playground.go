/**
Golang trivia
https://tour.golang.org/
*/
package main

import (
	"fmt"
	"runtime"
	"time"
)

// var statement declares a list of variables
var c, python, java bool

// include initializers
var j, k int = 1, 2

func main() {
	var i int
	fmt.Println("Default vars values:", i, j, k, c, python, java)

	// If initializers are presents, the types can be omitted
	var c, python, java = true, false, "no!"
	fmt.Println("Default vars values:", j, k, c, python, java)

	salut()
	checkOs()

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
	println(" It's", t.String())
}

func checkOs() {
	fmt.Print("We're running on ")

	switch os := runtime.GOOS; os {
	case "darwin":
		fmt.Println("OS X.")
	case "linux":
		fmt.Println("Linux.")
	default:
		// freebsd, openbsd,
		// plan9, windows...
		fmt.Printf("%s\n", os)
	}
}
