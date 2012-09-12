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
     QCOMPARE(QString(docInt->getFirstStudentNumber()),QString("96139802"));
 }

 void TestDocInterfaceCsv::testgetLastStudentNumber()
 {
   QCOMPARE(QString(docInt->getLastStudentNumber()),QString("211359803"));

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

 void TestDocInterfaceCsv::testgetMarkTypeColumn()
 {
    QCOMPARE(docInt->getMarkTypeColumn("A1"),1);
    QCOMPARE(docInt->getMarkTypeColumn("A3"),3);
    QCOMPARE(docInt->getMarkTypeColumn("A6"),6);
    QCOMPARE(docInt->getMarkTypeColumn("ST1"),9);
    QCOMPARE(docInt->getMarkTypeColumn("ST2"),10);
 }

 void TestDocInterfaceCsv::testgetMarkTypeTotalNumberMarks()
 {
     QCOMPARE(docInt->getMarkTypeTotalNumberMarks("A1"),35);
     QCOMPARE(docInt->getMarkTypeTotalNumberMarks("A2"),3);
     QCOMPARE(docInt->getMarkTypeTotalNumberMarks("A3"),1);
     QCOMPARE(docInt->getMarkTypeTotalNumberMarks("A4"),3);
     QCOMPARE(docInt->getMarkTypeTotalNumberMarks("A5"),6);
     QCOMPARE(docInt->getMarkTypeTotalNumberMarks("A6"),6);
     QCOMPARE(docInt->getMarkTypeTotalNumberMarks("CT"),9);
     QCOMPARE(docInt->getMarkTypeTotalNumberMarks("PJ"),10);
     QCOMPARE(docInt->getMarkTypeTotalNumberMarks("ST1"),9);
     QCOMPARE(docInt->getMarkTypeTotalNumberMarks("ST2"),10);
 }

void TestDocInterfaceCsv::cleanupTestCase()
{
    delete docInt;
}
