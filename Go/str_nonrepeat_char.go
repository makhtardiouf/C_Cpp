/*
 * Given a string s, find and return the first instance
 * of a non-repeating character in it. If there is no such character, return '_'.
 * Makhtar - Golang version

 */
package main

import "fmt"
import "log"

var dbg = false

func main() {
	// inp := "abacabad"
	inp := "abcdefghijklmnopqrstuvwxyziflskecznslkjfabe"

	fmt.Printf("1st non-repeating char of %s: %s\n", inp, firstUniqChar(inp))
}

func firstUniqChar(s string) string {
	if len(s) <= 1 {
		return s
	}

	// Chars counter hashtable
	m := make(map[byte]int)
	// Store keys separately for final ordered iteration
	var keys []byte
	chs := []byte(s)

	for _, k := range chs {

		// this can be less efficient as it scans the map every time
		if _, in := m[k]; !in {
			keys = append(keys, k)
		}

		m[k]++

		if dbg {
			log.Printf("%s => %d", string(k), m[k])
		}
	}

	fmt.Printf("Hashtable %v, len: %d\nKeys: %v, len: %d\n", m, len(m), keys, len(keys))

	// Cannot use 'range m' as it would be un-ordered
	for _, k := range keys {
		if m[k] == 1 {
			return string(k)
		}
	}
	return "_"
}
