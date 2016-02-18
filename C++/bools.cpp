// $Id: bools.cpp 5 2007-03-31 15:04:06Z Makhtar $
// verify the value of a bool result

#include <iostream>
#include <cctype>

int
main (void)
{
    int a = 0, b = 0;

    using namespace std;

    for (int ch = 'A'; ch < 'H'; ch++) {
        cout << "Enter a value: ";
        cin >> a;

        if (a<0)
            break;

        else {
            cout << "Enter a second value: ";
            cin >> b;
            cout << endl << endl;

            cout << "a < b ? is: " << (a < b) << endl;

            cout << endl << endl;
        }

    }
    return 0;
}
