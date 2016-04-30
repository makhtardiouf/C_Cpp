/* 
 * Makhtar Diouf 2004 最大公約数(除算法) kouyakusu2.c 
 * $Id$
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a = 249;
    int b = 54;
    int m = a;
    int n = b;
    int k = 0;
    do
    {
        k = m % n;
        m = n;
        n = k;
    } while(k != 0);
    
    printf("\nSaidai kouyakusuu(2)...\nResult = %d\n\n", m );    
    return 0;
}
