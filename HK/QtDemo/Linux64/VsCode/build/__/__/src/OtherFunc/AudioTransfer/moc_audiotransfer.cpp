/****************************************************************************
** Meta object code from reading C++ file 'audiotransfer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../../src/OtherFunc/AudioTransfer/audiotransfer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'audiotransfer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AudioTransfer_t {
    QByteArrayData data[11];
    char stringdata0[212];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AudioTransfer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AudioTransfer_t qt_meta_stringdata_AudioTransfer = {
    {
QT_MOC_LITERAL(0, 0, 13), // "AudioTransfer"
QT_MOC_LITERAL(1, 14, 26), // "on_pushButton_exit_clicked"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 19), // "audioTransferDevice"
QT_MOC_LITERAL(4, 62, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(5, 79, 4), // "item"
QT_MOC_LITERAL(6, 84, 6), // "column"
QT_MOC_LITERAL(7, 91, 28), // "on_pushButton_browse_clicked"
QT_MOC_LITERAL(8, 120, 32), // "on_pushButton_talkmrsend_clicked"
QT_MOC_LITERAL(9, 153, 29), // "on_pushButton_startmr_clicked"
QT_MOC_LITERAL(10, 183, 28) // "on_pushButton_stopmr_clicked"

    },
    "AudioTransfer\0on_pushButton_exit_clicked\0"
    "\0audioTransferDevice\0QTreeWidgetItem*\0"
    "item\0column\0on_pushButton_browse_clicked\0"
    "on_pushButton_talkmrsend_clicked\0"
    "on_pushButton_startmr_clicked\0"
    "on_pushButton_stopmr_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AudioTransfer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    2,   45,    2, 0x08 /* Private */,
       7,    0,   50,    2, 0x08 /* Private */,
       8,    0,   51,    2, 0x08 /* Private */,
       9,    0,   52,    2, 0x08 /* Private */,
      10,    0,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Int,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AudioTransfer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AudioTransfer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_exit_clicked(); break;
        case 1: _t->audioTransferDevice((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->on_pushButton_browse_clicked(); break;
        case 3: _t->on_pushButton_talkmrsend_clicked(); break;
        case 4: _t->on_pushButton_startmr_clicked(); break;
        case 5: _t->on_pushButton_stopmr_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AudioTransfer::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_AudioTransfer.data,
    qt_meta_data_AudioTransfer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AudioTransfer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AudioTransfer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AudioTransfer.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int AudioTransfer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
