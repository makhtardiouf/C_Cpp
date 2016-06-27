/**
 * Gen­er­ate Well Ordered Pass­words of a Given Length K
 *
*/
#include "malib.hpp"
#include <algorithm>
#include <random>
#include <string>
#include <iterator>
#include <sstream>
using namespace std;

void printWellOrdered(int number, int x, int k) {
  if (k == 0) {
    cout << number << endl;
    return;
  }

  // 0 ~ 9
  for (int i = (x + 1); i < 10; i++) {
    printWellOrdered(number * 10 + i, i, k - 1);
  }
}

void listWellOrdered(int num, int x, int k) {

  int nChars = k;
  int i = x + 1;
  stringstream ss;

  for (; i <= 9 && nChars > 0; i++) {
    ss << i;
    nChars--;
  }
  cout << ss.str() << endl;
  if ((i - 9) > k)
    listWellOrdered(num + 1, i, k);
}

int main() {

  // printWellOrdered(0, 0, 7);
 // listWellOrdered(0, 0, 7);

vector<int> v;
for(int i=1; i<10; i++) 
    v.push_back(i);

  std::string out;
    std::sample(v.begin(), v.end(), std::back_inserter(out),
                7, std::mt19937{std::random_device{}()});

   cout << out << endl;
  return 0;
}
