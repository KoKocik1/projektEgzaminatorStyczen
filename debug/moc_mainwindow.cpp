/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[15];
    char stringdata0[292];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 22), // "on_PoziomStart_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 16), // "on_start_clicked"
QT_MOC_LITERAL(4, 52, 25), // "on_ImieStudenta_activated"
QT_MOC_LITERAL(5, 78, 5), // "index"
QT_MOC_LITERAL(6, 84, 24), // "on_jakiEgzamin_activated"
QT_MOC_LITERAL(7, 109, 28), // "on_dodPytPodstA_valueChanged"
QT_MOC_LITERAL(8, 138, 4), // "arg1"
QT_MOC_LITERAL(9, 143, 28), // "on_dodPytPodstB_valueChanged"
QT_MOC_LITERAL(10, 172, 28), // "on_dodPytPodstC_valueChanged"
QT_MOC_LITERAL(11, 201, 26), // "on_dodPytSred_valueChanged"
QT_MOC_LITERAL(12, 228, 26), // "on_dodPytTrud_valueChanged"
QT_MOC_LITERAL(13, 255, 17), // "on_edycja_clicked"
QT_MOC_LITERAL(14, 273, 18) // "sprawdzWyswietlacz"

    },
    "MainWindow\0on_PoziomStart_clicked\0\0"
    "on_start_clicked\0on_ImieStudenta_activated\0"
    "index\0on_jakiEgzamin_activated\0"
    "on_dodPytPodstA_valueChanged\0arg1\0"
    "on_dodPytPodstB_valueChanged\0"
    "on_dodPytPodstC_valueChanged\0"
    "on_dodPytSred_valueChanged\0"
    "on_dodPytTrud_valueChanged\0on_edycja_clicked\0"
    "sprawdzWyswietlacz"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

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
       4,    1,   71,    2, 0x08 /* Private */,
       6,    1,   74,    2, 0x08 /* Private */,
       7,    1,   77,    2, 0x08 /* Private */,
       9,    1,   80,    2, 0x08 /* Private */,
      10,    1,   83,    2, 0x08 /* Private */,
      11,    1,   86,    2, 0x08 /* Private */,
      12,    1,   89,    2, 0x08 /* Private */,
      13,    0,   92,    2, 0x08 /* Private */,
      14,    0,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_PoziomStart_clicked(); break;
        case 1: _t->on_start_clicked(); break;
        case 2: _t->on_ImieStudenta_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_jakiEgzamin_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_dodPytPodstA_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_dodPytPodstB_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_dodPytPodstC_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_dodPytSred_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_dodPytTrud_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_edycja_clicked(); break;
        case 10: _t->sprawdzWyswietlacz(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
