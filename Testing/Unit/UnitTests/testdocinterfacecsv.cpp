#include "testdocinterfacecsv.h"

TestDocInterfaceCsv::TestDocInterfaceCsv(QObject *parent) :
    QObject(parent)
{
}


void TestDocInterfaceCsv::initTestCase()
{
   docInt = new DocInterface();
}

void TestDocInterfaceCsv::cleanupTestCase()
{
    delete docInt;
}
