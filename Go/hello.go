// Executables must always use package main
package main

import "time"

// Semicolons are optional in Go ;
func main() {
	println("Hello, World!")
	println("It's", time.Now().String())
}
