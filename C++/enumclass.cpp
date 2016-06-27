/**
 * enum classs ("strong enums") are strongly typed and scoped:
 * http://www.stroustrup.com/C++11FAQ.html
*/
#include "malib.hpp"
using namespace std;

int main() {

  enum Alert { green, yellow, orange, red }; // traditional enum

  enum class Color { red, blue }; // scoped and strongly typed enum
  // no export of enumerator names into enclosing scope
  // no implicit conversion to int
  enum class TrafficLight { red, yellow, green };

  //	Alert a = 7;              // error (as ever in C++)
  //	Color c = 7;              // error: no int->Color conversion

  int a2 = red;        // ok: Alert->int conversion
  int a3 = Alert::red; // error in C++98; ok in C++11
  //	int a4 = blue;            // error: blue not in scope
  //	int a5 = Color::blue;     // error: not Color->int conversion

  Color a6 = Color::blue; // ok

//  able to specify the underlying type
    enum EE : unsigned long { EE1 = 1, EE2 = 2, EEbig = 0xFFFFFFF0U }; 

  cout << "Enum vals: " << a2 << " " << a3  << " " << (int)a6 << " " << EEbig << endl;
  return 0;
}
