/**

Makhtar Diouf
*/
package main

import "fmt"

func main() {
	fmt.Println(centuryFromYear(1901))
	fmt.Println(centuryFromYear(1700))
}

func centuryFromYear(year int) int {
	var cent = year / 100
	var rem = year % 100

	if rem > 0 {
		cent++
	}
	return cent
}
