/*
$Id: grep.c 5 2007-03-31 15:04:06Z Makhtar $
Show lines of a file on wich a string pattern appears.
*/

#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <errno.h>
#include "emdutils.h"

int number = 0;
int printhits(int , char* );

int main(int argc, char* argv[])
{
    char* lineptr;
    const int BUFF = 200; /* max char per line */
    FILE* fp;
    int lineno = 0;
    int c, except = 0, found = 0;
    char* source = argv[ argc - 1 ] ;
    char* target = argv[ argc - 2 ] ;

    if (argc < 3) {
        printf("\nUsage: %s [-x -n] PATTERN FILENAME\n\n", argv[0]);
        return 1;
    }

    fp = fopen(source, "r");
    if (fp == NULL) {
        perror("\nFile reading error");
        return 1;
    }

    while (--argc > 0 && (*++argv)[0] == '-')
        while (c = *(++argv[0]))
            switch (c) {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf("\nInvalid option %c\n", c);
                break;
            }

    /* initzis(); */
    while (fgets(lineptr, BUFF, fp) != NULL) {
        lineno++;
        if (except) {
            if (strstr(lineptr, target) == NULL)
                found = printhits(lineno, lineptr);
        } else if (strstr(lineptr, target) != NULL)
            found = printhits(lineno, lineptr);
    }
    fclose(fp);

    printf("\nFound %d matches...\n", found);

    return 0;
}


int printhits(int lineno, char* lineptr)
{
    static int found = 0;
    if (number)
        printf("%3d: %s", lineno, lineptr);
    else
        printf("%s", lineptr);

    /*    _flushlbf();
        pausethis(1);
    */
    found++;

    return found;
}
