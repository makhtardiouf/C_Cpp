/*$Id: cat.c 18 2008-07-06 09:18:48Z Makhtar $
_cat_ commande clone with a demo of setjmp/longjmp
*/
#include "malib.h"
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

/* Simulate c++' string keywork */
typedef char *String;

jmp_buf jbuf;

void filecopy(FILE *, FILE *);

int main(int argc, char *argv[]) {
  FILE *fp;
  String prog = argv[0];
  String name = "Elhadji M. Diouf";

  if (argc == 1)
    filecopy(stdin, stdout);
  else
    while (--argc > 0)
      if ((fp = fopen(*(++argv), "r")) == NULL) {
        fprintf(stderr, "%s: failed to open %s\n", prog, *argv);
        exit(-1);
      } else {

        if (setjmp(jbuf))
          fprintf(stderr, "Jumped back to main\n\n");
        else /* first time through */
          filecopy(fp, stdout);
      }
  if (ferror(stdout)) {
    fprintf(stderr, "%s: error; can not write to stdout\n", prog);
    exit(-1);
  }

  fprintf(stderr, "By ");
  typewrite(name);
  fprintf(stderr, "\n\n");
  fclose(fp);
  return 0;
}

void filecopy(FILE *ifp, FILE *ofp) {
  int c;
  /* Check that the input file stream is readable
  and the output file stream is writable */
  /*     if( fopen(ifp, "r") && fopen(ofp, "w") != NULL) */
  while ((c = getc(ifp)) != EOF)
    putc(c, ofp);

  longjmp(jbuf, 1);
  fprintf(stderr, "No way to get here\n");
}
