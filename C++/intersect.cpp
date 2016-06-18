/**
* Find intersection between Two Sorted arrays.
*
*/
#include <cstdio>
#include <cstdlib>

int checkInsection(int arrA[], int arrB[]) {

  int aLength = sizeof(*arrA) / sizeof(arrA[0]);
  int istPoint = -1;
  int i = 0, j = 0;

  while (i < aLength && j < aLength) {
    if (arrA[i] < arrB[j])
      i++;
    else if (arrA[i] > arrB[j])
      j++;
    else
      return arrA[i];
  }
  return istPoint;
}

int main() {
  int a[] = {1, 2, 3, 6, 8, 10};
  int b[] = {4, 5, 6, 11, 15, 20};

  printf("Intersection point %d\n", checkInsection(a, b));
  return 0;
}
