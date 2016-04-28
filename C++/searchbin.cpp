/**
   Binary search using std::lower_bound / upper_bound
   
   Makhtar diouf
   $Id$
   c++ -g -Wall -std=c++11 searchbin.cpp -o searchbin
*/
#include "malib/malib.hpp"

int main() {
    using namespace std;
    clockit();
    
    std::vector<int> v;
    for(int i=0; i < 100; i++) {
     v.push_back(rand() % 5);           
    }
    v.push_back(20);
    printf("Vector of size: %lu\n", v.size());
    printV(v);
    
    cout << "Search target v[3]: " << *(std::lower_bound(v.begin(), v.end(), -100)) << endl;
    cout << "Search target " << v[v.size()-1] << ": " << *(std::upper_bound(v.begin(), v.end(), v[v.size()-1])) << endl;
    
    clockit();
    return 0;
}
