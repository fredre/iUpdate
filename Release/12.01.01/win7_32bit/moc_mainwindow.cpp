/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Mon 7. May 18:24:37 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../IUpdate/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      45,   36,   11,   11, 0x08,
      81,   11,   11,   11, 0x08,
     113,   11,   11,   11, 0x08,
     150,   11,   11,   11, 0x08,
     186,   11,   11,   11, 0x08,
     213,   11,   11,   11, 0x08,
     243,   11,   11,   11, 0x08,
     269,   11,   11,   11, 0x08,
     291,   11,   11,   11, 0x08,
     325,   11,   11,   11, 0x08,
     357,   11,   11,   11, 0x08,
     391,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_pushButton_clicked()\0"
    "progress\0on_webViewBrowser_loadProgress(int)\0"
    "on_webViewBrowser_loadStarted()\0"
    "on_webViewBrowser_loadFinished(bool)\0"
    "on_webViewBrowser_anyError(QString)\0"
    "on_actionAbout_triggered()\0"
    "on_actionAbout_QT_triggered()\0"
    "on_actionLoad_triggered()\0"
    "PopulateSubjectGrid()\0"
    "on_pushButtonUpdateMrks_clicked()\0"
    "on_actionMake_all_0_triggered()\0"
    "on_actionMake_empty_0_triggered()\0"
    "on_actionBlackout_Cancelled_triggered()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pushButton_clicked(); break;
        case 1: on_webViewBrowser_loadProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: on_webViewBrowser_loadStarted(); break;
        case 3: on_webViewBrowser_loadFinished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: on_webViewBrowser_anyError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: on_actionAbout_triggered(); break;
        case 6: on_actionAbout_QT_triggered(); break;
        case 7: on_actionLoad_triggered(); break;
        case 8: PopulateSubjectGrid(); break;
        case 9: on_pushButtonUpdateMrks_clicked(); break;
        case 10: on_actionMake_all_0_triggered(); break;
        case 11: on_actionMake_empty_0_triggered(); break;
        case 12: on_actionBlackout_Cancelled_triggered(); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
