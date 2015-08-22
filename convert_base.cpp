// $Id: convert_base.cpp 5 2007-03-31 15:04:06Z Makhtar $
// Base conversion

#include <iostream>

using namespace std;

int main(void)
{
    // specifying formats with manipulators:
    cout << "\n Decimal number: "  << dec << 24 << endl ;
    cout << " value in octal: 0"       << oct << 24 << endl ;
    cout << " value in hexadecimal: 0x" << hex << 24 << endl ;

    cout << "\n Floating-point number: " << 3.1355683 << endl ;
    cout << " non-printing char (escape): " << char(27) << endl << endl ;

    return 0;
}
