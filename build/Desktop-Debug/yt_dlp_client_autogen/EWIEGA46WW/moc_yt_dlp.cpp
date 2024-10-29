/****************************************************************************
** Meta object code from reading C++ file 'yt_dlp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.17)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../yt_dlp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'yt_dlp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.17. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_yt_dlp_t {
    QByteArrayData data[17];
    char stringdata0[253];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_yt_dlp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_yt_dlp_t qt_meta_stringdata_yt_dlp = {
    {
QT_MOC_LITERAL(0, 0, 6), // "yt_dlp"
QT_MOC_LITERAL(1, 7, 21), // "on_saveButton_clicked"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 19), // "on_dlButton_clicked"
QT_MOC_LITERAL(4, 50, 18), // "onDownloadFinished"
QT_MOC_LITERAL(5, 69, 7), // "success"
QT_MOC_LITERAL(6, 77, 7), // "message"
QT_MOC_LITERAL(7, 85, 16), // "onProgressUpdate"
QT_MOC_LITERAL(8, 102, 10), // "percentage"
QT_MOC_LITERAL(9, 113, 9), // "totalSize"
QT_MOC_LITERAL(10, 123, 5), // "speed"
QT_MOC_LITERAL(11, 129, 3), // "eta"
QT_MOC_LITERAL(12, 133, 13), // "onInfoMessage"
QT_MOC_LITERAL(13, 147, 14), // "onErrorMessage"
QT_MOC_LITERAL(14, 162, 41), // "on_actionSelectYtDlpInstallPa..."
QT_MOC_LITERAL(15, 204, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(16, 229, 23) // "on_actionHelp_triggered"

    },
    "yt_dlp\0on_saveButton_clicked\0\0"
    "on_dlButton_clicked\0onDownloadFinished\0"
    "success\0message\0onProgressUpdate\0"
    "percentage\0totalSize\0speed\0eta\0"
    "onInfoMessage\0onErrorMessage\0"
    "on_actionSelectYtDlpInstallPath_triggered\0"
    "on_actionAbout_triggered\0"
    "on_actionHelp_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_yt_dlp[] = {

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
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    2,   61,    2, 0x08 /* Private */,
       7,    4,   66,    2, 0x08 /* Private */,
      12,    1,   75,    2, 0x08 /* Private */,
      13,    1,   78,    2, 0x08 /* Private */,
      14,    0,   81,    2, 0x08 /* Private */,
      15,    0,   82,    2, 0x08 /* Private */,
      16,    0,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    5,    6,
    QMetaType::Void, QMetaType::Double, QMetaType::QString, QMetaType::QString, QMetaType::QString,    8,    9,   10,   11,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void yt_dlp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<yt_dlp *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_saveButton_clicked(); break;
        case 1: _t->on_dlButton_clicked(); break;
        case 2: _t->onDownloadFinished((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->onProgressUpdate((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 4: _t->onInfoMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->onErrorMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_actionSelectYtDlpInstallPath_triggered(); break;
        case 7: _t->on_actionAbout_triggered(); break;
        case 8: _t->on_actionHelp_triggered(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject yt_dlp::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_yt_dlp.data,
    qt_meta_data_yt_dlp,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *yt_dlp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *yt_dlp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_yt_dlp.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int yt_dlp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
