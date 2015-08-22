/*
$Id: genbuserror.c 18 2008-07-06 09:18:48Z Makhtar $

Generate a bus error? on SPARC only?
*/
#include <stdio.h>

    union {
	char a[10];
	int i;
    } u;

int main(void)
{
    int *p = (int*) &(u.a[1]);
    *p = 17;

    printf("p points at: %d\n", *p);
    return 0;
}
