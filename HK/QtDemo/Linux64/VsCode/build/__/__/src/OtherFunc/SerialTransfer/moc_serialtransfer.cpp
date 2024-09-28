/****************************************************************************
** Meta object code from reading C++ file 'serialtransfer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../../src/OtherFunc/SerialTransfer/serialtransfer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialtransfer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SerialTransfer_t {
    QByteArrayData data[12];
    char stringdata0[305];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialTransfer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialTransfer_t qt_meta_stringdata_SerialTransfer = {
    {
QT_MOC_LITERAL(0, 0, 14), // "SerialTransfer"
QT_MOC_LITERAL(1, 15, 43), // "on_comboBox_channeltype_curre..."
QT_MOC_LITERAL(2, 59, 0), // ""
QT_MOC_LITERAL(3, 60, 5), // "index"
QT_MOC_LITERAL(4, 66, 42), // "on_comboBox_channelnum_curren..."
QT_MOC_LITERAL(5, 109, 45), // "on_comboBox_sendinterface_cur..."
QT_MOC_LITERAL(6, 155, 26), // "on_pushButton_send_clicked"
QT_MOC_LITERAL(7, 182, 33), // "on_pushButton_startserial_cli..."
QT_MOC_LITERAL(8, 216, 32), // "on_pushButton_stopserial_clicked"
QT_MOC_LITERAL(9, 249, 26), // "on_pushButton_exit_clicked"
QT_MOC_LITERAL(10, 276, 23), // "on_lineEdit_textChanged"
QT_MOC_LITERAL(11, 300, 4) // "text"

    },
    "SerialTransfer\0"
    "on_comboBox_channeltype_currentIndexChanged\0"
    "\0index\0on_comboBox_channelnum_currentIndexChanged\0"
    "on_comboBox_sendinterface_currentIndexChanged\0"
    "on_pushButton_send_clicked\0"
    "on_pushButton_startserial_clicked\0"
    "on_pushButton_stopserial_clicked\0"
    "on_pushButton_exit_clicked\0"
    "on_lineEdit_textChanged\0text"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialTransfer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x08 /* Private */,
       4,    1,   57,    2, 0x08 /* Private */,
       5,    1,   60,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    1,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,

       0        // eod
};

void SerialTransfer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SerialTransfer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_comboBox_channeltype_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_comboBox_channelnum_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_comboBox_sendinterface_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_send_clicked(); break;
        case 4: _t->on_pushButton_startserial_clicked(); break;
        case 5: _t->on_pushButton_stopserial_clicked(); break;
        case 6: _t->on_pushButton_exit_clicked(); break;
        case 7: _t->on_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SerialTransfer::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_SerialTransfer.data,
    qt_meta_data_SerialTransfer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SerialTransfer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialTransfer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SerialTransfer.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int SerialTransfer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
