// +build OMIT
// MultiThreading in Go
// https://tour.golang.org/concurrency/1

package main

import (
	"fmt"
	"time"
)

func say(s string) {
	for i := 0; i < 5; i++ {
		time.Sleep(100 * time.Millisecond)
		fmt.Println(i, ":", s)
	}
}

func main() {
	go say("world")
	say("hello")
}
