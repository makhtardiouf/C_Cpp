
/* $Id: TuiMenu.cpp 2 2007-02-05 09:17:01Z elmakdi $

*/
#include "TuiMenuBar.hpp"

_MenuBar::_MenuBar()
{

  NCursesMenuItem* FileMenu = new NCursesMenuItem("File");

  NCursesMenuItem* ControlMenu = new NCursesMenuItem("Control");

    NCursesMenuItem* MenuHeaders[] = { FileMenu, ControlMenu};

    Menu = new NCursesMenu(MenuHeaders);

    //Menu->show();
}

// END $Id: TuiMenu.cpp 2 2007-02-05 09:17:01Z elmakdi $
