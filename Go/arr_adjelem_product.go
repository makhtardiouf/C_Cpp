/**
Given an array of integers, find the pair of adjacent elements
that has the largest product and return it
Makhtar Diouf
*/
package main

import "fmt"
import "math"

func main() {
	var inp = []int{3, 6, -2, -5, 7, 3} // max = 21

	fmt.Println(adjacentElementsProduct(inp))

}

func adjacentElementsProduct(inputArray []int) int {
	var a, b int
	var max = math.MinInt64

	for i := 0; i < len(inputArray)-1; i++ {
		a = inputArray[i]
		b = inputArray[i+1]

		if (a * b) > max {
			max = a * b
		}
	}
	return max
}
