/*
The definition of printBinary() is written in c++
the code in this file is written in c
we compile separately and link at the end...
*/

#define _GNU_SOURCE
#include "malib.h"
#include <errno.h>
#include <time.h>
#include <unistd.h>

static char id[] = "$Id: bit_wise.c 8 2007-04-30 22:25:20Z Makhtar $";

int main(void) {
  clock_t start, end;
  unsigned char a, b;
  start = clock();
  system("clear");
  fprintf(stdout, "\nProgram: %s\t%s\n\n", program_invocation_short_name, id);

  puts("Enter an integer(a) between 0 and 255: ");
  a = getchar();
  puts("\nEnter an integer(b) between 0 and 255: ");
  b = getchar();

  puts("\na | b : ");
  printBinary((a | b));
  putchar('\n');

  sleep(1);
  perror("\n ");
  end = clock();
  fprintf(stdout, "\nCPU time used: %.2lf\n",
          ((double)(end - start)) / CLOCKS_PER_SEC);

  return 0;
}
