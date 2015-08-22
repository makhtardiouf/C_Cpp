/* $Id: errors.c 5 2007-03-31 15:04:06Z Makhtar $
Experiment with error output facilities
*/
#define _GNU_SOURCE
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    FILE *myfile;

    system ("less RCS");
    printf ("\n %s\n\n", strerror (errno));
    myfile = fopen (argv[1], "r");

    if (argc > 3)
        errno = E2BIG;   // too many args

    if (errno != 0) {
        perror("ERROR ");
        printf("(errno value is %d)\n\n", errno);
    }
    else
        fclose (myfile);

    return EXIT_SUCCESS;
}
