// Go trivia: Mimic Unix cat command
// Makhtar Diouf

package main

import (
	"bufio"
	"log"
	"os"
)

func main() {
	var in = bufio.NewScanner(os.Stdin)
	var fp *os.File
	var err error
	var fname string

	if len(os.Args) < 2 {
		print("Enter a filename to read: ")		
		in.Scan()
		fname = in.Text()
		fp, err = os.Open(fname)
	} else {
        // If interpreted with "go run", arg1 should not be a go file
		fname := os.Args[1]
		fp, err = os.Open(fname)
	}

	if err != nil {
		log.Fatal("Error ", err)
	}
	in = bufio.NewScanner(fp)
    defer fp.Close()

	log.Println("Listing content of ", fname)
	for i := 1; in.Scan(); i++ {
		println(i, ":", in.Text())
	}
}
