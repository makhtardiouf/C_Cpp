#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int i;
  int j = 5;
  void *heapitem = malloc(4);
  double bigarr[2000];
  bigarr[0] = 15.34;

  fprintf(stderr, "The stack top is near: %p\n", &i);
  fprintf(stderr, "The data segment is near: %p\n", &j);
  fprintf(stderr, "The heap within the data seg is near: %p\n", heapitem);

  free(heapitem);
  return 0;
}
