/*
$Id: grep.c 5 2007-03-31 15:04:06Z Makhtar $
Unix 'grep' command clone:
shows lines of a file on which a string pattern appears.
*/
#define _GNU_SOURCE
#include "malib.h"
#include <errno.h>
#include <stdio.h>
#include <stdio_ext.h> /* _flushlbf */
#include <string.h>
#include <ctype.h>

int number = 0;
int printhits(int, char *);

int main(int argc, char *argv[])
{
    size_t len = 0;
    FILE *fp;
    int lineno = 0, c, except = 0, found = 0;
    char* lineptr; char* source; char* target;
    if (argc < 3) {
        printf("\nUsage: %s [-x -n] PATTERN FILENAME\n\n", argv[0]);
        return -1;
    }
    
    source = argv[argc - 1];
    target = argv[argc - 2];
    fp = fopen(source, "r");
    if (fp == NULL) {
        perror("\nCannot read file");
        return -1;
    }

    while (--argc > 0 && (*++argv)[0] == '-')
        while ( (c = *(++argv[0])) )
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
      
    fprintf(stderr, "Searching for: %s\n", target);

    while (getline(&lineptr, &len, fp) != -1) {
        lineno++;
        if (except) {
          /* Ignore cases */
            if (strcasestr(lineptr, target) == NULL)
                found = printhits(lineno, lineptr);
                
        } else if (strcasestr(lineptr, target) != NULL)
            found = printhits(lineno, lineptr);
    }
    free(lineptr);
    fclose(fp);
    printf("\nFound %d matches...\n", found);
    return 0;
}

int printhits(int lineno, char *lineptr)
{
    static int found = 0;
    if (number)
        printf("%3d: %s", lineno, lineptr);
    else
        printf("%s", lineptr);

    found++;
    return found;
}
