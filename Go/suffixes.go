/**
Suffixarrays
Makhtar Diouf
*/
package main

import (

	"fmt"
	"index/suffixarray"
)

func main() {

	content := []byte("Suffixarray implements substring search in logarithmic time using an in-memory suffix array")
	idx := suffixarray.New(content)
	target := "ar"

	println(string(content))
	fmt.Printf("Occurences of substring '%s' @ %v\n", target, idx.Lookup([]byte(target), -1))
}
