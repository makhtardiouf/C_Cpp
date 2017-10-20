/**
TMP: list/tree traversal draft
https://blog.golang.org/go-maps-in-action
*/
package main

import "fmt"

type Node struct {
	Next  *Node
	Value interface{}
}

var first *Node

func main() {

	visited := make(map[*Node]bool)
	for n := first; n != nil; n = n.Next {
		if visited[n] {
			fmt.Println("cycle detected")
			break
		}
		visited[n] = true
		fmt.Println(n.Value)
	}

}
