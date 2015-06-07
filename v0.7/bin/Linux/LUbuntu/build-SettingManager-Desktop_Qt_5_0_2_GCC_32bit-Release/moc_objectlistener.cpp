/****************************************************************************
** Meta object code from reading C++ file 'objectlistener.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../v0.7/objectlistener.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'objectlistener.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ObjectListener_t {
    QByteArrayData data[22];
    char stringdata[238];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ObjectListener_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ObjectListener_t qt_meta_stringdata_ObjectListener = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 11),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 8),
QT_MOC_LITERAL(4, 37, 6),
QT_MOC_LITERAL(5, 44, 18),
QT_MOC_LITERAL(6, 63, 5),
QT_MOC_LITERAL(7, 69, 14),
QT_MOC_LITERAL(8, 84, 8),
QT_MOC_LITERAL(9, 93, 6),
QT_MOC_LITERAL(10, 100, 5),
QT_MOC_LITERAL(11, 106, 5),
QT_MOC_LITERAL(12, 112, 10),
QT_MOC_LITERAL(13, 123, 11),
QT_MOC_LITERAL(14, 135, 12),
QT_MOC_LITERAL(15, 148, 5),
QT_MOC_LITERAL(16, 154, 20),
QT_MOC_LITERAL(17, 175, 10),
QT_MOC_LITERAL(18, 186, 1),
QT_MOC_LITERAL(19, 188, 20),
QT_MOC_LITERAL(20, 209, 12),
QT_MOC_LITERAL(21, 222, 14)
    },
    "ObjectListener\0menuClicked\0\0QAction*\0"
    "action\0tableDoubleClicked\0index\0"
    "dialogAccepted\0QString*\0_title\0_type\0"
    "_text\0_createnew\0CloseWindow\0QCloseEvent*\0"
    "event\0TabWidget_keyPressed\0QKeyEvent*\0"
    "e\0TabView_mousePressed\0QMouseEvent*\0"
    "Button_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ObjectListener[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a,
       1,    1,   55,    2, 0x0a,
       5,    1,   58,    2, 0x0a,
       7,    4,   61,    2, 0x0a,
      13,    1,   70,    2, 0x0a,
      16,    1,   73,    2, 0x0a,
      19,    1,   76,    2, 0x0a,
      21,    0,   79,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QModelIndex,    6,
    QMetaType::Void, 0x80000000 | 8, QMetaType::Int, 0x80000000 | 8, QMetaType::Bool,    9,   10,   11,   12,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 20,   15,
    QMetaType::Void,

       0        // eod
};

void ObjectListener::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ObjectListener *_t = static_cast<ObjectListener *>(_o);
        switch (_id) {
        case 0: _t->menuClicked(); break;
        case 1: _t->menuClicked((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 2: _t->tableDoubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->dialogAccepted((*reinterpret_cast< QString*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString*(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 4: _t->CloseWindow((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 5: _t->TabWidget_keyPressed((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 6: _t->TabView_mousePressed((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 7: _t->Button_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    }
}

const QMetaObject ObjectListener::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ObjectListener.data,
      qt_meta_data_ObjectListener,  qt_static_metacall, 0, 0}
};


const QMetaObject *ObjectListener::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ObjectListener::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ObjectListener.stringdata))
        return static_cast<void*>(const_cast< ObjectListener*>(this));
    return QObject::qt_metacast(_clname);
}

int ObjectListener::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
