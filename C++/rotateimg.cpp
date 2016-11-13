/**
Rotate 90 deg an image defined as a matrix of pixels

*/
#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

void print(int matrix[][4])
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
      printf("%3d ", matrix[i][j]);
    printf("\n");
  }
}

void rotate(int matrix[][4], int n)
{
  for (int layer = 0; layer < n / 2; ++layer)
  {
    int first = layer;
    int last = n - 1 - layer;
    for (int i = first; i < last; ++i)
    {
      int offset = i - first;
      int top = matrix[first][i]; // save top

      // left -> top
      matrix[first][i] = matrix[last - offset][first];

      // bottom -> left
      matrix[last - offset][first] = matrix[last][last - offset];

      // right -> bottom
      matrix[last][last - offset] = matrix[i][last];

      // top -> right
      matrix[i][last] = top; // right <- retrieve saved top
    }
  }
  print(matrix);
}

int main()
{
  // cout.width(2);
  int matrix[][4] = {{0, 1, 43, 10},
                     {5, 4, 9, -5},
                     {8, 9, -4, 20},
                     {6, 2, -9, 50}};

  print(matrix);
  cout << "\nRotated to: \n\n";
  rotate(matrix, 4);
  return 0;
}
