/*
$Id: var_arg.cpp 5 2007-03-31 15:04:06Z Makhtar $
Exemple of a function reporting errors,  with a variable argument list.
*/

#include "malib/malib.hpp"
#include <cstdarg>
#include <iostream>

using namespace std;

void error(int...);

int main(int argc, char *argv[]) {
  switch (argc) {
  case 1:
    error(0, argv[0], NULL);
    break;
  case 2:
    error(0, argv[0], argv[1], NULL);
    break;
  default:
    char buffer[8];
    error(1, argv[0], "with", itoa((argc - 1), buffer), "arguments", NULL);
  }
  return 0;
}

// Implementation of the function `error', the 1st arg(`severity')
// is followed by a zero-terminated list of char*s
void error(int severity...) {
  va_list ap;
  va_start(ap, severity); // arg startup

  for (;;) {
    char *p = va_arg(ap, char *);
    if (p == 0)
      break;
    cerr << p << ' ';
  }
  va_end(ap); // arg cleanup
  cerr << '\n';
  if (severity)
    exit(severity);
}
