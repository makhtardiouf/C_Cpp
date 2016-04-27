/*
$Id: cache.c 18 2008-07-06 09:18:48Z Makhtar $

Cache speed testing
Compile with -DCOPY=DUMBCOPY then SMARTCOPY
Test with: time ./cache
*/

#include <string.h>

#define DUMBCOPY                                                               \
  for (i = 0; i < 65536; i++)                                                  \
  dest[i] = src[i]
#define SMARTCOPY memcpy(dest, src, 65536)

int main(void) {
  char src[65536], dest[65536];
  int i, j;
  for (j = 0; j < 100; j++)
    COPY;

  return 0;
}
