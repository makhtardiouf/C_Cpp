/**
Go Structures:
The language permits to access a struct pointer values
with just p.X, without the explicit dereference (*p).X
https://tour.golang.org/moretypes/4 & 9
*/
package main

import "fmt"

type Vertex struct {
	X int
	Y int
}

func main() {
	initStruct()

	v := Vertex{1, 2}
	p := &v
	p.X = 1e3
	fmt.Println(v)

	// Functions don't have to be declared before main()
	manip(&v)

	// Annotated printing of struct fields
	fmt.Printf("%v\n", v)
	fmt.Printf("%+v\n", v)
	fmt.Printf("%#v\n", v)

	var (
		v1 = Vertex{1, 2}  // has type Vertex
		v2 = Vertex{X: 56} // Y:0 is implicit
		v3 = Vertex{}      // X:0 and Y:0
		p2 = &Vertex{2, 5} // has type *Vertex
	)

	fmt.Println(v1, p2, v2, v3)
}

func initStruct() {
	s := []struct {
		i int
		b bool
	}{
		{2, true},
		{3, false},
		{5, true},
		{7, true},
		{11, false},
		{13, true},
	}

	for _, v := range s {
		fmt.Printf("s[%d] => %v\n", v.i, v.b)
	}

	fmt.Println(s, "\n\n")
}

func manip(v *Vertex) {
	v.X /= 2
	v.Y++
}
