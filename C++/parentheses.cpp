
/*
 * $Id$
 * Makhtar Diouf
 * compile with: g++ -std=c++11 -o bitwiser bitwiser.cpp -L. -lmalib -I/usr/local/include/fxt/ -lfxt
 parenword2str() in FXT lib
 */
#include "malib.h"
#include <cstring>
#include <bitset>
using namespace std;

// A subset of a binary word can be interpreted as a (well formed/balance) string of parentheses.
static inline void bin2parentheses(ulong x, char *str)
{
    int s = 0;
    ulong j = 0;
    for (j=0; x!=0; ++j) {
        s += ( x&1 ? +1 : -1 );
        str[j] = ")("[x&1];
        x >>= 1;
    }
    std::cout << " Num opening parentheses: " << s << "\n";
    while ( s-- > 0 ) str[j++] = ')'; // close parentheses
    str[j] = 0; // terminate string
}

int main()
{
    std::bitset<3> b1("111");
    char str[20];
    bin2parentheses(b1.to_ulong(), str);
    cout << "Representation of " << b1 << ": " << str << "\n";

    memset(str, 0, 20);
    bin2parentheses(7, str);
    cout << "7: " << str << "\n";
    return 0;
}
