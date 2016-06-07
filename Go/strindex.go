package main

import ()

func strindex(s string, t string) int {
	var i, j, k int
	var end byte
	println("Checking string", t, "in", s, end)

	for i = 0; i < len(s); i++ {
		j = i
		k = 0
		for j < len(s) && (s[j] != t[k]) {
			println(i, j, s[i])
			j++
			// continue;
		}
		k++

		if s[j-1] == t[k-1] {
			return i
		}
	}

	return -1
}

func main() {
	println(strindex("Hello", "o"))

}
