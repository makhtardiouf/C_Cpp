// Go hash tables, Maps

package main

import (
	"math/rand"
	//"strings"
)

type Vertex struct {
	Lat, Long float64
}

var m map[string]Vertex

func main() {
	m = make(map[string]Vertex)
	m["Bell Labs"] = Vertex{
		40.68433, -74.39967,
	}

	m["Dakar"] = Vertex{113.09, -45.900}

	for i := 0; i < 5; i++ {
		m["Loc" + string(i)] = Vertex{rand.Float64(), rand.Float64()}
		//j >>= 1
	}
	for i, el := range m {
		println(i, ":\t", el.Lat, el.Long)
	}

}
