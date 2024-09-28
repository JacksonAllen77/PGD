/****************************************************************************
** Meta object code from reading C++ file 'logsearch.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../../src/ManageDevice/LogSearch/logsearch.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logsearch.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LogSearch_t {
    QByteArrayData data[11];
    char stringdata0[281];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LogSearch_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LogSearch_t qt_meta_stringdata_LogSearch = {
    {
QT_MOC_LITERAL(0, 0, 9), // "LogSearch"
QT_MOC_LITERAL(1, 10, 39), // "on_comboBox_logtype_currentIn..."
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 5), // "index"
QT_MOC_LITERAL(4, 57, 40), // "on_comboBox_maintype_currentI..."
QT_MOC_LITERAL(5, 98, 39), // "on_comboBox_subtype_currentIn..."
QT_MOC_LITERAL(6, 138, 37), // "on_dateTimeEdit_start_dateTim..."
QT_MOC_LITERAL(7, 176, 8), // "datetime"
QT_MOC_LITERAL(8, 185, 36), // "on_dateTimeEdit_stop_dateTime..."
QT_MOC_LITERAL(9, 222, 31), // "on_pushButton_searchlog_clicked"
QT_MOC_LITERAL(10, 254, 26) // "on_pushButton_exit_clicked"

    },
    "LogSearch\0on_comboBox_logtype_currentIndexChanged\0"
    "\0index\0on_comboBox_maintype_currentIndexChanged\0"
    "on_comboBox_subtype_currentIndexChanged\0"
    "on_dateTimeEdit_start_dateTimeChanged\0"
    "datetime\0on_dateTimeEdit_stop_dateTimeChanged\0"
    "on_pushButton_searchlog_clicked\0"
    "on_pushButton_exit_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LogSearch[] = {

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
       4,    1,   52,    2, 0x08 /* Private */,
       5,    1,   55,    2, 0x08 /* Private */,
       6,    1,   58,    2, 0x08 /* Private */,
       8,    1,   61,    2, 0x08 /* Private */,
       9,    0,   64,    2, 0x08 /* Private */,
      10,    0,   65,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QDateTime,    7,
    QMetaType::Void, QMetaType::QDateTime,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LogSearch::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LogSearch *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_comboBox_logtype_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_comboBox_maintype_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_comboBox_subtype_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_dateTimeEdit_start_dateTimeChanged((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 4: _t->on_dateTimeEdit_stop_dateTimeChanged((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 5: _t->on_pushButton_searchlog_clicked(); break;
        case 6: _t->on_pushButton_exit_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LogSearch::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_LogSearch.data,
    qt_meta_data_LogSearch,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LogSearch::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LogSearch::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LogSearch.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int LogSearch::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
