/****************************************************************************
** Meta object code from reading C++ file 'GuiTermEmu.hpp'
**
** Created: Fri Mar 6 19:39:32 2009
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GuiTermEmu.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GuiTermEmu.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AbstractTermEmu[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      26,   16,   17,   16, 0x0a,
      44,   16,   16,   16, 0x0a,
      53,   16,   16,   16, 0x0a,
      64,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AbstractTermEmu[] = {
    "AbstractTermEmu\0\0QPalette\0ColorizeTermEmu()\0"
    "RunCmd()\0GetInput()\0Activate()\0"
};

const QMetaObject AbstractTermEmu::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AbstractTermEmu,
      qt_meta_data_AbstractTermEmu, 0 }
};

const QMetaObject *AbstractTermEmu::metaObject() const
{
    return &staticMetaObject;
}

void *AbstractTermEmu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AbstractTermEmu))
        return static_cast<void*>(const_cast< AbstractTermEmu*>(this));
    return QWidget::qt_metacast(_clname);
}

int AbstractTermEmu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QPalette _r = ColorizeTermEmu();
            if (_a[0]) *reinterpret_cast< QPalette*>(_a[0]) = _r; }  break;
        case 1: RunCmd(); break;
        case 2: GetInput(); break;
        case 3: Activate(); break;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
