// +build OMIT
// methods with pointer receivers take either a value or 
// a pointer as the receiver when they are called.
// In general, all methods on a given type should have either 
// value or pointer receivers, but not a mixture of both.
package main

import (
	"fmt"
	"math"
)

type Vertex struct {
	X, Y float64
}


func main() {
	v := Vertex{3, 4}
	v.Scale(5) 
	fmt.Println("%v" , v)
	
	p := &v
	p.Scale(2)
	fmt.Println("%v" , v)
	
	fmt.Println(Abs(v))
}


func Abs(v Vertex) float64 {
	return math.Sqrt(v.X*v.X + v.Y*v.Y)
}


func (v *Vertex) Scale(f float64) {
	v.X = v.X * f
	v.Y = v.Y * f
}
