/****************************************************************************
** Meta object code from reading C++ file 'cremoteparams.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../../../src/ParaConfig/configure_params/RemoteParams/cremoteparams.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cremoteparams.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CRemoteParams_t {
    QByteArrayData data[12];
    char stringdata0[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CRemoteParams_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CRemoteParams_t qt_meta_stringdata_CRemoteParams = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CRemoteParams"
QT_MOC_LITERAL(1, 14, 13), // "refreshParams"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 10), // "saveParams"
QT_MOC_LITERAL(4, 40, 9), // "clickDHCP"
QT_MOC_LITERAL(5, 50, 16), // "clickAdvancedNet"
QT_MOC_LITERAL(6, 67, 8), // "clickNFS"
QT_MOC_LITERAL(7, 76, 12), // "clickZoneDst"
QT_MOC_LITERAL(8, 89, 9), // "clickRtsp"
QT_MOC_LITERAL(9, 99, 18), // "clickCompressAudio"
QT_MOC_LITERAL(10, 118, 12), // "clickTabPage"
QT_MOC_LITERAL(11, 131, 9) // "iTabIndex"

    },
    "CRemoteParams\0refreshParams\0\0saveParams\0"
    "clickDHCP\0clickAdvancedNet\0clickNFS\0"
    "clickZoneDst\0clickRtsp\0clickCompressAudio\0"
    "clickTabPage\0iTabIndex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CRemoteParams[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    0,   64,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x0a /* Public */,
      10,    1,   67,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void CRemoteParams::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CRemoteParams *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->refreshParams(); break;
        case 1: _t->saveParams(); break;
        case 2: _t->clickDHCP(); break;
        case 3: _t->clickAdvancedNet(); break;
        case 4: _t->clickNFS(); break;
        case 5: _t->clickZoneDst(); break;
        case 6: _t->clickRtsp(); break;
        case 7: _t->clickCompressAudio(); break;
        case 8: _t->clickTabPage((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CRemoteParams::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_CRemoteParams.data,
    qt_meta_data_CRemoteParams,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CRemoteParams::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CRemoteParams::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CRemoteParams.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CRemoteParams::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
