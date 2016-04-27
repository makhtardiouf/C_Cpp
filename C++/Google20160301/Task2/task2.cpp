/**
 * Makhtar Diouf
 * Google Japan University Graduate 20160301 Tests
 *
 * Compile: g++ -g -Wall -std=c++11 task2.cpp -o task2
 * Run: ./task2 < task2_small_sample.input.txt
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <cstring>

using namespace std;

/*
 * Good if it contains K horizontal or vertical consecutive cells whose sum = S
 * Number of cells to sum: 1 <= K <= N.
 */

int
solve (std::map<int, int> v[], int N, int K, int S)
{
  for (int i = 0; i < N; i++)
    {
      int sumRow = 0;
      int sumCol = 0;
      if ((K == 0) && ((sumRow == S) || (sumCol == S)))
	{
	  return 1; // if good
	}
      
      clog << "Sums: ";
      for (int j = 0; j < K; j++)
        {
	  if(sumCol < S)
	    sumCol += v[j][i];
	  else if(sumCol > S) {
	    sumCol = 0;
	  }
	  
	  if(sumRow < S)
	    sumRow += v[i][j];
          else if(sumRow > S) {
	     sumRow = 0;
	     if(j>0)
	       j--;
	  }

          if((sumRow == S) || (sumCol == S))
            {
              return 1; // good
            }
        }
      clog << sumRow << " " << sumCol << endl;
    }

  return 0;
}


int
main (int argc, char* argv[])
{
  int C = 0; // num of test cases
  cin >> C;
  clog << C << " test cases\n";
  string empty;
  getline (cin, empty); // \n

  int K, S = 0;
  int sz, N = 0;

  for (int k = 0; k < C; ++k)
    {
      cin >> N; // 2 <= N <= 15
      clog << "N = " << N << "\n";

      sz = N*N;
      std::map<int, int> rows[sz];
      int val = 0;
      
      // Grid  0 <= g[i,j] <= 9.
      for (int i = 0; i < N; i++)
        {
          for (int j = 0; j < N; j++)
            {
              cin >> val;
              rows[i][j] = val;
              clog << val << " ";
            }
          clog << endl;
        }

      cin >> K;
      cin >> S;
      clog << "K S " << K << " " << S << "\n";

      cout << "Case #" << k + 1 << ": " << solve (rows, N, K, S);
      cout << "\n";
    }

  clog << endl;
  return 0;
}
