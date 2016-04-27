
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char S[254];
  FILE *proc = popen("ls", "r");
  if (proc)
    /* 	while( (c = fgets(proc))) */
    /* 	    putchar(c); */
    while (puts(fgets(S, 254, proc)))
      ;
  else
    perror("popen");

  return EXIT_SUCCESS;
}
