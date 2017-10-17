// Go trivia: io with cmd line or file
// Makhtar

package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
)

func main() {
	num := 0
	print("Enter a number: ")
	fmt.Scan(&num)
	fmt.Printf("You entered: %d, type: %T \n", num, num)

	in := bufio.NewScanner(os.Stdin)
	msg := "Enter anything or q to quit: "
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
		log.Fatal("Cannot access file ", err, "\n")
	}

	fp, err := os.Open(fname)
	if err != nil {
		log.Fatal("Error ", err)
		return
	}
	defer fp.Close()

	in = bufio.NewScanner(fp)
	log.Println("Listing content of ", fname)
	for i := 1; in.Scan(); i++ {
		println(i, ":", in.Text())
	}

	msg = "Diouf"
	fmt.Printf("By %s %X\n", msg, msg)
}
