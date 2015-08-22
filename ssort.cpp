/*
$Id: ssort.cpp 5 2007-03-31 15:04:06Z Makhtar $
Shell sort (stroustrup P169) with pointer to functions
*/

#include <iostream>
#include <cstring>
#include <cstdarg>
//#include "emdutils.h"

using namespace std;

/*** PROTO ***/

/*
CFT: pointer to a function which takes 2 `const void*' args
and returns an `int'
*/
typedef int (*CFT) (const void* , const void* );

/*
ssort() :Sort the elements of a vector into increasing order
using the comparison function pointed to.
*/
void ssort(void* , size_t , size_t , CFT );

/*
Example of a table to sort
*/
struct Hacker
{
    char* name;
    char* id;
    int dept;
};

/*
print_id(): prints the name, id, dept of each hacker
*/
void print_id(Hacker* , int );

/*
Functions used by ssort() to make comparisons
They should match the arg-types of CFT
*/
int cmp1(const void* , const void* ); // compare name strings
int cmp2(const void* , const void* ); // compare dept numbers

/*** END PROTO ***/


int main(void)
{
    Hacker heads[] =
        {
            "Ritchie D.M.",   "dmr",  11271,
            "Ken Thompson",   "kth",  11272,
            "Kernighan B.W.", "bwk",  11273,
            "Ritchard M.S.",  "rms",  11274,
            "Linus B.T.",     "lbt",  11275,
            "Eric S.R.",      "esr",  11276
        };

    cout<< "\nHackers in alphabetical order:\n";
    ssort(heads, 6, sizeof(Hacker), cmp1);
    print_id(heads, 6);
    cout << endl;

    cout<< "Hackers in order of department number:\n";
    ssort(heads, 6, sizeof(Hacker), cmp2);
    print_id(heads, 6);
    cout << endl;

    return 0 ;
}

/*** IMPLEM ***/

/*
ssort():
Sort the `n' elements of vector `base' into increasing order
using the comparison function pointed to by `cmp'.
The elements are of size `sz'.
*/
void ssort(void* base, size_t n, size_t sz, CFT cmp)
{
    for (int gap = n/2;  0 < gap;  gap /= 2)
        for (int i = gap;  i < n;  i++)
            for (int j = i - gap;  0 <= j;  j -= gap) {
                char* b = static_cast<char*>(base);
                char* pj = b + (j * sz); // &base[j]
                char* pjg = b + ((j + gap) * sz); // &base[j + gap]

                if (cmp(pj, pjg) < 0) // swap base[j] and base[j + gap]
                {
                    for (int k = 0; k < sz; k++)
                    {
                        char temp = pj[k];
                        pj[k] = pjg[k];
                        pjg[k] = temp;
                    }
                }
            }
}

/*
print_id():
*/
void print_id(Hacker* v, int n)
{
    for (int i = 0;  i < n;  i++)
        cout << v[i].name << "\t\t" << v[i].id << "\t\t" << v[i].dept << "\n";
}

/*
cmp1(): compare name strings
*/
int cmp1(const void* p, const void* q)
{
    return strcmp(static_cast<const Hacker*>(q)->name,
                  static_cast<const Hacker*>(p)->name);
}

/*
cmp2(): compare dept numbers
 */
int cmp2(const void* p, const void* q)
{
    return static_cast<const Hacker*>(q)->dept -
           static_cast<const Hacker*>(p)->dept;
}
