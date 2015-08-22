// $Id: assertit.cpp 3 2007-03-28 20:49:35Z elmakdi $

#include <cassert>

int main(void)
{
    int number=230;
    assert(number not_eq 230);  // fails

    return 0 ;
}
