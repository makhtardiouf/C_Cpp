/**
Go trivia:  display system info
Makhtar Diouf
*/
package main

import (
	"fmt"
	"log"
	"os"
	"runtime"
	// Profiler
	"runtime/pprof"
)

func main() {
	var profile, err = os.Create("cpu.profile")
	if err != nil {
		log.Fatal("Could not create file ", profile)
	}
	pprof.StartCPUProfile(profile)
	defer pprof.StopCPUProfile()

	log.Println("Runtime info of this system: ")

	fmt.Printf("OS: %s \nArch: %s\n", runtime.GOOS, runtime.GOARCH)
	println("Num CPUs: ", runtime.NumCPU())
	println("Go version: ", runtime.Version())

	var user = os.Getenv("USER")
	println("Goodbye", user)
}
