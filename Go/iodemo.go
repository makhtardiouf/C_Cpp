// Go trivia: io with cmd line or file
// Makhtar Diouf

package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
)

func main() {
	msg := "Enter anything or q to quit: "

	in := bufio.NewScanner(os.Stdin)
	//_, err := fmt.Scanf("%s\n", &in)
	print(msg)

	// While advancing the Scanner to the next token
	for in.Scan() {
		line := in.Text()
		println("Got: ", line)

		if line == "q" {
			break
		}
		print(msg)
	}

	// Display a file's' content
	print("Enter a filename to read: ")
	in.Scan()
	fname := in.Text()
	if _, err := os.Stat(fname); err != nil {
		log.Fatal("Cannot access file ", fname, err, "\n")
		
	} else {

		fp, err := os.Open(fname)
		if err != nil {
			log.Fatal("Error ", err)
			return
		}
		in = bufio.NewScanner(fp)
		log.Println("Listing content of ", fname)
		for i := 1; in.Scan(); i++ {
			println(i, ":", in.Text())
		}
		fp.Close()
	}

	msg = "Diouf"
	fmt.Printf("By %s %X\n", msg, msg)
}
