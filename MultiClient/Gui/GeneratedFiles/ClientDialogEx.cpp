/****************************************************************************
** Meta object code from reading C++ file 'ClientDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ClientDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ClientDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Cry__ClientDialog_t {
    QByteArrayData data[13];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Cry__ClientDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Cry__ClientDialog_t qt_meta_stringdata_Cry__ClientDialog = {
    {
QT_MOC_LITERAL(0, 0, 17), // "Cry::ClientDialog"
QT_MOC_LITERAL(1, 18, 23), // "MultiDelegateConnection"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 3), // "u32"
QT_MOC_LITERAL(4, 47, 5), // "Index"
QT_MOC_LITERAL(5, 53, 6), // "Status"
QT_MOC_LITERAL(6, 60, 17), // "DelegateSignInMsg"
QT_MOC_LITERAL(7, 78, 4), // "uMsg"
QT_MOC_LITERAL(8, 83, 11), // "std::string"
QT_MOC_LITERAL(9, 95, 4), // "Text"
QT_MOC_LITERAL(10, 100, 3), // "uid"
QT_MOC_LITERAL(11, 104, 7), // "expires"
QT_MOC_LITERAL(12, 112, 19) // "DelegateRegisterMsg"

    },
    "Cry::ClientDialog\0MultiDelegateConnection\0"
    "\0u32\0Index\0Status\0DelegateSignInMsg\0"
    "uMsg\0std::string\0Text\0uid\0expires\0"
    "DelegateRegisterMsg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Cry__ClientDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,
       6,    4,   34,    2, 0x06 /* Public */,
      12,    3,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,
    QMetaType::Bool, 0x80000000 | 3, 0x80000000 | 8, 0x80000000 | 3, 0x80000000 | 3,    7,    9,   10,   11,
    QMetaType::Bool, 0x80000000 | 3, 0x80000000 | 8, 0x80000000 | 3,    7,    9,   10,

       0        // eod
};

void Cry::ClientDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClientDialog *_t = static_cast<ClientDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->MultiDelegateConnection((*reinterpret_cast< const u32(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: { bool _r = _t->DelegateSignInMsg((*reinterpret_cast< const u32(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2])),(*reinterpret_cast< const u32(*)>(_a[3])),(*reinterpret_cast< const u32(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: { bool _r = _t->DelegateRegisterMsg((*reinterpret_cast< const u32(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2])),(*reinterpret_cast< const u32(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ClientDialog::*_t)(const u32 , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientDialog::MultiDelegateConnection)) {
                *result = 0;
                return;
            }
        }
        {
            typedef bool (ClientDialog::*_t)(const u32 , const std::string & , const u32 , const u32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientDialog::DelegateSignInMsg)) {
                *result = 1;
                return;
            }
        }
        {
            typedef bool (ClientDialog::*_t)(const u32 , const std::string & , const u32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientDialog::DelegateRegisterMsg)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Cry::ClientDialog::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Cry__ClientDialog.data,
      qt_meta_data_Cry__ClientDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Cry::ClientDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Cry::ClientDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Cry__ClientDialog.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Cry::ClientDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
void Cry::ClientDialog::MultiDelegateConnection(const u32 _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
bool Cry::ClientDialog::DelegateSignInMsg(const u32 _t1, const std::string & _t2, const u32 _t3, const u32 _t4)
{
    bool _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}

// SIGNAL 2
bool Cry::ClientDialog::DelegateRegisterMsg(const u32 _t1, const std::string & _t2, const u32 _t3)
{
    bool _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
    return _t0;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
