// Go hash tables, Maps
// Makhtar Diouf

package main

import (
	"fmt"
	"math/rand"
	"sort"
)

type Vertex struct {
	// Index for sorting
	i int
	Lat, Long float64
}

type mvertex map[string]Vertex


func main() {
	m := make(mvertex)
	
	m["Bell Labs"] = Vertex{
		0, 40.68433, -74.39967,
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
	// m.Sort()

	for i, el := range m {
		println(i, ":\t", el.Lat, el.Long)
	}
	println("Length: ", m.Len())

	v, ok := m["Dakar"]
	fmt.Println("\nDakar:", v, "Present?", ok)

}

// Make this type "printable" using the Stringer interface
func (m mvertex) String() string {
 return ""//	return fmt.Sprintf("%v %v", m.Lat, m.Long)
}

// sort.Interface 
type mv interface {
	Len() int
	Less(i, j int) bool
	Swap(i, j int)
}

// A method for the type above
func (m mvertex) Len() int {
	return len(m)
}

// For sort.Interface ...Less method
//type mvertex interface {
func (m mvertex) Less(i, j int) bool {
	return i < j
}

func (m mvertex) Swap(i, j int) {
	
}
