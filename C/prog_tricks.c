/* $Id: prog_tricks.c 18 2008-07-06 09:18:48Z Makhtar $
Program for testing various tricks stated in The practice of programming book
 */
#include <stdio.h>

int main(void) {
  /* Order of evaluation */
  int n = 1;
  printf("%d %d", n++, n++);

  return 0;
}
