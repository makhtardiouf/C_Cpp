
/* Experimenting with out of memory crash 
   $Id: eatmem.c 18 2008-07-06 09:18:48Z Makhtar $ */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int mem = 100;

  while(1)
    {
/* malloc(1<<20) */
      if(malloc(mem * 1024 * 1024) != NULL)
	{
	fprintf(stderr, "Allocated %dMB.\n", mem);
	mem += 10;
	} else {
	fprintf(stderr, "Memory exhausted!\n");
	return EXIT_FAILURE;
      }
    }
  return EXIT_SUCCESS;
}
