#include "docinterface.h"


DocInterface::DocInterface( QObject *parent ) :
QObject( parent )
{

}

void DocInterface::sanitizeString(QString &needsSanitation)
{
    //Remove ""
  if(needsSanitation.contains('"'))
  {
    needsSanitation.replace('"',"");
  }

  //Sometimes I feel the campus needsSanitation ;P

  //Trimmerd
  needsSanitation = needsSanitation.simplified();
  needsSanitation = needsSanitation.trimmed();

}

bool DocInterface::validateStudentNumber( QString number )
{
   //False trap to check


    if( number.length()>=10 )
    {
        emit FileParseError( QString( "Invalid student number found. Student number %1 has more then 9 digits" ).arg( number ) );
        qDebug()<<QString( "Invalid student number found. Student number %1 has more then 9 digits" ).arg( number );
        return false;
    }


    if( number.length()<=7 )
    {
       emit FileParseError( QString( "Invalid student number found. Student number %1 has less then 8 digits" ).arg( number ));
       qDebug()<<QString( "Invalid student number found. Student number %1 has less then 8 digits" ).arg( number );
       return false;
    }

     QIntValidator v( 00000001, 999999999, this );
     int pos=0;

     if( v.validate( number,pos ) == QValidator::Invalid )
     {

      emit FileParseError( QString( "Invalid student number found. Student number %1 does not consist of all numbers or contains spaces." ).arg( number ) );
      qDebug()<<QString( "Invalid student number found. Student number %1 does not consist of all numbers or contains spaces." ).arg( number );

      return false;
     }

    return true;
}

QString DocInterface::FilePath()
{
    return filepath;
}

void DocInterface::SetFilePath( QString fp )
{
    filepath = fp;
}

void  DocInterface::LoadJsonDoc(QJsonDocument *thedoc)
{
  JDoc = thedoc;
  qDebug()<<JDoc->toJson();
}

bool DocInterface::LoadFile()
{
    if( filepath.isNull() )
    {
        return false;
    }

        QFile file( filepath );


        if ( file.open( QIODevice::ReadOnly | QIODevice::Text ) )
        {
            //Clear file contents
            filecontents.clear();

            while ( !file.atEnd() )
            {

                QString line = file.readLine();

                line = line.trimmed();
                filecontents.append( line );
                //qDebug()<<line;
            }
            file.close();
            return true;
        }
        else
        {
            return false;
        }
}

QString DocInterface::GetFileExt() {
     return "CSV Files (*.csv)";
 }

QString  DocInterface::GetFileTypeName() {
      return "CSV";
  }

QString DocInterface::GetSubjectCode() {
       QJsonObject json_O_mainObject(JDoc->object());
       QString scode = json_O_mainObject["SubjectName"].toString();
       sanitizeString( scode );
       return scode;
  }

int DocInterface::GetStudentCount() {

      QJsonObject json_O_mainObject(JDoc->object());

      QJsonArray json_A_stlist = json_O_mainObject["AllStudentNumbers"].toArray();

      //Also check for duplicate student numbers here
      QStringList allstuNums;
      foreach(const QJsonValue & value,json_A_stlist)
      {
          QString stu = value.toString();
          if(allstuNums.contains(stu))
          {
             emit FileParseError( QString ( "Duplicate student number found. %1 was found more then once" ).arg( stu ));
          }
          else
          {
              allstuNums.append(stu);
          }

      }

      int stuCount = json_A_stlist.size();

      return stuCount;
  }

QStringList DocInterface::GetMarkTypesList() {

    QStringList mtypesSp;

    QJsonObject json_O_mainObject(JDoc->object());

    QJsonArray json_A_mtlist = json_O_mainObject["AllMarkTypes"].toArray();

    foreach(const QJsonValue & value,json_A_mtlist)
    {
        QString mt = value.toString();
        mtypesSp.append(mt);
    }

  return mtypesSp;
}

int DocInterface::GetMarkTypeTotalNumberMarks( QString mt ){

    int totamt=0;

    QMap<QString, int> allMarks = GetAllMarksPerMarkType( mt );

    //loop over all marks and get the mark count for this marktype
   QMap<QString, int>::const_iterator i = allMarks.constBegin();

    while ( i != allMarks.constEnd() ) {


        if ( i.value()!=0 ) {
               totamt++;
        }

         ++i;

    }

    return totamt;
}

QMap<QString, int> DocInterface::GetAllMarksPerMarkType(QString mt){
   //This will return all marks from the file for the specified marktype. If the mark is empty or 0 the mark will still be returned

   QMap<QString, int> allMarks;


   QJsonObject json_O_mainObject(JDoc->object());

   QJsonObject json_O_mtObject = json_O_mainObject[mt].toObject(); //Get the object for the MT

   foreach(const QString & key,json_O_mtObject.keys()) //Key is the student number
   {
      QJsonValue oneMark = json_O_mtObject.value(key);

      if( allMarks.contains( key ) ) {
       emit FileParseError( QString ( "Duplicate student number found. %1 was found for mark type %2 more then once" ).arg( key ).arg( mt ));
      }

      //sanitizeString( &key );

      if(validateStudentNumber( key ))
      {
       allMarks.insert( key,oneMark.toDouble() );
      }

      if(validateDecimal(oneMark.toDouble()))
      {
       emit FileParseError( QString ( "Error found student number %1 for mark type %2 contains a decimal number" ).arg( key ).arg( mt ));
      }

      if(oneMark.toDouble() > 100)
      {
          emit FileParseError( QString ( "Invalid mark found. Plase not ITS only accepts final % marks between 0 and 100% the mark %1 for student %2 is not valid" ).arg( oneMark.toDouble()).arg(key));
      }
   }

 return allMarks;
}

bool DocInterface::validateDecimal(double mark)
{
    int intmark = (static_cast<int>(mark));
    if( mark - intmark  > 0 ) {
     return true;
    }
   return false;
}

QStringList DocInterface::GetAllStudentNumbersPerMarkType(QString mt){

    //Will return all student numbers irrespective of mark
    QMap<QString, int> allMarks = GetAllMarksPerMarkType( mt );

    QStringList snums;

    QMap<QString, int>::const_iterator i = allMarks.constBegin();

     while (i != allMarks.constEnd()) {

         QString stunum = i.key();
         validateStudentNumber( stunum );
         snums.append( stunum );
         ++i;
     }
     return snums;
}

int DocInterface::GetStudentMarkPerMarkType( QString mt,QString stunum ){
   QMap<QString, int> allMarks = GetAllMarksPerMarkType( mt );

   QMap<QString, int>::const_iterator i = allMarks.constBegin();
    while (i != allMarks.constEnd()) {
        sanitizeString( stunum );
        validateStudentNumber( stunum );
        if( i.key()==stunum )
        {
         return i.value();
        }
        ++i;
    }
     emit FileParseError( QString ( "No mark found for student %1  for mark type %2" ).arg( stunum ).arg( mt ));
     return 0;
}
