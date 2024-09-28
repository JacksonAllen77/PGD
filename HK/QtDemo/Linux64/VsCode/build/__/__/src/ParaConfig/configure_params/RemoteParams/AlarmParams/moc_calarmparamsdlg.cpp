/****************************************************************************
** Meta object code from reading C++ file 'calarmparamsdlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../../../../src/ParaConfig/configure_params/RemoteParams/AlarmParams/calarmparamsdlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calarmparamsdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CAlarmParamsDlg_t {
    QByteArrayData data[11];
    char stringdata0[246];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CAlarmParamsDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CAlarmParamsDlg_t qt_meta_stringdata_CAlarmParamsDlg = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CAlarmParamsDlg"
QT_MOC_LITERAL(1, 16, 18), // "changeAlarmInIndex"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 5), // "index"
QT_MOC_LITERAL(4, 42, 32), // "on_checkBoxAlarmInHandle_clicked"
QT_MOC_LITERAL(5, 75, 34), // "on_pushButtonAlarmInHandle_cl..."
QT_MOC_LITERAL(6, 110, 24), // "on_pushButtonPTZ_clicked"
QT_MOC_LITERAL(7, 135, 32), // "on_pushButtonAlarmInSave_clicked"
QT_MOC_LITERAL(8, 168, 33), // "on_pushButtonAlarmOutSave_cli..."
QT_MOC_LITERAL(9, 202, 19), // "changeAlarmOutIndex"
QT_MOC_LITERAL(10, 222, 23) // "changeAlarmOutDateIndex"

    },
    "CAlarmParamsDlg\0changeAlarmInIndex\0\0"
    "index\0on_checkBoxAlarmInHandle_clicked\0"
    "on_pushButtonAlarmInHandle_clicked\0"
    "on_pushButtonPTZ_clicked\0"
    "on_pushButtonAlarmInSave_clicked\0"
    "on_pushButtonAlarmOutSave_clicked\0"
    "changeAlarmOutIndex\0changeAlarmOutDateIndex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CAlarmParamsDlg[] = {

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
       1,    1,   54,    2, 0x0a /* Public */,
       4,    0,   57,    2, 0x0a /* Public */,
       5,    0,   58,    2, 0x0a /* Public */,
       6,    0,   59,    2, 0x0a /* Public */,
       7,    0,   60,    2, 0x0a /* Public */,
       8,    0,   61,    2, 0x0a /* Public */,
       9,    1,   62,    2, 0x0a /* Public */,
      10,    1,   65,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void CAlarmParamsDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CAlarmParamsDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeAlarmInIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_checkBoxAlarmInHandle_clicked(); break;
        case 2: _t->on_pushButtonAlarmInHandle_clicked(); break;
        case 3: _t->on_pushButtonPTZ_clicked(); break;
        case 4: _t->on_pushButtonAlarmInSave_clicked(); break;
        case 5: _t->on_pushButtonAlarmOutSave_clicked(); break;
        case 6: _t->changeAlarmOutIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->changeAlarmOutDateIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CAlarmParamsDlg::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_CAlarmParamsDlg.data,
    qt_meta_data_CAlarmParamsDlg,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CAlarmParamsDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CAlarmParamsDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CAlarmParamsDlg.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int CAlarmParamsDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
