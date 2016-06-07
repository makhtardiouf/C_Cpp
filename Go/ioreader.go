// +build OMIT

package main

import (
	"fmt"
	"io"
	"strings"
	// Test unused import
	_ "bufio"
)

func main() {
	r := strings.NewReader("Let's do io reading")

	b := make([]byte, 8)
	// == while
	for {
		n, err := r.Read(b)
		fmt.Printf("read %v bytes, b[:n] = %q\n", n, string(b[:n]))

		if err == io.EOF {
			break
		}
	}
}
