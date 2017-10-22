/**
Classic palindrome strings checking: when reversed give the same string
Makhtar
*/
package main

import "fmt"

func main() {
	var inp = []string{"aabaa", "abac", "a"}

	for _, s := range inp {
		fmt.Printf("'%s' is a palindrome? %v\n", s, checkPalindrome(s))
	}
}

func checkPalindrome(inputString string) bool {
	var str = []byte(inputString)
	if len(str) <= 1 {
		return true
	}

	for i, j := 0, len(str)-1; i <= j; i, j = i+1, j-1 {
		if str[i] != str[j] {
			return false
		}
	}
	return true
}
