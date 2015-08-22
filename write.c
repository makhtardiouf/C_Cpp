/*
$Id: write.c 10 2007-12-06 13:45:15Z Makhtar $

*/

#include <unistd.h>		/* should come 1st */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
  const char* str1 = "Hello Linux world, I'm on my way back\n";
  unsigned int total_chars = strlen(str1);
  unsigned int temp_total = 0;
  int retval = 0;
  const char* str2 = "An error occured...\n";

  while(temp_total < total_chars)
    {
      retval = write(1, str1, total_chars);
      if(retval != -1)
	temp_total += retval;
      else
	write(2, str2, sizeof(str2));
    }
  return EXIT_SUCCESS;
}
