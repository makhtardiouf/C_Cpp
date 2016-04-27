
/* $Id: tui.cpp 2 2007-02-05 09:17:01Z elmakdi $

Implementation of Textual User Interface */

#include "Tui.hpp"

Tui::Tui(int nlines, int ncols, 
	 int begin_y, int begin_x)
    : NCursesWindow(nlines, ncols, begin_y, begin_x)
{
    this->box();

    MenuBar = new _MenuBar();

    //    set_menu_win(MenuBar, this);

    //    this->refresh();
}

// END $Id: tui.cpp 2 2007-02-05 09:17:01Z elmakdi $
