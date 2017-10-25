/*
 Parse and print IP addresses
 https://tour.golang.org/methods/18
 Makhtar Diouf
*/

package main

import "fmt"

type IPAddr [4]byte

func main() {
	hosts := map[string]IPAddr{
		"loopback":  {127, 0, 0, 1},
		"googleDNS": {8, 8, 8, 8},
	}
	for name, ip := range hosts {
		fmt.Printf("%v: %v\n", name, ip)
	}
}

// Stringer interface to print this specific type
func (ip IPAddr) String() string {
	var str, tmp string
	for i, v := range ip {
		if i < 3 {
			tmp = fmt.Sprintf("%d.", v)

		} else {
			tmp = fmt.Sprintf("%d", v)
		}
		str += tmp
	}
	return str
}
