/* 
 * Makhtar Diouf e2550 20040617  B2.2004 0604,
 * kbd から変数の値を入力するより，直接ソースプログラム中に一定の値を設定しました
 * 組み合わせの数 nCr 
 * $Id$
 */
#include <stdio.h>

int combine(int n ,int r)
{
    int i;
    int x = 1;
    
    for(i = 1; i <= r; i++)
        x = x*(n-i+1)/i;  /* 漸化式 */
    return x;
}

int main(void)
{
    int n, r;
    
    puts("\nPossible combinations are:\n\n");
    for(n = 0; n <= 5; n++)
    {
        for(r = 0; r <= n; r++)
            printf("%d C%2d = %d,  ", n, r, combine(n,r));
        puts("\n");
    }
    
    puts("\n");
}
