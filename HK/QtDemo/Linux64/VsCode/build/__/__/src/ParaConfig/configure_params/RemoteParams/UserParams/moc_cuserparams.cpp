/****************************************************************************
** Meta object code from reading C++ file 'cuserparams.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../../../../src/ParaConfig/configure_params/RemoteParams/UserParams/cuserparams.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cuserparams.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CUserParams_t {
    QByteArrayData data[8];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CUserParams_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CUserParams_t qt_meta_stringdata_CUserParams = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CUserParams"
QT_MOC_LITERAL(1, 12, 13), // "userIDChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 7), // "iUserID"
QT_MOC_LITERAL(4, 35, 21), // "localRightTypeChanged"
QT_MOC_LITERAL(5, 57, 15), // "iLocalRightType"
QT_MOC_LITERAL(6, 73, 22), // "remoteRightTypeChanged"
QT_MOC_LITERAL(7, 96, 16) // "iRemoteRightType"

    },
    "CUserParams\0userIDChanged\0\0iUserID\0"
    "localRightTypeChanged\0iLocalRightType\0"
    "remoteRightTypeChanged\0iRemoteRightType"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CUserParams[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       4,    1,   32,    2, 0x0a /* Public */,
       6,    1,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void CUserParams::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CUserParams *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->userIDChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->localRightTypeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->remoteRightTypeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CUserParams::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_CUserParams.data,
    qt_meta_data_CUserParams,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CUserParams::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CUserParams::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CUserParams.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int CUserParams::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
