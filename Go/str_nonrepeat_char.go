/*
 * Given a string s, find and return the first instance
 * of a non-repeating character in it. If there is no such character, return '_'.
 * Makhtar - Golang version

 */
package main

import "fmt"

func main() {
	var inp = "abacabad"
	fmt.Printf("1st non-repeating char of %s: %s\n", inp, firstUniqChar(inp))
}

func firstUniqChar(s string) string {
	if len(s) <= 1 {
		return s
	}

	// Chars counter hashtable
	m := make(map[byte]int)
	str := []byte(s)

	for i := 0; i < len(str); i++ {
		m[str[i]] += 1
	}

	fmt.Printf("%v\n", m)
	// Cannot use 'range m' as it would be un-ordered
	for i := 0; i < len(str); i++ {
		if m[str[i]] == 1 {
			return string(str[i])
		}
	}
	return "_"
}
