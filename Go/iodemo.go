// Go trivia: read from the cmd line
package main

import (
	"bufio"
	//"fmt"
	"os"
)

func main() {
	msg := "Enter anything or q to quit: "
    
	in := bufio.NewScanner(os.Stdin)
    //_, err := fmt.Scanf("%s\n", &in)
    print(msg);
    // advances the Scanner to the next token
	for in.Scan() {
		line := in.Text()			
		println("Got: ", line)
        
		if line == "q" {
			return
		} 
        print(msg);
	}
}
