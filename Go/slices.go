/**
 * Vectors
 */

package main
import ("fmt"; "sort"; "math/rand" )

func main() {
    
 v := []int{0, 5, -10, 15, -23};
 v = append(v, rand.Intn(100));
 	// We can add more than one element at a time.
 v = append(v, -2, 30, 4);
 sort.Ints(v);
 
 for i := 0; i < len(v); i++ {
  print(v[i], " ") ;  
 }
 println("\nSorted vector of length:", len(v), "\nIndexes: ");
 
 // range form of the for loop
 for i, el := range v {
     fmt.Printf("%d:\t%s\n", i, el)
 }
 println();
}
