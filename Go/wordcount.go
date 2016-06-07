// https://tour.golang.org/moretypes/23

package main

import (
	"golang.org/x/tour/wc"
	"strings"
)

func WordCount(s string) map[string]int {
	v := strings.Split(s, " ")
	m := make(map[string]int, len(v))

	for _, el := range v {
		m[el] += 1
	}

	return m
}

func main() {
	wc.Test(WordCount)
}
