/****************************************************************************
** Meta object code from reading C++ file 'exqtabwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../v0.7/exqtabwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'exqtabwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ExQTabWidget_t {
    QByteArrayData data[8];
    char stringdata[71];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ExQTabWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ExQTabWidget_t qt_meta_stringdata_ExQTabWidget = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 10),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 10),
QT_MOC_LITERAL(4, 36, 1),
QT_MOC_LITERAL(5, 38, 12),
QT_MOC_LITERAL(6, 51, 12),
QT_MOC_LITERAL(7, 64, 5)
    },
    "ExQTabWidget\0keyPressed\0\0QKeyEvent*\0"
    "e\0mousePressed\0QMouseEvent*\0event\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExQTabWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x05,
       5,    1,   27,    2, 0x05,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void ExQTabWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ExQTabWidget *_t = static_cast<ExQTabWidget *>(_o);
        switch (_id) {
        case 0: _t->keyPressed((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 1: _t->mousePressed((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ExQTabWidget::*_t)(QKeyEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ExQTabWidget::keyPressed)) {
                *result = 0;
            }
        }
        {
            typedef void (ExQTabWidget::*_t)(QMouseEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ExQTabWidget::mousePressed)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject ExQTabWidget::staticMetaObject = {
    { &QTabWidget::staticMetaObject, qt_meta_stringdata_ExQTabWidget.data,
      qt_meta_data_ExQTabWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *ExQTabWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExQTabWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ExQTabWidget.stringdata))
        return static_cast<void*>(const_cast< ExQTabWidget*>(this));
    return QTabWidget::qt_metacast(_clname);
}

int ExQTabWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ExQTabWidget::keyPressed(QKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ExQTabWidget::mousePressed(QMouseEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
