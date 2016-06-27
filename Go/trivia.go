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

func pow(x, n, lim float64) float64 {
	// If with a short statement
	if v := math.Pow(x, n); v < lim {
		return v
	} else {
		fmt.Printf("%g >= %g\n", v, lim)
	}
	// can't use v here, though
	return lim
}

func salut() {
	t := time.Now()
	switch {
	case t.Hour() < 12:
		fmt.Println("Good morning!")
	case t.Hour() < 18:
		fmt.Println("Good afternoon.")
	default:
		fmt.Println("Good evening.")
	}
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

func main() {
	fmt.Println(
		pow(3, 2, 10),
		pow(3, 3, 20),
	)

	salut()
	checkOs()

}
