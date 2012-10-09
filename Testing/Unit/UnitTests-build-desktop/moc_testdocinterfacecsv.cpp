/****************************************************************************
** Meta object code from reading C++ file 'testdocinterfacecsv.h'
**
** Created: Tue Sep 18 11:45:23 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../UnitTests/testdocinterfacecsv.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testdocinterfacecsv.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TestDocInterfaceCsv[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x08,
      36,   20,   20,   20, 0x08,
      51,   20,   20,   20, 0x08,
      72,   20,   20,   20, 0x08,
     100,   20,   20,   20, 0x08,
     127,   20,   20,   20, 0x08,
     149,   20,   20,   20, 0x08,
     172,   20,   20,   20, 0x08,
     196,   20,   20,   20, 0x08,
     224,   20,   20,   20, 0x08,
     259,   20,   20,   20, 0x08,
     293,   20,   20,   20, 0x08,
     322,   20,   20,   20, 0x08,
     360,   20,   20,   20, 0x08,
     392,   20,   20,   20, 0x08,
     429,   20,   20,   20, 0x08,
     463,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TestDocInterfaceCsv[] = {
    "TestDocInterfaceCsv\0\0initTestCase()\0"
    "testloadFile()\0testgetSubjectCode()\0"
    "testgetFirstStudentNumber()\0"
    "testgetLastStudentNumber()\0"
    "testgetStudentCount()\0testgetMarkTypesList()\0"
    "testgetMarkTypeColumn()\0"
    "testvalidateStudentNumber()\0"
    "testcheckDuplicateStudentNumbers()\0"
    "testgetMarkTypeTotalNumberMarks()\0"
    "testgetAllMarksPerMarkType()\0"
    "testgetAllStudentNumbersPerMarkType()\0"
    "testgetStudentMarkPerMarkType()\0"
    "testgetStudentMarkPerMarkType_data()\0"
    "testgetStudentNumbersWithNoMark()\0"
    "cleanupTestCase()\0"
};

const QMetaObject TestDocInterfaceCsv::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TestDocInterfaceCsv,
      qt_meta_data_TestDocInterfaceCsv, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TestDocInterfaceCsv::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TestDocInterfaceCsv::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TestDocInterfaceCsv::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TestDocInterfaceCsv))
        return static_cast<void*>(const_cast< TestDocInterfaceCsv*>(this));
    return QObject::qt_metacast(_clname);
}

int TestDocInterfaceCsv::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: initTestCase(); break;
        case 1: testloadFile(); break;
        case 2: testgetSubjectCode(); break;
        case 3: testgetFirstStudentNumber(); break;
        case 4: testgetLastStudentNumber(); break;
        case 5: testgetStudentCount(); break;
        case 6: testgetMarkTypesList(); break;
        case 7: testgetMarkTypeColumn(); break;
        case 8: testvalidateStudentNumber(); break;
        case 9: testcheckDuplicateStudentNumbers(); break;
        case 10: testgetMarkTypeTotalNumberMarks(); break;
        case 11: testgetAllMarksPerMarkType(); break;
        case 12: testgetAllStudentNumbersPerMarkType(); break;
        case 13: testgetStudentMarkPerMarkType(); break;
        case 14: testgetStudentMarkPerMarkType_data(); break;
        case 15: testgetStudentNumbersWithNoMark(); break;
        case 16: cleanupTestCase(); break;
        default: ;
        }
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
