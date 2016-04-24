/**
   Selection sort
   g++ -std=c++11 sort_select.cpp -I/usr/local/include/fxt/ -lfxt
   $Id$
*/
#include <cstring>
#include <iostream>
#include "malib.h"
#include <sort/sort.h>
#include <sort/bsearch.h>

using namespace std;

int main()
{
    std::string s = "SELECTIONSORT";
    char* seq = strdup(s.c_str());
    selection_sort(seq, s.size());
    cout << s << ": " << seq << endl;

    int nums[] = {0, 5, 2, 4, 10};
    selection_sort(nums, getArrLength(nums));
    for(auto x: nums)
        cout << x << " ";
    cout << endl;

    cout << "\nbsearch of 4 in sorted nums[]: " << bsearch(nums, getArrLength(nums), 4) << endl;
    return 0;
}
