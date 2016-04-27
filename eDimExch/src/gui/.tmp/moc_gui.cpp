/****************************************************************************
** Meta object code from reading C++ file 'gui.hpp'
**
** Created: Fri Mar 6 19:39:09 2009
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gui.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gui.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Gui[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      33,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
       9,    5,    4,    4, 0x0a,
      39,   34,    4,    4, 0x08,
      58,    4,    4,    4, 0x08,
      67,    4,    4,    4, 0x08,
      79,    4,    4,    4, 0x08,
      92,    4,    4,    4, 0x08,
     103,    4,    4,    4, 0x08,
     121,    4,    4,    4, 0x08,
     143,    4,  139,    4, 0x08,
     172,    4,  160,    4, 0x08,
     179,    4,  139,    4, 0x08,
     195,    4,  139,    4, 0x08,
     210,    4,    4,    4, 0x08,
     218,    4,    4,    4, 0x08,
     233,    4,  227,    4, 0x08,
     240,    4,  139,    4, 0x08,
     253,    4,  139,    4, 0x08,
     265,  260,    4,    4, 0x08,
     279,    4,    4,    4, 0x28,
     305,  290,    4,    4, 0x08,
     324,    4,  139,    4, 0x08,
     338,    4,    4,    4, 0x08,
     354,    4,    4,    4, 0x08,
     362,    4,    4,    4, 0x08,
     378,    4,    4,    4, 0x08,
     401,  393,    4,    4, 0x08,
     423,    4,    4,    4, 0x28,
     438,  434,    4,    4, 0x08,
     455,  434,    4,    4, 0x08,
     485,    4,  477,    4, 0x08,
     497,    4,    4,    4, 0x08,
     509,    4,    4,    4, 0x08,
     518,    4,  227,    4, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Gui[] = {
    "Gui\0\0str\0SetHostname(const char*)\0"
    "file\0AddToList(QString)\0Cancel()\0"
    "CdUpLocal()\0CdUpRemote()\0Download()\0"
    "EnableConnectBt()\0ExecLoginMethod()\0"
    "int\0GetLoginMethod()\0const char*\0"
    "Host()\0InteractLogin()\0ListRemoteFs()\0"
    "Login()\0Logout()\0char*\0Pass()\0"
    "PasswLogin()\0Port()\0fake\0Progress(int)\0"
    "Progress()\0value,showText\0Progress(int,bool)\0"
    "PubKeyLogin()\0UpdateLocalFs()\0Retry()\0"
    "SetAesthetics()\0SetCallbacks()\0postfix\0"
    "SetTitle(std::string)\0SetTitle()\0msg\0"
    "ShowMsg(QString)\0SysError(const char*)\0"
    "QString\0SftpError()\0TellAbout()\0"
    "Upload()\0User()\0"
};

const QMetaObject Gui::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Gui,
      qt_meta_data_Gui, 0 }
};

const QMetaObject *Gui::metaObject() const
{
    return &staticMetaObject;
}

void *Gui::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Gui))
        return static_cast<void*>(const_cast< Gui*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Gui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: SetHostname((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 1: AddToList((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: Cancel(); break;
        case 3: CdUpLocal(); break;
        case 4: CdUpRemote(); break;
        case 5: Download(); break;
        case 6: EnableConnectBt(); break;
        case 7: ExecLoginMethod(); break;
        case 8: { int _r = GetLoginMethod();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 9: { const char* _r = Host();
            if (_a[0]) *reinterpret_cast< const char**>(_a[0]) = _r; }  break;
        case 10: { int _r = InteractLogin();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 11: { int _r = ListRemoteFs();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 12: Login(); break;
        case 13: Logout(); break;
        case 14: { char* _r = Pass();
            if (_a[0]) *reinterpret_cast< char**>(_a[0]) = _r; }  break;
        case 15: { int _r = PasswLogin();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 16: { int _r = Port();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 17: Progress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: Progress(); break;
        case 19: Progress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 20: { int _r = PubKeyLogin();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 21: UpdateLocalFs(); break;
        case 22: Retry(); break;
        case 23: SetAesthetics(); break;
        case 24: SetCallbacks(); break;
        case 25: SetTitle((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 26: SetTitle(); break;
        case 27: ShowMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 28: SysError((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 29: { QString _r = SftpError();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 30: TellAbout(); break;
        case 31: Upload(); break;
        case 32: { char* _r = User();
            if (_a[0]) *reinterpret_cast< char**>(_a[0]) = _r; }  break;
        }
        _id -= 33;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
