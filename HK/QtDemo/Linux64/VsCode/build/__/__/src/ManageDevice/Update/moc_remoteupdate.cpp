/****************************************************************************
** Meta object code from reading C++ file 'remoteupdate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../../src/ManageDevice/Update/remoteupdate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'remoteupdate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RemoteUpdate_t {
    QByteArrayData data[10];
    char stringdata0[208];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RemoteUpdate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RemoteUpdate_t qt_meta_stringdata_RemoteUpdate = {
    {
QT_MOC_LITERAL(0, 0, 12), // "RemoteUpdate"
QT_MOC_LITERAL(1, 13, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 5), // "index"
QT_MOC_LITERAL(4, 52, 36), // "on_pushButton_setnetworktype_..."
QT_MOC_LITERAL(5, 89, 28), // "on_pushButton_browse_clicked"
QT_MOC_LITERAL(6, 118, 28), // "on_pushButton_update_clicked"
QT_MOC_LITERAL(7, 147, 28), // "on_pushButton_cancel_clicked"
QT_MOC_LITERAL(8, 176, 23), // "on_lineEdit_textChanged"
QT_MOC_LITERAL(9, 200, 7) // "OnTimer"

    },
    "RemoteUpdate\0on_comboBox_currentIndexChanged\0"
    "\0index\0on_pushButton_setnetworktype_clicked\0"
    "on_pushButton_browse_clicked\0"
    "on_pushButton_update_clicked\0"
    "on_pushButton_cancel_clicked\0"
    "on_lineEdit_textChanged\0OnTimer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RemoteUpdate[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x08 /* Private */,
       4,    0,   52,    2, 0x08 /* Private */,
       5,    0,   53,    2, 0x08 /* Private */,
       6,    0,   54,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RemoteUpdate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RemoteUpdate *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_setnetworktype_clicked(); break;
        case 2: _t->on_pushButton_browse_clicked(); break;
        case 3: _t->on_pushButton_update_clicked(); break;
        case 4: _t->on_pushButton_cancel_clicked(); break;
        case 5: _t->on_lineEdit_textChanged(); break;
        case 6: _t->OnTimer(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RemoteUpdate::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_RemoteUpdate.data,
    qt_meta_data_RemoteUpdate,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RemoteUpdate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RemoteUpdate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RemoteUpdate.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int RemoteUpdate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
