/**
 The language permits to access a struct pointer values 
 with just p.X, without the explicit dereference (*p).X
https://tour.golang.org/moretypes/4
*/
package main

import "fmt"

type Vertex struct {
	X int
	Y int
}

func main() {
	v := Vertex{1, 2}
	p := &v
	p.X = 1e3
    fmt.Println(v)
    
    // Functions don't have to be declared before main()
    manip(&v)
	fmt.Println(v)    
}

func manip(v *Vertex) {
    v.X /= 2
    v.Y++
}
