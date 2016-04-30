/* 
 * Makhtar Diouf 2004 Newton 法
 * $Id$
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define Eps 1e-5

float f(float x) { return (x*x) - (2*x) -1; }
float df(float x) { return (2*x) -2; }
int calc(float );

int main(void)
{
    float x = 4;
    printf("Newton...Output...\n x = %f\n",x);
    calc(x);    
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
