/**
 * C++14 binary notation
 * Makhtar Diouf
 * c++ -std=c++14 binary.cpp -o binary -I ../malib
*/
#include "malib.hpp"
using namespace std;

int main() {
int a = 0b0011;
// ' to separate long numbers
int b = 0b1100'0110;

cout  << a << " " << b << endl;
    return 0;
}
