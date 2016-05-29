// Go hash tables, associative arrays: Maps
// map() creates slices, maps, and channels only, and it returns an initialized 
// (not zeroed) value of type T (not *T)
// Makhtar Diouf

package main

import (
	"fmt"
	"math/rand"
	"sort"
)

func init() {
	idx int
	
}

type Vertex struct {
	// Index for sorting
	i int
	Lat, Long float64
}

type mvertex map[string]Vertex


func main() {
	m := make(mvertex)  //  new([]mvertex)
	
	m["Bell Labs"] = Vertex{
		i:0, Lat: 40.68433, Long:-74.39967,
	}

	m["Dakar"] = Vertex{1, 113.09, -45.900}
	m["test"] = Vertex{}
	
	var name string
	for i := 0; i < 5; i++ {
		name = fmt.Sprintf("Loc %v", i)
		m[name] = Vertex{i + m.Len(), rand.Float64(), rand.Float64()}
	}
	delete(m, "test")
	sort.Sort(m)
	
	// Details printing of a struct, json style
	fmt.Printf("%+v\n", m["Dakar"])

	for i, el := range m {
		println(i, ":\t", el.Lat, el.Long)
	}
	println("Length: ", m.Len())

	v, ok := m["Dakar"]
	fmt.Println("\nDakar:", v, "Present?", ok)
}

// Methods for sort.Interface

func (m mvertex) Len() int {
	// Could populate the indexes(i) here
	
	return len(m)
}

func (m mvertex) Less(i, j int) bool {
	return i < j
}

func (m mvertex) Swap(i, j int) {
	
}

// Make this type "printable" using the Stringer interface
func (m mvertex) String() string {
 	return fmt.Sprintf("%+v", string(m)) //m["Dakar"].Lat, m["Dakar"].Long)
}


