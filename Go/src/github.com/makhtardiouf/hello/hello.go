/**
Go package: howto
Run: go install github.com/makhtardiouf/hello  from $GOPATH
Makhtar Diouf
*/
package main

import (
	"fmt"
	"github.com/makhtardiouf/mutils"
)

func main() {
	fmt.Println(mutils.Reverse("!oG ,olleH"))
}
