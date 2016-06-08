
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
   // char mess[]  = "Hello World";
   
   // Test if the rest of the array is initialized
   int a[8] = {0, 1, 2, 3};
   int i = 0;
   for(; i < 8; i++)
    printf("%d ", a[i]);
   
     return 0;    
}