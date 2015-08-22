
// $Id: bitWise.cpp 5 2007-03-31 15:04:06Z Makhtar $
// #include "../collection.h"  // mycollection of useful functions

#include <iostream>

using namespace std ;

extern void printBinary(const unsigned char val) ;

int main(void)
{
    unsigned int getval;
    unsigned char a, b;

    cout << "Enter a number(a) between 0 and 255: " ;
    cin >> getval;
    a = getval;

    cout << "Enter a number(b) between 0 and 255: " ;
    cin >> getval;
    b = getval;

    cout << "\na in binary: \t";
    printBinary(a);
    cout << endl;

    cout << "\nb in binary: \t";
    printBinary(b);
    cout << endl;

    cout << "\na bitand b = \t";
    printBinary(a bitand b);
    cout << endl;

    cout << "\na bitor b = \t";
    printBinary(a bitor b);
    cout << endl;

    cout << "\na xor b = \t";
    printBinary(a xor b);
    cout << endl;

    cout << "\ncompl a = \t";
    printBinary(compl a);
    cout << endl;

    cout << "\na & 0x5A = \t";
    printBinary(a & 0x5A);
    cout << endl;

    return 0 ;
}

/*
I compiled separatly the file printBinary.cpp so that the object file can
be used even with a C of Fortran program:

 compile with: g++ -o bitWise bitWise.cpp printBinary.o

*/
