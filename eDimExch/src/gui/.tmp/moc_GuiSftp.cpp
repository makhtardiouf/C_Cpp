/****************************************************************************
** Meta object code from reading C++ file 'GuiSftp.hpp'
**
** Created: Fri Mar 6 19:39:24 2009
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GuiSftp.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GuiSftp.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AbstractDetailsWin[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AbstractDetailsWin[] = {
    "AbstractDetailsWin\0\0SelectKey()\0"
};

const QMetaObject AbstractDetailsWin::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AbstractDetailsWin,
      qt_meta_data_AbstractDetailsWin, 0 }
};

const QMetaObject *AbstractDetailsWin::metaObject() const
{
    return &staticMetaObject;
}

void *AbstractDetailsWin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AbstractDetailsWin))
        return static_cast<void*>(const_cast< AbstractDetailsWin*>(this));
    return QDialog::qt_metacast(_clname);
}

int AbstractDetailsWin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: SelectKey(); break;
        }
        _id -= 1;
    }
    return _id;
}
static const uint qt_meta_data_AbstractSftp[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      27,   13,   13,   13, 0x0a,
      48,   43,   13,   13, 0x0a,
      80,   13,   13,   13, 0x0a,
      97,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AbstractSftp[] = {
    "AbstractSftp\0\0RedispTest()\0UpdateLocalFs()\0"
    "item\0UpdateLocalFs(QListWidgetItem*)\0"
    "ListLocalFiles()\0EnableDetailsBt()\0"
};

const QMetaObject AbstractSftp::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AbstractSftp,
      qt_meta_data_AbstractSftp, 0 }
};

const QMetaObject *AbstractSftp::metaObject() const
{
    return &staticMetaObject;
}

void *AbstractSftp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AbstractSftp))
        return static_cast<void*>(const_cast< AbstractSftp*>(this));
    return QWidget::qt_metacast(_clname);
}

int AbstractSftp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: RedispTest(); break;
        case 1: UpdateLocalFs(); break;
        case 2: UpdateLocalFs((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: ListLocalFiles(); break;
        case 4: EnableDetailsBt(); break;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
