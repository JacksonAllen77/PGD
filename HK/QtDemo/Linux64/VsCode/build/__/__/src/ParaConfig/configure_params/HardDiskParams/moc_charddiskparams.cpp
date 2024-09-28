/****************************************************************************
** Meta object code from reading C++ file 'charddiskparams.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../../../src/ParaConfig/configure_params/HardDiskParams/charddiskparams.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'charddiskparams.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CHardDiskParams_t {
    QByteArrayData data[9];
    char stringdata0[173];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CHardDiskParams_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CHardDiskParams_t qt_meta_stringdata_CHardDiskParams = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CHardDiskParams"
QT_MOC_LITERAL(1, 16, 22), // "on_btnHDUpdate_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 20), // "on_btnHDSave_clicked"
QT_MOC_LITERAL(4, 61, 27), // "on_btnHDGroupUpdate_clicked"
QT_MOC_LITERAL(5, 89, 25), // "on_btnHDGroupSave_clicked"
QT_MOC_LITERAL(6, 115, 19), // "comboHDGroupChanged"
QT_MOC_LITERAL(7, 135, 13), // "iHDGroupIndex"
QT_MOC_LITERAL(8, 149, 23) // "on_checkAllChan_clicked"

    },
    "CHardDiskParams\0on_btnHDUpdate_clicked\0"
    "\0on_btnHDSave_clicked\0on_btnHDGroupUpdate_clicked\0"
    "on_btnHDGroupSave_clicked\0comboHDGroupChanged\0"
    "iHDGroupIndex\0on_checkAllChan_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CHardDiskParams[] = {

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
       1,    0,   44,    2, 0x0a /* Public */,
       3,    0,   45,    2, 0x0a /* Public */,
       4,    0,   46,    2, 0x0a /* Public */,
       5,    0,   47,    2, 0x0a /* Public */,
       6,    1,   48,    2, 0x0a /* Public */,
       8,    0,   51,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,

       0        // eod
};

void CHardDiskParams::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CHardDiskParams *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnHDUpdate_clicked(); break;
        case 1: _t->on_btnHDSave_clicked(); break;
        case 2: _t->on_btnHDGroupUpdate_clicked(); break;
        case 3: _t->on_btnHDGroupSave_clicked(); break;
        case 4: _t->comboHDGroupChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_checkAllChan_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CHardDiskParams::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_CHardDiskParams.data,
    qt_meta_data_CHardDiskParams,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CHardDiskParams::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CHardDiskParams::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CHardDiskParams.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CHardDiskParams::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
