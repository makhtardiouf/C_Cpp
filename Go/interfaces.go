/**
 Go Polymorphism
	https://tour.golang.org/methods/10

	A type implements an interface by implementing its methods.
	There is no explicit declaration of intent, no "implements" keyword.
*/
package main

import "fmt"

type I interface {
	M()
}

type T struct {
	S string
}

func main() {
	var i I = T{"hello"}
	i.M()

	var j = T{"hey"}
	j.M()

	// empty interface may hold values of any type.
	var k interface{} = "Wassup"
	println(k)

	l, ok := k.(string)
	println(l, ok)

	// Type checking
	do(21)
	do("hello")
	do(true)
}

//M... This method means type T implements the interface I,
//M... but we don't need to explicitly declare that it does so.
func (t T) M() {
	fmt.Println(t.S, "this is a test")
}

func do(i interface{}) {
	switch v := i.(type) {
	case int:
		fmt.Printf("Twice %v is %v\n", v, v*2)
	case string:
		fmt.Printf("%q is %v bytes long\n", v, len(v))
	default:
		fmt.Printf("I don't know about type '%T'!\n", v)
	}
}
