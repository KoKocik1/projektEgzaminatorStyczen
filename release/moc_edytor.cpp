/****************************************************************************
** Meta object code from reading C++ file 'edytor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../edytor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'edytor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_edytor_t {
    QByteArrayData data[13];
    char stringdata0[241];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_edytor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_edytor_t qt_meta_stringdata_edytor = {
    {
QT_MOC_LITERAL(0, 0, 6), // "edytor"
QT_MOC_LITERAL(1, 7, 17), // "on_koniec_clicked"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 20), // "on_readPodsA_clicked"
QT_MOC_LITERAL(4, 47, 20), // "on_readPodsB_clicked"
QT_MOC_LITERAL(5, 68, 20), // "on_readPodsC_clicked"
QT_MOC_LITERAL(6, 89, 19), // "on_readSred_clicked"
QT_MOC_LITERAL(7, 109, 19), // "on_readTrud_clicked"
QT_MOC_LITERAL(8, 129, 22), // "on_readDyplomA_clicked"
QT_MOC_LITERAL(9, 152, 22), // "on_readDyplomB_clicked"
QT_MOC_LITERAL(10, 175, 22), // "on_readDyplomC_clicked"
QT_MOC_LITERAL(11, 198, 22), // "on_readDyplomD_clicked"
QT_MOC_LITERAL(12, 221, 19) // "on_readStud_clicked"

    },
    "edytor\0on_koniec_clicked\0\0"
    "on_readPodsA_clicked\0on_readPodsB_clicked\0"
    "on_readPodsC_clicked\0on_readSred_clicked\0"
    "on_readTrud_clicked\0on_readDyplomA_clicked\0"
    "on_readDyplomB_clicked\0on_readDyplomC_clicked\0"
    "on_readDyplomD_clicked\0on_readStud_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_edytor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void edytor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<edytor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_koniec_clicked(); break;
        case 1: _t->on_readPodsA_clicked(); break;
        case 2: _t->on_readPodsB_clicked(); break;
        case 3: _t->on_readPodsC_clicked(); break;
        case 4: _t->on_readSred_clicked(); break;
        case 5: _t->on_readTrud_clicked(); break;
        case 6: _t->on_readDyplomA_clicked(); break;
        case 7: _t->on_readDyplomB_clicked(); break;
        case 8: _t->on_readDyplomC_clicked(); break;
        case 9: _t->on_readDyplomD_clicked(); break;
        case 10: _t->on_readStud_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject edytor::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_edytor.data,
    qt_meta_data_edytor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *edytor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *edytor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_edytor.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int edytor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
