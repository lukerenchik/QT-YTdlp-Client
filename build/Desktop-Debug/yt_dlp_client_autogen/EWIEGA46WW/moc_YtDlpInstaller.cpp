/****************************************************************************
** Meta object code from reading C++ file 'YtDlpInstaller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.17)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../YtDlpInstaller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'YtDlpInstaller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.17. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_YtDlpInstaller_t {
    QByteArrayData data[8];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_YtDlpInstaller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_YtDlpInstaller_t qt_meta_stringdata_YtDlpInstaller = {
    {
QT_MOC_LITERAL(0, 0, 14), // "YtDlpInstaller"
QT_MOC_LITERAL(1, 15, 20), // "installationFinished"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 7), // "success"
QT_MOC_LITERAL(4, 45, 7), // "message"
QT_MOC_LITERAL(5, 53, 11), // "infoMessage"
QT_MOC_LITERAL(6, 65, 12), // "errorMessage"
QT_MOC_LITERAL(7, 78, 23) // "onYtDlpDownloadFinished"

    },
    "YtDlpInstaller\0installationFinished\0"
    "\0success\0message\0infoMessage\0errorMessage\0"
    "onYtDlpDownloadFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_YtDlpInstaller[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       5,    1,   39,    2, 0x06 /* Public */,
       6,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void YtDlpInstaller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<YtDlpInstaller *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->installationFinished((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->infoMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->errorMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->onYtDlpDownloadFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (YtDlpInstaller::*)(bool , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&YtDlpInstaller::installationFinished)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (YtDlpInstaller::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&YtDlpInstaller::infoMessage)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (YtDlpInstaller::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&YtDlpInstaller::errorMessage)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject YtDlpInstaller::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_YtDlpInstaller.data,
    qt_meta_data_YtDlpInstaller,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *YtDlpInstaller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *YtDlpInstaller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_YtDlpInstaller.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int YtDlpInstaller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void YtDlpInstaller::installationFinished(bool _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void YtDlpInstaller::infoMessage(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void YtDlpInstaller::errorMessage(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
