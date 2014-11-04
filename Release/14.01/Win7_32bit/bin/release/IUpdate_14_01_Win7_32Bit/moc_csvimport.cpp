/****************************************************************************
** Meta object code from reading C++ file 'csvimport.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../iUpdateLocaltoHub/csvimport.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'csvimport.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CSVImport_t {
    QByteArrayData data[20];
    char stringdata[413];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CSVImport_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CSVImport_t qt_meta_stringdata_CSVImport = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 13),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 14),
QT_MOC_LITERAL(4, 40, 12),
QT_MOC_LITERAL(5, 53, 24),
QT_MOC_LITERAL(6, 78, 11),
QT_MOC_LITERAL(7, 90, 8),
QT_MOC_LITERAL(8, 99, 4),
QT_MOC_LITERAL(9, 104, 9),
QT_MOC_LITERAL(10, 114, 18),
QT_MOC_LITERAL(11, 133, 39),
QT_MOC_LITERAL(12, 173, 3),
QT_MOC_LITERAL(13, 177, 25),
QT_MOC_LITERAL(14, 203, 22),
QT_MOC_LITERAL(15, 226, 43),
QT_MOC_LITERAL(16, 270, 47),
QT_MOC_LITERAL(17, 318, 39),
QT_MOC_LITERAL(18, 358, 18),
QT_MOC_LITERAL(19, 377, 34)
    },
    "CSVImport\0JSonGenerated\0\0QJsonDocument*\0"
    "generatedDoc\0on_action_Open_triggered\0"
    "checkString\0QString&\0temp\0character\0"
    "on_btnOpen_clicked\0"
    "on_tableView_customContextMenuRequested\0"
    "pos\0customHeaderMenuRequested\0"
    "customRowMenuRequested\0"
    "on_actionSet_cell_as_subject_name_triggered\0"
    "on_actionSet_as_student_number_colomn_triggered\0"
    "on_actionSet_as_mark_type_row_triggered\0"
    "on_btnDone_clicked\0"
    "on_actionSet_as_last_row_triggered\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CSVImport[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       5,    0,   82,    2, 0x08,
       6,    2,   83,    2, 0x08,
       6,    1,   88,    2, 0x28,
      10,    0,   91,    2, 0x08,
      11,    1,   92,    2, 0x08,
      13,    1,   95,    2, 0x08,
      14,    1,   98,    2, 0x08,
      15,    0,  101,    2, 0x08,
      16,    0,  102,    2, 0x08,
      17,    0,  103,    2, 0x08,
      18,    0,  104,    2, 0x08,
      19,    0,  105,    2, 0x08,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, QMetaType::QChar,    8,    9,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   12,
    QMetaType::Void, QMetaType::QPoint,   12,
    QMetaType::Void, QMetaType::QPoint,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CSVImport::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CSVImport *_t = static_cast<CSVImport *>(_o);
        switch (_id) {
        case 0: _t->JSonGenerated((*reinterpret_cast< QJsonDocument*(*)>(_a[1]))); break;
        case 1: _t->on_action_Open_triggered(); break;
        case 2: _t->checkString((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QChar(*)>(_a[2]))); break;
        case 3: _t->checkString((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->on_btnOpen_clicked(); break;
        case 5: _t->on_tableView_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 6: _t->customHeaderMenuRequested((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 7: _t->customRowMenuRequested((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 8: _t->on_actionSet_cell_as_subject_name_triggered(); break;
        case 9: _t->on_actionSet_as_student_number_colomn_triggered(); break;
        case 10: _t->on_actionSet_as_mark_type_row_triggered(); break;
        case 11: _t->on_btnDone_clicked(); break;
        case 12: _t->on_actionSet_as_last_row_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CSVImport::*_t)(QJsonDocument * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSVImport::JSonGenerated)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject CSVImport::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CSVImport.data,
      qt_meta_data_CSVImport,  qt_static_metacall, 0, 0}
};


const QMetaObject *CSVImport::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CSVImport::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CSVImport.stringdata))
        return static_cast<void*>(const_cast< CSVImport*>(this));
    return QDialog::qt_metacast(_clname);
}

int CSVImport::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void CSVImport::JSonGenerated(QJsonDocument * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
