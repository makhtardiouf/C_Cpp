/*
  Find all pairs of 5-digit numbers that collectively
  use the digits 0 through 9 once each, such that the first number divided by the second is
  equal to an integer N, where 2 ≤ N ≤ 79. P96

  g++ -std=c++11 digits_pairs725.cpp -o digits_pairs
  ./digits_pairs
  num1 = abcde, num2 = fghij
  Makhtar Diouf $Id$
*/
//#include "malib.h"
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
    // For manual testing
    // vector<int> inputs = {1, 61, 62, 4};
    //    for(int N: inputs)
    int N = 0;
    while(cin >> N)
        {
            if(N == 0)
                return 0;
            bool hit = false;
            printf("\n");
            for (int num2 = 1234; num2 <= (98765 / N); num2++)
                {
                    // num1 and num2 are at most 5 digits
                    int num1 = num2 * N;

                    // if digit f=0, then we have to flag it
                    int tmp, used = (num2 < 10000);
                    tmp = num1;
                    while (tmp)
                        {
                            used |= 1 << (tmp % 10);
                            tmp /= 10;
                        }

                    tmp = num2;
                    while (tmp)
                        {
                            used |= 1 << (tmp % 10);
                            tmp /= 10;
                        }
                    // cout << " used " << used;
                    // if all 10 digits are used, print it
                    if (used == (1<<10) - 1)
                        {
                            printf("%05d / %05d = %d\n", num1, num2, N);
                            hit = true;
                        }
                }
            if(!hit)
                printf("There are no solutions for %d.\n", N);
        }
}

