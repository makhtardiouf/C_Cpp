// $Id: convert_base.cpp 5 2007-03-31 15:04:06Z Makhtar $
// Base conversion and output manipulators

#include <ctype.h>
#include <exception>
#include <iomanip> // setprecision
#include <iostream>
#include <string>
using namespace std;

void PrintNumerals(int val) {
  // specifying formats with manipulators:
  cout << "\n\tDecimal: " << dec << val << endl;
  cout << " \tOctal: " << showbase << oct << val << endl;
  cout << " \tHexadecimal: " << hex << val << endl;
}

int main(void) {
  double d = 4509003.13556;
  cout << setprecision(5);
  cout << "\n Floating-point number: " << scientific << d << " = " << fixed << d
       << endl;
  cout << " non-printing char (escape): " << char(27) << endl << endl;

  for (int i = 0; i < 10; i++) {
    try {
      cout << "\nInput a number or Ctrl+c to quit: ";
      int val;
      cin >> val;
      if (!isdigit(val))
        continue;

      PrintNumerals(val);
    } catch (exception e) {
      cout << "Error: " << e.what();
    }
  }

  return 0;
}
