/****************************************************************************
** Meta object code from reading C++ file 'editdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SettingManager/editdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EditDialog_t {
    QByteArrayData data[11];
    char stringdata[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EditDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EditDialog_t qt_meta_stringdata_EditDialog = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 14),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 8),
QT_MOC_LITERAL(4, 36, 6),
QT_MOC_LITERAL(5, 43, 5),
QT_MOC_LITERAL(6, 49, 5),
QT_MOC_LITERAL(7, 55, 10),
QT_MOC_LITERAL(8, 66, 8),
QT_MOC_LITERAL(9, 75, 11),
QT_MOC_LITERAL(10, 87, 4)
    },
    "EditDialog\0dialogAccepted\0\0QString*\0"
    "_title\0_type\0_text\0_createnew\0Accepted\0"
    "textChanged\0text"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EditDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   38,    2, 0x08 /* Private */,
       9,    1,   39,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, 0x80000000 | 3, QMetaType::Bool,    4,    5,    6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,

       0        // eod
};

void EditDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EditDialog *_t = static_cast<EditDialog *>(_o);
        switch (_id) {
        case 0: _t->dialogAccepted((*reinterpret_cast< QString*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString*(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 1: _t->Accepted(); break;
        case 2: _t->textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (EditDialog::*_t)(QString * , int , QString * , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EditDialog::dialogAccepted)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject EditDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_EditDialog.data,
      qt_meta_data_EditDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *EditDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EditDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EditDialog.stringdata))
        return static_cast<void*>(const_cast< EditDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int EditDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void EditDialog::dialogAccepted(QString * _t1, int _t2, QString * _t3, bool _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
