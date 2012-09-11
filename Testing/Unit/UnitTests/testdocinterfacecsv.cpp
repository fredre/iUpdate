#include "testdocinterfacecsv.h"

TestDocInterfaceCsv::TestDocInterfaceCsv(QObject *parent) :
    QObject(parent)
{
}


void TestDocInterfaceCsv::initTestCase()
{
   docInt = new DocInterface();
   docInt->setFilePath("../Test1.csv");
}

void TestDocInterfaceCsv::testloadFile()
{
   QCOMPARE(docInt->loadFile(),true);
}

 void TestDocInterfaceCsv::testgetSubjectCode()
 {
   QCOMPARE(QString(docInt->getSubjectCode()),QString("PGG311T"));
 }

 void TestDocInterfaceCsv::testgetFirstStudentNumber()
 {
     QCOMPARE(QString(docInt->getFirstStudentNumber()),QString("204041431"));
 }


void TestDocInterfaceCsv::cleanupTestCase()
{
    delete docInt;
}
