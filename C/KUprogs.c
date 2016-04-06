/* 
 e2550 ::: 20040617 ::: B2exercise2004 0604 ::: 以下，五つのソースプログラムをまとめ,
 keyboard から変数の値を入力するより，直接ソースプログラム中に一定の値を設定しました
 Makhtar Diouf 
 ----- 組み合わせの数 nCr 
*/

#include <stdio.h>

int combine(int n ,int r)
{
  int i;
  int x = 1;                    /* 0次の値  */

  for(i=1;i<=r;i++)
    x = x*(n-i+1)/i;            /* 漸化式 */
  return x;
}

int main(void)
{
  int n,r;

  puts("\nPossible combinations are:\n\n");
  for(n=0;n<=5; n++)
    {
      for(r=0; r<=n; r++)
        printf("%d C%2d =%d  ",n,r,combine(n,r));
      puts("\n");
    }

  puts("\n");

}

/* 実行例    */



/* 検討等    */



---------------------------------------------------------------------------



/*---------------------- Elh.M. Diouf Hornerの方法 */
#include <stdio.h>

int fn(int x, int a[], int n)
{

  int buf;
  int i;
  buf = a[n];
  for(i=n-1;i>=0;i--)
    buf = buf*x+a[i];

  return buf;
}

int main(void)
{
  int a[]={1,2,3,4,5};
  int x;

  puts("\nOutput: \n");

  for(x=1;x<=5;x++)
    printf("fn(%d) = %d\n",x,fn(x,a,4));

  puts("\n");
  return 0;

}

 /*--------------------- Elh. M. Diouf ::: StudNo> 021T3550 ::: Prg>最大公約数(減算法)> kouyakusu1.c     */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   int a,b,m,n;
   a = 453;
   b = 12;

   m = a;
   n = b;
   while (m - n !=0)
   {
     if(m>n)
        m = m - n;
     else
        n = n - m;
   }

   printf("\nSaidai kouyakusuu(1)...\nResult = %d\n\n",m );

      system("PAUSE");
      return 0;
}

/*------- Elh. M. Diouf : 最大公約数(除算法) kouyakusu2.c */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   int a,b,m,n,k;
   a = 249;
   b = 54;

   m = a;
   n = b;
   do
   {
     k = m % n;
     m = n;
     n = k;
   } while(k!=0);

   printf("\nSaidai kouyakusuu(2)...\nResult = %d\n\n",m );

      system("PAUSE");
      return 0;
}

/*---------------  Name> Elh M. Diouf ::: StudNo> 021T3550 ::: Prg>Newton 法> myNewton.c */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define Eps 1e-5

float f(float x) { return (x*x)-(2*x)-1 ; }
float df(float x) { return (2*x)-2 ; }
int calc(float );

int main(void)
{
   float x = 4;
   printf("Newton...Output...\n x = %f\n",x);
      calc(x);

      system("PAUSE");
    return 0;
}

int calc( float x)
{
  float nextX;
  int i;

  for(i=1; ;i++)
  {
     nextX = x - f(x)/df(x);
     if (fabs(nextX -x) < (Eps* fabs(nextX)))
      {
        printf("\n Result: x = %f \n\n", nextX);
        break;
      }
     x = nextX;
  }

}
