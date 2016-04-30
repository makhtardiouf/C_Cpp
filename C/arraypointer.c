/*
$Id$
Arrays and pointers interchangeability is not always true!
Let us demonstrate it

P214 Deep C secrets
*/
#include <stdio.h>
#include <stdlib.h>

void fun(char target[]) {

  fprintf(stderr, "The elements of the array arg (@ %x): %c(@ %x) , %c(@ %x)\n",
          &target, target[0], &(target[0]), target[1], &(target[1]));

  fprintf(stderr, "The size of the array = %ld - INSIDE fun() !!!\n",
          sizeof(target));
}

void fun2(char *target) {

  fprintf(stderr,
          "The elements of the pointer arg (@ %X): %c(@ %X) , %c(@ %X)\n",
          &target, target[0], &(target[0]), target[1], &(target[1]));

  fprintf(stderr, "The size of the pointer arg = %ld - INSIDE fun2() !!!\n",
          sizeof(target));
}

int main(void) {
  char arr[] = {'a', 'b'};

  fprintf(stderr, "The size of the array = %ld - INSIDE main() \n"
                  "elements are located at: %X and %X\n",
          sizeof(arr), &arr[0], &arr[1]);

  fun(arr);
  fun2(arr);
  exit(0);
}
