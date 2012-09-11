#include "docinterface.h"

DocInterface::DocInterface(QObject *parent) :
    QObject(parent)
{

}

QString DocInterface::FilePath()
{
    return filepath;
}

void DocInterface::setFilePath(QString fp)
{
    filepath = fp;


}

bool DocInterface::loadFile()
{
    if(filepath.isNull())
    {
        return false;
    }

        QFile file(filepath);

        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            //Clear file contents
            filecontents.clear();

            while (!file.atEnd())
            {
                QString line = file.readLine();
                line = line.trimmed();
                filecontents.append(line);
                qDebug()<<line;
            }
            file.close();
            return true;
        }
        else
        {
            return false;
        }
}

 QString DocInterface::getFileExt()
 {
     return "CSV Files (*.csv)";
 }

  QString  DocInterface::getFileTypeName()
  {
      return "CSV";
  }

  QString DocInterface::getSubjectCode()
  {
      QString scode;
      scode = filecontents[0];
      return scode.split(',')[0];
  }

  QString DocInterface::getFirstStudentNumber()
  {
      QString snum = filecontents[3];
      return snum.split(',')[0];
  }

  QString DocInterface::getLastStudentNumber()
  {

      for(int a=filecontents.count()-1;a>=0;a--)
      {
        if(filecontents[a].split(',')[0]=="END")
       {
        return filecontents[a-1].split(',')[0];
       }
      }
  }

  int  DocInterface::getStudentCount()
  {
      for(int a=filecontents.count()-1;a>=0;a--)
      {
         if(filecontents[a].split(',')[0]=="END")
          {
           return (a-3);
          }
      }
  }

QStringList DocInterface::getMarkTypesList()
{
   QString mtypes =filecontents[2];
   QStringList mtypesSp = mtypes.split(',');

  mtypesSp.removeAt(0);

 return mtypesSp;
}

 int DocInterface::getMarkTypeColumn(QString mt)
 {
     //Will return the coloumn number of the marktype
     QStringList mtypesall = filecontents[2].split(',');
     int loc;

     for(int a=0;a<mtypesall.count();a++)
     {
       if(mtypesall[a]==mt)
       {
           loc =a;
           qDebug()<<"Mark type found "<<mt<<" location "<<loc;
       }
     }

     return loc;
 }


int DocInterface::getMarkTypeTotalNumberMarks(QString mt)
{
    //Return the total ammount of marks for the marktype

    int totamt=0;

   QMap<QString, int> allMarks = getAllMarksPerMarkType(mt);


    //loop over all marks and get the mark count for this marktype
   QMap<QString, int>::const_iterator i = allMarks.constBegin();
    while (i != allMarks.constEnd()) {
        if(i.value()!=0)
        {
          totamt++;
           qDebug()<<"Ammount "<<totamt << "of marks incremented for mark "<<i.value()<<"Marktype "<<mt<<" student number"<<i.key();
       }
           ++i;
    }

    return totamt;
}

QMap<QString, int> DocInterface::getAllMarksPerMarkType(QString mt)
{
   QMap<QString, int> allMarks;

   int loc = getMarkTypeColumn(mt);

   for(int a=3;a<filecontents.count()-1;a++)
   {
       QStringList line = filecontents[a].split(','); //Split the mark line into sperate marks
       QString mark = line[loc]; //Get only the mark for the marktype specified by arg mt
       QString snum = line[0]; //Get the student number

       allMarks.insert(snum,mark.toInt());

   }
 return allMarks;
}

QStringList DocInterface::getAllStudentNumbersPerMarkType(QString mt)
{
    QMap<QString, int> allMarks = getAllMarksPerMarkType(mt);

    QStringList snums;

    QMap<QString, int>::const_iterator i = allMarks.constBegin();
     while (i != allMarks.constEnd()) {
         snums.append(i.key());
         ++i;
     }

     return snums;
}

int DocInterface::getStudentMarkPerMarkType(QString mt,QString stunum)
{
   QMap<QString, int> allMarks = getAllMarksPerMarkType(mt);

   QMap<QString, int>::const_iterator i = allMarks.constBegin();
    while (i != allMarks.constEnd()) {
        if(i.key()==stunum)
        {
         return i.value();
        }
        ++i;
    }
}

 QStringList DocInterface::getStudentNumbersWithNoMark(QString mt)
 {

 QMap<QString, int> allMarks = getAllMarksPerMarkType(mt);

 QStringList nomarks;

 QMap<QString, int>::const_iterator i = allMarks.constBegin();
  while (i != allMarks.constEnd()) {
      if(i.value()==0)
      {
        nomarks.append(i.key());
     }
         ++i;
  }

    return nomarks;

 }

 int DocInterface::getMarkTypesCount()
 {
     return getMarkTypesList().count();
 }
