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
    QCOMPARE(docInt->getStudentCount(),45);

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

 void TestDocInterfaceCsv::testvalidateStudentNumber()
 {
  QCOMPARE(docInt->validateStudentNumber("204063982"),true);
  //Also sanitize
  QString teststu = "204063982 ";
  docInt->sanitizeString(teststu);
  QCOMPARE(docInt->validateStudentNumber(teststu),true);

  teststu = " 204063982 ";
  docInt->sanitizeString(teststu);
  QCOMPARE(docInt->validateStudentNumber(teststu),true);

  teststu ="204063982 " ;
  docInt->sanitizeString(teststu);
  QCOMPARE(docInt->validateStudentNumber(teststu),true);

  QCOMPARE(docInt->validateStudentNumber("96139802"),true);
  QCOMPARE(docInt->validateStudentNumber("2000000000"),false);
  QCOMPARE(docInt->validateStudentNumber("010"),false);
  QCOMPARE(docInt->validateStudentNumber("2040 8762"),false);
  QCOMPARE(docInt->validateStudentNumber("20406398w"),false);
 }

 void TestDocInterfaceCsv::testcheckDuplicateStudentNumbers()
 {
    QStringList a;
    a.append("204063982");
    a.append("204063482");
    a.append("504063782");
    a.append("204063982");

    QCOMPARE(docInt->checkDuplicateStudentNumbers(a),false);

    QStringList ab;
    a.append("204063982");
    a.append("204053482");
    a.append("504063782");
    a.append("203063982");


    QCOMPARE(docInt->checkDuplicateStudentNumbers(ab),true);
 }

 void TestDocInterfaceCsv::testgetMarkTypeTotalNumberMarks()
 {
     QCOMPARE(docInt->getMarkTypeTotalNumberMarks("A1"),35);
     QCOMPARE(docInt->getMarkTypeTotalNumberMarks("A2"),36);
     QCOMPARE(docInt->getMarkTypeTotalNumberMarks("A3"),39);
     QCOMPARE(docInt->getMarkTypeTotalNumberMarks("A4"),32);
     QCOMPARE(docInt->getMarkTypeTotalNumberMarks("A5"),27);
     QCOMPARE(docInt->getMarkTypeTotalNumberMarks("A6"),21);
     QCOMPARE(docInt->getMarkTypeTotalNumberMarks("CT"),39);
     QCOMPARE(docInt->getMarkTypeTotalNumberMarks("PJ"),30);
     QCOMPARE(docInt->getMarkTypeTotalNumberMarks("ST1"),40);
     QCOMPARE(docInt->getMarkTypeTotalNumberMarks("ST2"),30);
 }

void TestDocInterfaceCsv::testgetAllMarksPerMarkType()
{
     QMap<QString, int> allMarksFromFileA1;

     allMarksFromFileA1 = docInt->getAllMarksPerMarkType("A1");

     QMap<QString, int> allMarksFromFileA6;

     allMarksFromFileA6 = docInt->getAllMarksPerMarkType("A6");

     QMap<QString, int> allMarksFromFileST2;

     allMarksFromFileST2 = docInt->getAllMarksPerMarkType("ST2");

     qDebug()<<allMarksFromFileA1.count();


}

void TestDocInterfaceCsv::cleanupTestCase()
{
    delete docInt;
}
