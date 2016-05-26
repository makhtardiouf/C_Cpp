
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;



int maxDifference(vector <int> v) {
     std::vector<int>::iterator itMax = std::max_element(v.begin(), v.end());
    std::vector<int>::iterator itMin = std::min(v.begin(), itMax -1);
    
    if(itMax <= itMin)
        return -1;
        
    return *itMax - *itMin;    
}

int main() {
   // char mess[]  = "Hello World";
 int n = 5;
 std::bitset<10> b(n);
 b.flip();
 
 cout << b.to_ulong();
 
        return 0;
    
}