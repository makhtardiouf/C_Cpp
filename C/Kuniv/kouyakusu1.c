/* 
 * Makhtar Diouf 2004 最大公約数(減算法) kouyakusu1.c
 * $Id$
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a = 453;
    int b = 12;
    int m = a;
    int n = b;
    while (m - n != 0)
    {
        if(m > n)
            m = m - n;
        else
            n = n - m;
    }
    
    printf("\nSaidai kouyakusuu(1)...\nResult = %d\n\n", m);
    return 0;
}
