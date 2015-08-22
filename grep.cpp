/*
$Id: grep.cpp 5 2007-03-31 15:04:06Z Makhtar $
Show lines of a file on wich a string pattern appears.
*/
#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <errno.h>
#include "emdutils.h"

using namespace std;

int number=0;
#ifdef __cplusplus
extern "C"
{
#endif

    int printhits( int , char* );

#ifdef __cplusplus
}
#endif


int main(int argc, char* argv[] )
{
    char* lineptr = new char[256] ;
    int lineno = 0;
    int c, except = 0, found = 0;
    char* target = argv[ argc - 2 ] ;
    ifstream file(argv[argc - 1], ios::in);

    if (  argc < 3 ) {
        printf( "\nUsage: %s [-x -n] PATTERN "
                "FILENAME\n\n", argv[0] );
        return 1;
    }

    while ( --argc > 0 && (*++argv)[0] == '-' )
        for ( ; (c = *(++argv[0]) ); )
            switch (c) {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf( "\nInvalid option %c\n", c );
                break;
            }

    // read input
    bool over = false;
    do {
        lineno++;
        file.getline(lineptr, 256);
        if (*lineptr != '\n' && lineptr != NULL) {
            if (except) {
                if ( strstr(lineptr, target) == NULL )
                    found = printhits( lineno, lineptr );
            } else if (strstr(lineptr, target) != NULL)
                found = printhits(lineno, lineptr);
        }

        if (file.eof()) {
            over = true;
        }

    } while (!over);

    file.close();
    printf("\nFound %d matches...\n", found);
    return 0;
}


int printhits( int lineno, char* lineptr )
{
    static int found = 0;
    if (number)
        printf("%3d: %s\n", lineno, lineptr);
    else
        printf("%s\n" , lineptr);

    found++;
    return found;
}
