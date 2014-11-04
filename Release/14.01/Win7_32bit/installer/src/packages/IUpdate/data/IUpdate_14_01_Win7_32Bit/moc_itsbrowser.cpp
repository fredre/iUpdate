/****************************************************************************
** Meta object code from reading C++ file 'itsbrowser.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../iUpdateLocaltoHub/itsbrowser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'itsbrowser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_itsBrowser_t {
    QByteArrayData data[14];
    char stringdata[198];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_itsBrowser_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_itsBrowser_t qt_meta_stringdata_itsBrowser = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 10),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 14),
QT_MOC_LITERAL(4, 38, 15),
QT_MOC_LITERAL(5, 54, 14),
QT_MOC_LITERAL(6, 69, 5),
QT_MOC_LITERAL(7, 75, 16),
QT_MOC_LITERAL(8, 92, 6),
QT_MOC_LITERAL(9, 99, 21),
QT_MOC_LITERAL(10, 121, 15),
QT_MOC_LITERAL(11, 137, 25),
QT_MOC_LITERAL(12, 163, 13),
QT_MOC_LITERAL(13, 177, 19)
    },
    "itsBrowser\0onAnyError\0\0OnNetworkError\0"
    "handleSslErrors\0QNetworkReply*\0reply\0"
    "QList<QSslError>\0errors\0ProvideAuthentication\0"
    "QAuthenticator*\0ProvideProxAuthentication\0"
    "QNetworkProxy\0NetworkTaskfinished\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_itsBrowser[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06,
       3,    1,   47,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    2,   50,    2, 0x0a,
       9,    2,   55,    2, 0x0a,
      11,    2,   60,    2, 0x0a,
      13,    1,   65,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 7,    6,    8,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 10,    2,    2,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 10,    2,    2,
    QMetaType::Void, 0x80000000 | 5,    2,

       0        // eod
};

void itsBrowser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        itsBrowser *_t = static_cast<itsBrowser *>(_o);
        switch (_id) {
        case 0: _t->onAnyError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->OnNetworkError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->handleSslErrors((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< const QList<QSslError>(*)>(_a[2]))); break;
        case 3: _t->ProvideAuthentication((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< QAuthenticator*(*)>(_a[2]))); break;
        case 4: _t->ProvideProxAuthentication((*reinterpret_cast< const QNetworkProxy(*)>(_a[1])),(*reinterpret_cast< QAuthenticator*(*)>(_a[2]))); break;
        case 5: _t->NetworkTaskfinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QSslError> >(); break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkProxy >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (itsBrowser::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&itsBrowser::onAnyError)) {
                *result = 0;
            }
        }
        {
            typedef void (itsBrowser::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&itsBrowser::OnNetworkError)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject itsBrowser::staticMetaObject = {
    { &QWebView::staticMetaObject, qt_meta_stringdata_itsBrowser.data,
      qt_meta_data_itsBrowser,  qt_static_metacall, 0, 0}
};


const QMetaObject *itsBrowser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *itsBrowser::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_itsBrowser.stringdata))
        return static_cast<void*>(const_cast< itsBrowser*>(this));
    return QWebView::qt_metacast(_clname);
}

int itsBrowser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWebView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void itsBrowser::onAnyError(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void itsBrowser::OnNetworkError(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
