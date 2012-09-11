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

 void TestDocInterfaceCsv::testgetLastStudentNumber()
 {
   QCOMPARE(QString(docInt->getLastStudentNumber()),QString("210172149"));

   //QBENCHMARK { docInt->getLastStudentNumber(); }
 }

 void TestDocInterfaceCsv::testgetStudentCount()
 {
    QCOMPARE(docInt->getStudentCount(),46);

    //QBENCHMARK { docInt->getStudentCount(); }
 }

 void TestDocInterfaceCsv::testgetMarkTypesList()
 {
     QStringList fromfile = docInt->getMarkTypesList();

     QStringList correct;  //A1,A2,A3,A4,A5,A6,CT,PJ,ST1,ST2
     correct.append("A1");
     correct.append("A2");
     correct.append("A3");
     correct.append("A4");
     correct.append("A5");
     correct.append("A6");
     correct.append("CT");
     correct.append("PJ");
     correct.append("ST1");
     correct.append("ST2");

     QCOMPARE(fromfile,correct);
 }

void TestDocInterfaceCsv::cleanupTestCase()
{
    delete docInt;
}
