
/* $Id: tui.hpp 2 2007-02-05 09:17:01Z elmakdi $
 
Textual User Interface Object's Interface */

#ifndef TUI_HPP
#define TUI_HPP

#include "Dimorftp.h"      // global vars
#include "CWidgets.hpp"		// custome Curses Widgets
#include "TuiMenuBar.hpp"     //_MenuBar object's interface
//#include "TuiEditorTab.hpp"  //_EditorTab object's interface
#include "TuiFtpTab.hpp"     //_FtpTab object's interface

#include <cstdlib>
#include <sstream>              // ostringstream
#include <string>               // string
#include <iostream>             // cerr(for debugging)

// namespace Dim
// {

/** The Graphical User Interface object */
class Tui : public NCursesWindow
{
    friend class _FtpTab;

public:
    Tui(int nlines, int ncols, int begin_y = 0, int begin_x = 0);

    // slots (similar to callback functions in some toolkits)

private:
    /** Set the title of the main window. */
    void SetTitle(std::string postfix = ""){;}

    /** Display information about the application */
    void About() {;}

  void ShowMessage(std::string msg){;}

  void OpenFile(){;}

  //    void Cd(QListWidgetItem* item);

  void SetLocalPath(std::string path){;}

  void Connection(){;}

  void Disconnection(){;}

  void Cancel() {;}

  void ShowProgression(){;}

  void AddToList(std::string file){;}


private:

    enum
    {
        MAXCHARS = 15,
        MAXHEIGHT = 25
    };

    /** Set the general look and feel of the application */
  void SetAesthetics(){;}

    /** Setup connections between Signals and Slots */
  void SetConnections(){;}

    // Top part composed by a menu bar and its components
     _MenuBar* MenuBar;
    // Main part composed of tabs
    //   NCursesPanel* TabGroup;

  //    _EditorTab* EditorTab;

    _FtpTab* FtpTab;

    // Bottom part composed of buttons and the status bar
    CButton* connectBt;

    CButton* disconnectBt;

    CButton* quitBt;

    NCursesFormField* StatusBar;
};

//} // END Dim namespace

#endif

// END $Id: tui.hpp 2 2007-02-05 09:17:01Z elmakdi $
