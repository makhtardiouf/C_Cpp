/**
minimal number of statues that need to be added to existing statues such that it contains every integer
size from an interval [L, R] (for some L, R).

Arrange from smallest to largest so that each statue will be bigger
than the previous one exactly by 1
Makhtar Diouf
*/
package main

import "fmt"
import "sort"

func main() {
	var inp = []int{6, 2, 3, 8} // addCnt = 3, as it needs sizes 4, 5 and 7.
	//inp = []int{6, 3}
	fmt.Println(makeArrayConsecutive2(inp))
}

func makeArrayConsecutive2(statues []int) int {
	var addCnt, tmp int
	sort.Ints(statues)

	for i := 0; i < len(statues)-1; i++ {
		tmp = statues[i+1] - statues[i]
		if tmp != 1 {
			for j := 0; j < tmp-1; j++ {
				addCnt++
			}
		}
	}
	return addCnt
}
