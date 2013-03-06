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


bool DocInterface::checkDuplicateStudentNumbers( QStringList  lstsnums )
{
    //This is not really used by the app since the file contents is converted to QMap and Qmap does not allow duplicate keys.
    //And i used student number as key lol
    //So when 2 student numbers is the same one is just ignored !
    //This is fixed at the point where the qmap is built ! and the user is warned getAllMarksPerMarkType

    lstsnums.sort();

   for( int a =0;a<lstsnums.count()-1;a++ )
   {
       if( lstsnums.at( a )==lstsnums.at( a+1 ) )
       {
           qDebug()<<QString( "Duplicate student numbers found. %1 was found multiple times" ).arg( lstsnums.at( a ) );
           emit FileParseError( QString(" Duplicate student numbers found. %1 was found multiple times" ).arg( lstsnums.at( a ) ) );

           return false;
       }
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
      QString scode;
      scode = filecontents[ 0 ];
      scode = scode.split( ',' )[ 0 ];
      sanitizeString( scode );
      return scode;
  }

  QString DocInterface::GetFirstStudentNumber() {
      QString snum = filecontents[ 3 ];
      snum = snum.split( ',' )[ 0 ];
      sanitizeString( snum );
      validateStudentNumber( snum );
      return snum;
  }

  QString DocInterface::GetLastStudentNumber() {

      for ( int a=filecontents.count()-1;a>=0;a-- ) {
       //this needs sanitation also bec of "END"
       QString content =filecontents[ a ].split( ',' )[ 0 ];
       sanitizeString( content );

        if ( content=="END" ) {
        QString lstu = filecontents[ a-1 ].split( ',' )[ 0 ];


        sanitizeString( lstu );
        validateStudentNumber( lstu );

        return lstu;
       }
      }
  }


  int  DocInterface::GetStudentCount() {
      for ( int a=filecontents.count()-1;a>=0;a-- ) {
         QString content =filecontents[ a ].split( ',' )[ 0 ];
         sanitizeString( content );

         if ( content=="END" ) {

           return ( a-3 );

          }
      }
  }


QStringList DocInterface::GetMarkTypesList() {
   QString mtypes =filecontents[ 2 ];
   sanitizeString( mtypes );
   QStringList mtypesSp = mtypes.split( ',' );

  mtypesSp.removeAt(0);

 return mtypesSp;
}


 int DocInterface::getMarkTypeColumn( QString mt ) {
     //Will return the coloumn number of the marktype
     QStringList mtypesall = filecontents[ 2 ].split( ',' );
     int loc;

     for ( int a=0;a<mtypesall.count();a++ ) {
       QString snglmt =mtypesall[ a ];
       sanitizeString( snglmt );
       if( snglmt==mt ) {
           loc =a;
           //qDebug()<<"Mark type found "<<mt<<" location "<<loc;
       }
     }

     return loc;
 }



int DocInterface::GetMarkTypeTotalNumberMarks( QString mt )
{
    //Return the total ammount of marks for the marktype
    //If mark is 0 or empty it is not counted

    int totamt=0;


   QMap<QString, int> allMarks = GetAllMarksPerMarkType( mt );


    //loop over all marks and get the mark count for this marktype
   QMap<QString, int>::const_iterator i = allMarks.constBegin();

    while ( i != allMarks.constEnd() ) {


        if ( i.value()!=0 ) {

          totamt++;
           //qDebug()<<"Ammount "<<totamt << "of marks incremented for mark "<<i.value()<<"Marktype "<<mt<<" student number"<<i.key();
        }
           ++i;
    }

    return totamt;
}


QMap<QString, int> DocInterface::GetAllMarksPerMarkType(QString mt)

{
   //This will return all marks from the file for the specified marktype. If the mark is empty or 0 the mark will slill be returned

   QMap<QString, int> allMarks;


   int loc = getMarkTypeColumn( mt );


   for ( int a=3;a<filecontents.count()-1;a++ ) {
       QStringList line = filecontents[ a ].split( ',' ); //Split the mark line into sperate marks
       QString mark = line[ loc ]; //Get only the mark for the marktype specified by arg mt
       QString snum = line[ 0 ]; //Get the student number

       //A QMap ingores duplicate keys. so if the map already contains key named stunum warn the user
       if( allMarks.contains( snum ) ) {

            emit FileParseError( QString ( "Duplicate student number found. %1 was found for mark type %2 more then once" ).arg( snum ).arg( mt ));

       }

       allMarks.insert( snum,mark.toInt() );
   }
   if( allMarks.count() != GetStudentCount() )  //I shot the dean but I didnt shoot the associate dean ! This should never happen
   {
     emit FileParseError( QString( "Serious error. The total ammount of students are %1 but the ammount of marks returned for %2 is %3" ).arg( GetStudentCount() ).arg( mt ).arg( allMarks.count() ) );
   }



 return allMarks;
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
     checkDuplicateStudentNumbers( snums );
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
}


 QStringList DocInterface::GetStudentNumbersWithNoMark( QString mt ) {

  //Will return all student numbers where mark is 0 or empty

 QMap<QString, int> allMarks = GetAllMarksPerMarkType( mt );


 QStringList nomarks;

 QMap<QString, int>::const_iterator i = allMarks.constBegin();

  while ( i != allMarks.constEnd() ) {

      if( i.value()==0 )
      {

       QString stunum = i.key();
       sanitizeString(stunum);
       validateStudentNumber(stunum);
        nomarks.append(stunum);
     }
         ++i;
  }
   checkDuplicateStudentNumbers(nomarks);

    return nomarks;
 }


 int DocInterface::GetMarkTypesCount() {

     return GetMarkTypesList().count();

 }
