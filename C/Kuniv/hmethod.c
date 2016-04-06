/* Makhtar Diouf 2004 Hornerの方法 
 *   $Id$
 */
#include <stdio.h>

int fn(int x, int a[], int n)
{
    int buf;
    int i;
    buf = a[n];
    for(i = n-1; i >= 0; i--)
        buf = buf*x+a[i];
    
    return buf;
}

int main(void)
{
    int a[] = {1,2,3,4,5};
    int x;    
    puts("\nOutput: \n");
    
    for(x = 1; x <= 5; x++)
        printf("fn(%d) = %d\n", x, fn(x, a, 4));
    
    puts("\n");
    return 0;
}
