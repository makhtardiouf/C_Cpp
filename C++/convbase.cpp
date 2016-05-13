// $Id: convert_base.cpp 5 2007-03-31 15:04:06Z Makhtar $
// Base conversion and output manipulators

#include <exception>
#include <iostream>
#include <iomanip>  // setprecision
#include <string>
using namespace std;

void PrintNumerals(int val) {
  // specifying formats with manipulators:
  cout << "\nDecimal value : " << dec << val << endl;
  cout << " Octal: " << showbase << oct << val << endl;
  cout << " Hexadecimal: " << hex << val << endl;
}

int main(void) {
  double d = 1000003.1355683;
  cout << setprecision(5);
  cout << "\n Floating-point number: " << scientific << d << " = " << fixed << d
       << endl;
  cout << " non-printing char (escape): " << char(27) << endl << endl;

  for (int i = 0; i < 10; i++) {
    try {
      cout << "\nInput a number or q to quit: ";
      // pressing q sends the prog in a continuous loop !
      int val;
      cin >> val;
      if (val == 'q')
        return 0;

      PrintNumerals(val);
    } catch (exception e) {
      cout << "Error: " << e.what();
    }
  }

  return 0;
}
