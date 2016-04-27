
$Id: ThesisReadme.txt 7 2007-05-22 15:03:42Z makhtar $
eDimExch
Education-oriented Dimorphic data Exchanger
By Makhtar Diouf <elmakdi@users.sourceforge.net>

eDimExch aims to be a simple, secure and educative cross-platform file tranferrer application. It brings some of the available open source networkin to non-technical users and as both a graphical user interface(GUI) using the Qt library and a
textual interface(TUI) using the NCurses library. It is written in C/C++ with portability in mind, but the principal target platforms are UNIX-like systems and MS-Windows.


***FEATURE LIST:

***COMPILATION:
The following development packages are needed:
QT 4.2(for the GUI), NCurses 5.x(for the TUI), libssh 0.11, zlib, OpenSSL, GPGME

*On Unix: Execute "make"  under the directory "src" or run the included custom
program builder "makeit".

*On Windows: Dev-C++, MSYS or Relo can be used with MINGW as back bone.
You'll need the header files and the dll of libssh included under the "w32"
directory if you do not already have it in your environment.
