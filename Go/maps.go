// Go hash tables, Maps

package main

import (
	"math/rand"
	"fmt"
)

type Vertex struct {
	Lat, Long float64
}

type mv map[string]Vertex

func (m mv) Len() int {
	var l = 0
	for _, _ = range m {
		l++
	}
	return l
}

func main() {
	m := make(map[string]Vertex)
	m["Bell Labs"] = Vertex{
		40.68433, -74.39967,
	}

	m["Dakar"] = Vertex{113.09, -45.900}
	m["test"] = Vertex{}
	
	for i := 0; i < 5; i++ {
		m["Loc" + string(i)] = Vertex{rand.Float64(), rand.Float64()}
		//j >>= 1
	}
	delete(m, "test")	
	//sort.Sort(m)
	
	for i, el := range m {
		println(i, ":\t", el.Lat, el.Long)
	}
	println("Length: ", m.Len())
	
	v, ok := m["Dakar"]
	fmt.Println("Dakar:", v, "Present?", ok)
	
}
