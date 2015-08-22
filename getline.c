/*
$Id: getline.c 5 2007-03-31 15:04:06Z Makhtar $
Get line into aString, return length.
*/
#include <stdio.h>

int getline(char aString[], int LineLength)
{
    int c, i;

    i = 0;
    while ( --LineLength > 0 && (c==getchar()) != EOF && c!='\n')
        aString[i++] = c;

    if ( c == '\n' )
        aString[i++] = c;
    aString[i] = '\0';

    return i;
}
