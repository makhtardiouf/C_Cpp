/*
$Id: binary.c 8 2007-04-30 22:25:20Z Makhtar $
*/

#include "malib.h"

int main(int argc, char* argv[])
{
    int i = 10;
    int n = i++%5;
    printf("\ni equals %d, n equals %d\n", i, n);

    i = 10;
    n = ++i%5;
    printf("\ni equals %d, n equals %d\n", i, n);

    printBinary(17);
    printf("\n\n");
    return EXIT_SUCCESS;
}
