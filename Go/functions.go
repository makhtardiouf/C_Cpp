// Go functions trivia
// Data types come after variable names
// func params of the same type can omit the type from all but the last

package main

import "fmt"
import "math"
import "math/rand"

func main() {
	fmt.Println("Add", add(rand.Intn(10), rand.Intn(69)))

	s1, s2 := swap("Hello", "World")
	println(s1, s2)

	fmt.Println(sqrt(2), sqrt(-4))

}

func add(x, y int) int {
	return x + y
}

// Any number of args can be returned
func swap(a, b string) (string, string) {
	fmt.Printf("Swapping '%s %s' => ", a, b)
	return b, a
}

func sqrt(x float64) string {
	if x < 0 {
		return sqrt(-x) + "i"
	}
	return fmt.Sprint(math.Sqrt(x))
}

// func reverse(str string) string {
// 	b := str // []string(str)
// 	a := make([]string, len(str))

// 	for i, j := len(b)-1, 0; i >= 0; i, j = i-1, j+1 {
// 		a[j] = b[i]
// 	}
// 	println(a)
// 	return //a
// }
