/* $Id: char_code.c 9 2007-07-11 08:22:53Z Makhtar $

  Print the ASCII code of some characters */

#include "malib.h"
#include <ctype.h>


int main(int argc, char* argv[])
{
    char output[16];
    char ch;
    int i = 0;

    clearconsole();

    for (; i<3 ; ++i ) {
	rotate_dash();
        printf("\tEnter an alpha-numeric character: ");
        ch = getchar();

	if(!isalnum(ch))
	    continue;

	/* Discard the new line char */
        getchar();
	printf("\tAscii code of \'%c\' ", ch);
	fflush(stdout);
	sprintf(output, "is %d\n", ch);
	slowprint(output);
    }

    puts("\n");
    pausethis(1);
    return EXIT_SUCCESS;
}
