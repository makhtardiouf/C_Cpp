/*
 * Given a string s, find and return the first instance
 * of a non-repeating character in it. If there is no such character, return '_'.
 * Makhtar - Golang version

 */
package main

import "fmt"
import "log"

var dbg = true

func main() {
	var inp = "abacabad"
	inp = "abcdefghijklmnopqrstuvwxyziflskecznslkjfabe"

	fmt.Printf("1st non-repeating char of %s: %s\n", inp, firstUniqChar(inp))
}

func firstUniqChar(s string) string {
	if len(s) <= 1 {
		return s
	}

	// Chars counter hashtable
	m := make(map[byte]int)
	chs := []byte(s)

	for i := 0; i < len(chs); i++ {
		m[chs[i]]++

		if dbg {
			log.Printf("%s => %d", string(chs[i]), m[chs[i]])
		}
	}

	fmt.Printf("%v\n", m)

	// Cannot use 'range m' as it would be un-ordered
	// but this can be less efficient for large input of s
	for i := 0; i < len(chs); i++ {
		if m[chs[i]] == 1 {
			return string(chs[i])
		}
	}
	return "_"
}
