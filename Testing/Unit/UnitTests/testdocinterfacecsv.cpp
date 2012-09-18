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
     QCOMPARE(docInt->getMarkTypeTotalNumberMarks("A6"),20);
     QCOMPARE(docInt->getMarkTypeTotalNumberMarks("CT"),39);
     QCOMPARE(docInt->getMarkTypeTotalNumberMarks("PJ"),30);
     QCOMPARE(docInt->getMarkTypeTotalNumberMarks("ST1"),40);
     QCOMPARE(docInt->getMarkTypeTotalNumberMarks("ST2"),30);
 }

void TestDocInterfaceCsv::testgetAllMarksPerMarkType()
{
     QMap<QString, int> allMarksFromFileProgA1;

     allMarksFromFileProgA1 = docInt->getAllMarksPerMarkType("A1");

     QMap<QString, int> allMarksFromFileA1;

     allMarksFromFileA1["96139802"]=	0;
     allMarksFromFileA1["200300400"]=	80;
     allMarksFromFileA1["204041431"]=	0;
     allMarksFromFileA1["204116415"]=	87;
     allMarksFromFileA1["206223529"]=	0;
     allMarksFromFileA1["207161292"]=	0;
     allMarksFromFileA1["208094416"]=	80;
     allMarksFromFileA1["208128906"]=	7;
     allMarksFromFileA1["208213172"]=	80;
     allMarksFromFileA1["209068559"]=	87;
     allMarksFromFileA1["209071641"]=	7;
     allMarksFromFileA1["209088398"]=	87;
     allMarksFromFileA1["209089955"]=	90;
     allMarksFromFileA1["209112027"]=	80;
     allMarksFromFileA1["209243733"]=	7;
     allMarksFromFileA1["209253754"]=	7;
     allMarksFromFileA1["209261286"]=	93;
     allMarksFromFileA1["209295741"]=	0;
     allMarksFromFileA1["209296276"]=	0;
     allMarksFromFileA1["209313391"]=	93;
     allMarksFromFileA1["209331519"]=	0;
     allMarksFromFileA1["210008420"]=	93;
     allMarksFromFileA1["210060758"]=	87;
     allMarksFromFileA1["210062270"]=	93;
     allMarksFromFileA1["210098780"]=	87;
     allMarksFromFileA1["210100687"]=	100;
     allMarksFromFileA1["210128506"]=	63;
     allMarksFromFileA1["210172149"]=	100;
     allMarksFromFileA1["210242775"]=	87;
     allMarksFromFileA1["210244174"]=	77;
     allMarksFromFileA1["210265899"]=	0;
     allMarksFromFileA1["210276165"]=	93;
     allMarksFromFileA1["210284036"]=	87;
     allMarksFromFileA1["210284893"]=	87;
     allMarksFromFileA1["210287051"]=	100;
     allMarksFromFileA1["210297626"]=	77;
     allMarksFromFileA1["210301607"]=	0;
     allMarksFromFileA1["210309802"]=	80;
     allMarksFromFileA1["210327100"]=	0;
     allMarksFromFileA1["211039884"]=	73;
     allMarksFromFileA1["211089520"]=	53;
     allMarksFromFileA1["211242523"]=	83;
     allMarksFromFileA1["211247703"]=	73;
     allMarksFromFileA1["211316187"]=	93;
     allMarksFromFileA1["211359803"]=	80;

    QCOMPARE(allMarksFromFileA1,allMarksFromFileProgA1);
    QCOMPARE(allMarksFromFileProgA1.count(),docInt->getStudentCount());

    //Add the rest...


     QMap<QString, int> allMarksFromFileA6;

     allMarksFromFileA6 = docInt->getAllMarksPerMarkType("A6");
     QCOMPARE(allMarksFromFileA6.count(),docInt->getStudentCount());

     QMap<QString, int> allMarksFromFileST2;

     allMarksFromFileST2 = docInt->getAllMarksPerMarkType("ST2");
     QCOMPARE(allMarksFromFileST2.count(),docInt->getStudentCount());

}

void TestDocInterfaceCsv::testgetAllStudentNumbersPerMarkType()
{
    QStringList FromFile = docInt->getAllStudentNumbersPerMarkType("CT");

    QStringList FromTpye;

    FromTpye<<"200300400" <<"204041431"<<"204116415"<< "206223529"<<"207161292"<<"208094416"<<"208128906"<<"208213172"<<"209068559"<<"209071641"<<"209088398"<<"209089955"<<"209112027"<< "209243733"<< "209253754"<< "209261286"<< "209295741"<< "209296276"<< "209313391"<< "209331519"<< "210008420"<< "210060758"<< "210062270"<< "210098780"<< "210100687"<< "210128506"<< "210172149"<< "210242775"<< "210244174"<< "210265899"<< "210276165"<< "210284036"<< "210284893"<< "210287051"<< "210297626"<< "210301607"<< "210309802"<< "210327100"<< "211039884"<< "211089520"<< "211242523"<< "211247703"<< "211316187"<< "211359803"<< "96139802";

    QCOMPARE(FromFile,FromTpye);
}

 void TestDocInterfaceCsv::testgetStudentMarkPerMarkType_data()
 {

     QTest::addColumn<QString>("StudentNumber");
     QTest::addColumn<QString>("MarkType");
     QTest::addColumn<int>("MarkExpected");

     QTest::newRow("Test1") << "209068559"<<"A1"<<87;
     QTest::newRow("Test2") << "209068559"<<"A2"<<77;
     QTest::newRow("Test3") << "209068559"<<"A3"<<86;
     QTest::newRow("Test4") << "209068559"<<"A4"<<0;
     QTest::newRow("Test5") << "209068559"<<"A5"<<93;
     QTest::newRow("Test6") << "209068559"<<"A6"<<0;
     QTest::newRow("Test7") << "209068559"<<"CT"<<50;
     QTest::newRow("Test8") << "209068559"<<"PJ"<<77;
     QTest::newRow("Test9") << "209068559"<<"ST1"<<40;
     QTest::newRow("Test10") << "209068559"<<"ST2"<<29;

 }

void TestDocInterfaceCsv::testgetStudentMarkPerMarkType()
{
    QFETCH(QString, StudentNumber);
    QFETCH(QString, MarkType);
    QFETCH(int, MarkExpected);


    QCOMPARE(docInt->getStudentMarkPerMarkType(MarkType,StudentNumber), MarkExpected);

}

 void TestDocInterfaceCsv::testgetStudentNumbersWithNoMark()
 {
     QStringList nomarkcs = docInt->getStudentNumbersWithNoMark("A5");

     QStringList selfde;

     selfde<<"200300400" <<"204116415"<< "207161292"<< "208094416"<< "209071641"<< "209088398"<< "209243733"<< "209253754"<< "209295741"<< "209296276"<< "210008420"<< "210062270"<< "210128506"<< "210265899"<< "210276165"<< "210284893"<< "210287051"<< "210301607";

     QCOMPARE(nomarkcs,selfde);
 }

void TestDocInterfaceCsv::cleanupTestCase()
{
    delete docInt;
}
