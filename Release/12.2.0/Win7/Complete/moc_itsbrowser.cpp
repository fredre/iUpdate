/****************************************************************************
** Meta object code from reading C++ file 'itsbrowser.h'
**
** Created: Tue 8. May 21:30:09 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../IUpdate/itsbrowser.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'itsbrowser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_itsBrowser[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      45,   32,   11,   11, 0x0a,
      96,   94,   11,   11, 0x0a,
     150,   94,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_itsBrowser[] = {
    "itsBrowser\0\0onAnyError(QString)\0"
    "reply,errors\0"
    "handleSslErrors(QNetworkReply*,QList<QSslError>)\0"
    ",\0provideAuthentication(QNetworkReply*,QAuthenticator*)\0"
    "provideProxAuthentication(QNetworkProxy,QAuthenticator*)\0"
};

const QMetaObject itsBrowser::staticMetaObject = {
    { &QWebView::staticMetaObject, qt_meta_stringdata_itsBrowser,
      qt_meta_data_itsBrowser, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &itsBrowser::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *itsBrowser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *itsBrowser::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_itsBrowser))
        return static_cast<void*>(const_cast< itsBrowser*>(this));
    return QWebView::qt_metacast(_clname);
}

int itsBrowser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWebView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onAnyError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: handleSslErrors((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< const QList<QSslError>(*)>(_a[2]))); break;
        case 2: provideAuthentication((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< QAuthenticator*(*)>(_a[2]))); break;
        case 3: provideProxAuthentication((*reinterpret_cast< const QNetworkProxy(*)>(_a[1])),(*reinterpret_cast< QAuthenticator*(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void itsBrowser::onAnyError(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
