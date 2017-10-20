/**
io demo: redirecting log output to file

*/
package main

import "os"
import "log"

func main() {
	fp, err := os.Create("logfile.log")

	if err == nil {
		log.SetOutput(fp)
	}
	log.Println("Logging it...")
}
