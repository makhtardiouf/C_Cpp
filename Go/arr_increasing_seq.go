/**
Given a seq of integers as an array, determine whether it is possible to obtain
a strictly increasing seq by removing no more than one element from the array.


Makhtar Diouf
*/
package main

import "fmt"

func main() {
	var inp = []int{10, 1, 2, 3, 4, 5}

	fmt.Printf("%v can be increasing seq? %v\n", inp, almostIncreasingSequence(inp))
}

func almostIncreasingSequence(seq []int) bool {
	var hitCnt int

	for i := 0; i < len(seq)-1; i++ {
		if seq[i] >= seq[i+1] {
			hitCnt++

			// Remove the hit for the sequence
			seq = append(seq[:i], seq[i+1:]...)

			/*
				if i > 0 {
					hitCnt += cntHits(seq[i-1:])
				}*/
		}
	}
	fmt.Println("HitCnt: ", hitCnt)
	if hitCnt > 1 {
		return false
	}
	return true
}

func cntHits(seq []int) int {
	for i := 0; i < len(seq)-1; i++ {
		if seq[i] >= seq[i+1] {
			return 1
		}
	}
	return 0
}
