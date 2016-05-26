// https://tour.golang.org/moretypes/18

package main

import "golang.org/x/tour/pic"

func Pic(dx, dy int) [][]uint8 {
	x := make([]uint8, dx)
	y := make([][]uint8, dy)
	for i:=0; i < dy; i++ {
		y[i] = x
	}
	return y
}

func main() {
	pic.Show(Pic)
}
