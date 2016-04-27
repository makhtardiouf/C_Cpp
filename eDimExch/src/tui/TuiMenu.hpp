
/* $Id: TuiMenu.hpp 2 2007-02-05 09:17:01Z elmakdi $

*/
#ifndef TUIMENUBAR_HPP
#define TUIMENUBAR_HPP

#include "CWidgets.hpp"

class _MenuBar
{

public:
  _MenuBar();

private:
  NCursesMenu* Menu;

  NCursesMenuItem* MenuHeaders[];

//    NCursesMenuItem* FileQuit;

};

#endif
