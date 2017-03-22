/* $Id: char_code.c 9 2007-07-11 08:22:53Z Makhtar $

  Print the ASCII code of some characters
  Mixing C and C++ at will
  make char_code
 */
#include "malib.hpp"
#include <ctype.h>
#include <string>

int main(int argc, char *argv[]) {
  char output[16];
  clearconsole();
  std::string msg = "\n\tEnter an alpha-numeric character or # to quit: ";
  std::cout << msg;
  for (char ch = 0; std::cin >> ch, ch != '#';) {
    rotate_dash();
    if (!isalnum(ch))
      continue;

    // Discard the new line char if using printf above
    // getchar ();
    printf("\tAscii code of \'%c\' ", ch);
    fflush(stdout);
    sprintf(output, "is %d\n", ch);
    typewrite(output);
    std::cout << msg;
  }

  char c = 122;
  printf("\nCharacter corresponding to %d: '%c' \n", c, c);

  // C++11 initializations for implicit conversions warnings
  double x{2.7}; // OK
  // int y{x};       // error: double -> int might narrow
  int a{1000}; // OK
  // char b{a};     // error: int -> char might narrow
  printf("%.3f %d\n", x, a);
  pausethis(1);
  return EXIT_SUCCESS;
}
