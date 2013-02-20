#include "docinterface.h"

<<<<<<< HEAD
DocInterface::DocInterface( QObject *parent ) :
<<<<<<< HEAD
    QObject( parent ) {

}

void DocInterface::sanitizeString( QString &needsSanitation ) {
    //Remove ""
  if( needsSanitation.contains ( '"' ) ) {
=======
    QObject( parent )
{

}

void DocInterface::sanitizeString( QString &needsSanitation )
{
    //Remove ""
  if( needsSanitation.contains( '"' ) )
  {
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
    needsSanitation.replace( '"',"" );
=======
DocInterface::DocInterface(QObject *parent) :
    QObject(parent)
{

}

void DocInterface::sanitizeString(QString &needsSanitation)
{
    //Remove ""
  if(needsSanitation.contains('"'))
  {
    needsSanitation.replace('"',"");
>>>>>>> 9741ee93263e965794ac363168e703497d496a37
  }

  //Sometimes I feel the campus needsSanitation ;P

  //Trimmerd
  needsSanitation = needsSanitation.simplified();
  needsSanitation = needsSanitation.trimmed();

}

<<<<<<< HEAD
bool DocInterface::validateStudentNumber( QString number ) {
   //False trap to check


    if( number.length()>=10 ) {
=======
bool DocInterface::validateStudentNumber( QString number )
{
   //False trap to check


    if( number.length()>=10 )
    {
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
        emit FileParseError( QString( "Invalid student number found. Student number %1 has more then 9 digits" ).arg( number ) );
        qDebug()<<QString( "Invalid student number found. Student number %1 has more then 9 digits" ).arg( number );
        return false;
    }

<<<<<<< HEAD
    if( number.length()<=7 ) {
       emit FileParseError( QString( "Invalid student number found. Student number %1 has less then 8 digits" ).arg( number ) );
=======
    if( number.length()<=7 )
    {
       emit FileParseError( QString( "Invalid student number found. Student number %1 has less then 8 digits" ).arg( number ));
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
       qDebug()<<QString( "Invalid student number found. Student number %1 has less then 8 digits" ).arg( number );
       return false;
    }

     QIntValidator v( 00000001, 999999999, this );
     int pos=0;
<<<<<<< HEAD
     if( v.validate( number,pos ) == QValidator::Invalid ) {
=======
     if( v.validate( number,pos ) == QValidator::Invalid )
     {
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
      emit FileParseError( QString( "Invalid student number found. Student number %1 does not consist of all numbers or contains spaces." ).arg( number ) );
      qDebug()<<QString( "Invalid student number found. Student number %1 does not consist of all numbers or contains spaces." ).arg( number );
=======
bool DocInterface::validateStudentNumber(QString number)
{
   //False trap to check


    if(number.length()>=10)
    {
        emit FileParseError(QString("Invalid student number found. Student number %1 has more then 9 digits").arg(number));
        qDebug()<<QString("Invalid student number found. Student number %1 has more then 9 digits").arg(number);
        return false;
    }

    if(number.length()<=7)
    {
       emit FileParseError(QString("Invalid student number found. Student number %1 has less then 8 digits").arg(number));
       qDebug()<<QString("Invalid student number found. Student number %1 has less then 8 digits").arg(number);
       return false;
    }

     QIntValidator v(00000001, 999999999, this);
     int pos=0;
     if(v.validate(number,pos) == QValidator::Invalid)
     {
      emit FileParseError(QString("Invalid student number found. Student number %1 does not consist of all numbers or contains spaces.").arg(number));
      qDebug()<<QString("Invalid student number found. Student number %1 does not consist of all numbers or contains spaces.").arg(number);
>>>>>>> 9741ee93263e965794ac363168e703497d496a37
      return false;
     }

    return true;
}

<<<<<<< HEAD
bool DocInterface::checkDuplicateStudentNumbers( QStringList  lstsnums ) {
=======
bool DocInterface::checkDuplicateStudentNumbers( QStringList  lstsnums )
{
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
    //This is not really used by the app since the file contents is converted to QMap and Qmap does not allow duplicate keys.
    //And i used student number as key lol
    //So when 2 student numbers is the same one is just ignored !
    //This is fixed at the point where the qmap is built ! and the user is warned getAllMarksPerMarkType

    lstsnums.sort();

<<<<<<< HEAD
   for( int a =0;a<lstsnums.count()-1;a++ ) {
       if( lstsnums.at(a)==lstsnums.at(a+1) ) {
           qDebug()<<QString( "Duplicate student numbers found. %1 was found multiple times" ).arg( lstsnums.at( a ) );
           emit FileParseError( QString( "Duplicate student numbers found. %1 was found multiple times" ).arg( lstsnums.at( a ) ) );
=======
<<<<<<< HEAD
   for( int a =0;a<lstsnums.count()-1;a++ )
   {
       if( lstsnums.at( a )==lstsnums.at( a+1 ) )
       {
           qDebug()<<QString( "Duplicate student numbers found. %1 was found multiple times" ).arg( lstsnums.at( a ) );
           emit FileParseError( QString(" Duplicate student numbers found. %1 was found multiple times" ).arg( lstsnums.at( a ) ) );
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
bool DocInterface::checkDuplicateStudentNumbers(QStringList  lstsnums)
{
    //This is not really used by the app since the file contents is converted to QMap and Qmap does not allow duplicate keys.
    //And i used student number as key lol
    //So when 2 student numbers is the same one is just ignored !
    //This is fixed at the point where the qmap is built ! and the user is warned GetAllMarksPerMarkType

    lstsnums.sort();

   for(int a =0;a<lstsnums.count()-1;a++)
   {
       if(lstsnums.at(a)==lstsnums.at(a+1))
       {
           qDebug()<<QString("Duplicate student numbers found. %1 was found multiple times").arg(lstsnums.at(a));
           emit FileParseError(QString("Duplicate student numbers found. %1 was found multiple times").arg(lstsnums.at(a)));
>>>>>>> 9741ee93263e965794ac363168e703497d496a37
>>>>>>> Serame-master
           return false;
       }
   }

  return true;
}

<<<<<<< HEAD
QString DocInterface::FilePath() {
    return filepath;
}

void DocInterface::setFilePath( QString fp ) {
    filepath = fp;
}

bool DocInterface::loadFile() {
    if( filepath.isNull() ) {
=======
QString DocInterface::FilePath()
{
    return filepath;
}

void DocInterface::setFilePath( QString fp )
{
    filepath = fp;
}

bool DocInterface::loadFile()
{
    if( filepath.isNull() )
    {
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
        return false;
    }

        QFile file( filepath );

<<<<<<< HEAD
        if( file.open( QIODevice::ReadOnly | QIODevice::Text ) ) {
            //Clear file contents
            filecontents.clear();

            while( !file.atEnd() ) {
=======
        if ( file.open( QIODevice::ReadOnly | QIODevice::Text ) )
        {
            //Clear file contents
            filecontents.clear();

            while ( !file.atEnd() )
            {
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
                QString line = file.readLine();
                line = line.trimmed();
                filecontents.append( line );
=======
QString DocInterface::FilePath()
{
    return filepath;
}

void DocInterface::SetFilePath(QString fp)
{
    filepath = fp;
}

bool DocInterface::LoadFile()
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
>>>>>>> 9741ee93263e965794ac363168e703497d496a37
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

<<<<<<< HEAD
 QString DocInterface::getFileExt() {
     return "CSV Files (*.csv)";
 }

  QString  DocInterface::getFileTypeName() {
      return "CSV";
  }

  QString DocInterface::getSubjectCode() {
      QString scode;
      scode = filecontents[ 0 ];
      scode = scode.split( ',' )[ 0 ];
      sanitizeString( scode );
      return scode;
  }

  QString DocInterface::getFirstStudentNumber() {
      QString snum = filecontents[ 3 ];
      snum = snum.split( ',' )[ 0 ];
      sanitizeString( snum );
      validateStudentNumber( snum );
      return snum;
  }

  QString DocInterface::getLastStudentNumber() {

      for ( int a=filecontents.count()-1;a>=0;a-- ) {
       //this needs sanitation also bec of "END"
       QString content =filecontents[ a ].split( ',' )[ 0 ];
       sanitizeString( content );

        if ( content=="END" ) {
        QString lstu = filecontents[ a-1 ].split( ',' )[ 0 ];
=======
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
      scode = scode.split(',')[0];
      sanitizeString(scode);
      return scode;
  }

  QString DocInterface::getFirstStudentNumber()
  {
      QString snum = filecontents[3];
      snum = snum.split(',')[0];
      sanitizeString(snum);
      validateStudentNumber(snum);
      return snum;
  }

  QString DocInterface::getLastStudentNumber()
  {

      for( int a=filecontents.count()-1;a>=0;a-- )
      {
       //this needs sanitation also bec of "END"
       QString content =filecontents[a].split(',')[0];
       sanitizeString( content );

        if( content=="END" )
       {
        QString lstu = filecontents[a-1].split(',')[0];
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
        sanitizeString( lstu );
        validateStudentNumber( lstu );
=======
 QString DocInterface::GetFileExt()
 {
     return "CSV Files (*.csv)";
 }

  QString  DocInterface::GetFileTypeName()
  {
      return "CSV";
  }

  QString DocInterface::GetSubjectCode()
  {
      QString scode;
      scode = filecontents[0];
      scode = scode.split(',')[0];
      sanitizeString(scode);
      return scode;
  }

  QString DocInterface::GetFirstStudentNumber()
  {
      QString snum = filecontents[3];
      snum = snum.split(',')[0];
      sanitizeString(snum);
      validateStudentNumber(snum);
      return snum;
  }

  QString DocInterface::GetLastStudentNumber(){

      for(int a=filecontents.count()-1;a>=0;a--)
      {
       //this needs sanitation also bec of "END"
       QString content =filecontents[a].split(',')[0];
       sanitizeString(content);

        if(content=="END")
       {
        QString lstu = filecontents[a-1].split(',')[0];
        sanitizeString(lstu);
        validateStudentNumber(lstu);
>>>>>>> 9741ee93263e965794ac363168e703497d496a37
        return lstu;
       }
      }
  }

<<<<<<< HEAD
  int  DocInterface::getStudentCount() {
      for ( int a=filecontents.count()-1;a>=0;a-- ) {
         QString content =filecontents[ a ].split( ',' )[ 0 ];
         sanitizeString( content );

         if ( content=="END" ) {
=======
  int  DocInterface::getStudentCount()
  {
      for( int a=filecontents.count()-1;a>=0;a-- )
      {
         QString content =filecontents[a].split( ',' )[0];
         sanitizeString(content);

         if( content=="END" )
          {
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
           return ( a-3 );
=======
  int  DocInterface::GetStudentCount()
  {
      for(int a=filecontents.count()-1;a>=0;a--)
      {
         QString content =filecontents[a].split(',')[0];
         sanitizeString(content);

         if(content=="END")
          {
           return (a-3);
>>>>>>> 9741ee93263e965794ac363168e703497d496a37
          }
      }
  }

<<<<<<< HEAD
QStringList DocInterface::getMarkTypesList() {
   QString mtypes =filecontents[ 2 ];
   sanitizeString( mtypes );
   QStringList mtypesSp = mtypes.split( ',' );
=======
QStringList DocInterface::GetMarkTypesList()
{
   QString mtypes =filecontents[2];
   sanitizeString(mtypes);
   QStringList mtypesSp = mtypes.split(',');
>>>>>>> 9741ee93263e965794ac363168e703497d496a37

  mtypesSp.removeAt(0);
=======
QStringList DocInterface::getMarkTypesList()
{
   QString mtypes =filecontents[2];
   sanitizeString( mtypes );
   QStringList mtypesSp = mtypes.split( ',' );

  mtypesSp.removeAt( 0 );
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad

 return mtypesSp;
}

<<<<<<< HEAD
 int DocInterface::getMarkTypeColumn( QString mt ) {
     //Will return the coloumn number of the marktype
     QStringList mtypesall = filecontents[ 2 ].split( ',' );
     int loc;

     for ( int a=0;a<mtypesall.count();a++ ) {
       QString snglmt =mtypesall[ a ];
       sanitizeString( snglmt );
       if( snglmt==mt ) {
=======
<<<<<<< HEAD
 int DocInterface::getMarkTypeColumn( QString mt )
 {
     //Will return the coloumn number of the marktype
     QStringList mtypesall = filecontents[2].split( ',' );
     int loc;

     for( int a=0;a<mtypesall.count();a++ )
     {
       QString snglmt =mtypesall[a];
       sanitizeString( snglmt );
       if( snglmt==mt )
       {
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
 int DocInterface::getMarkTypeColumn(QString mt)
 {
     //Will return the coloumn number of the marktype
     QStringList mtypesall = filecontents[2].split(',');
     int loc;

     for(int a=0;a<mtypesall.count();a++)
     {
       QString snglmt =mtypesall[a];
       sanitizeString(snglmt);
       if(snglmt==mt)
       {
>>>>>>> 9741ee93263e965794ac363168e703497d496a37
>>>>>>> Serame-master
           loc =a;
           //qDebug()<<"Mark type found "<<mt<<" location "<<loc;
       }
     }

     return loc;
 }


<<<<<<< HEAD
int DocInterface::getMarkTypeTotalNumberMarks( QString mt ) {
=======
<<<<<<< HEAD
int DocInterface::getMarkTypeTotalNumberMarks( QString mt )
{
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
int DocInterface::GetMarkTypeTotalNumberMarks(QString mt)
{
>>>>>>> 9741ee93263e965794ac363168e703497d496a37
>>>>>>> Serame-master
    //Return the total ammount of marks for the marktype
    //If mark is 0 or empty it is not counted

    int totamt=0;

<<<<<<< HEAD
   QMap<QString, int> allMarks = getAllMarksPerMarkType( mt );
=======
   QMap<QString, int> allMarks = GetAllMarksPerMarkType(mt);
>>>>>>> 9741ee93263e965794ac363168e703497d496a37


    //loop over all marks and get the mark count for this marktype
   QMap<QString, int>::const_iterator i = allMarks.constBegin();
<<<<<<< HEAD
    while ( i != allMarks.constEnd() ) {

<<<<<<< HEAD
        if ( i.value()!=0 ) {
=======
<<<<<<< HEAD
        if( i.value()!=0 )
        {
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
    while (i != allMarks.constEnd()) {

        if(i.value()!=0)
        {
>>>>>>> 9741ee93263e965794ac363168e703497d496a37
>>>>>>> Serame-master
          totamt++;
           //qDebug()<<"Ammount "<<totamt << "of marks incremented for mark "<<i.value()<<"Marktype "<<mt<<" student number"<<i.key();
        }
           ++i;
    }

    return totamt;
}

<<<<<<< HEAD
QMap<QString, int> DocInterface::getAllMarksPerMarkType( QString mt )
=======
QMap<QString, int> DocInterface::GetAllMarksPerMarkType(QString mt)
>>>>>>> 9741ee93263e965794ac363168e703497d496a37
{
   //This will return all marks from the file for the specified marktype. If the mark is empty or 0 the mark will slill be returned

   QMap<QString, int> allMarks;

<<<<<<< HEAD
   int loc = getMarkTypeColumn( mt );

<<<<<<< HEAD
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
     //I shot the dean but I didnt shoot the associate dean ! This should never happen
   if( allMarks.count() != getStudentCount() ) {
     emit FileParseError( QString ( "Serious error. The total ammount of students are %1 but the ammount of marks returned for %2 is %3" ).arg( getStudentCount() ).arg(mt).arg( allMarks.count() ) );
=======
<<<<<<< HEAD
   for( int a=3;a<filecontents.count()-1;a++ )
   {
       QStringList line = filecontents[a].split( ',' ); //Split the mark line into sperate marks
=======
   int loc = getMarkTypeColumn(mt);

   for(int a=3;a<filecontents.count()-1;a++)
   {
       QStringList line = filecontents[a].split(','); //Split the mark line into sperate marks
>>>>>>> Serame-master
       QString mark = line[loc]; //Get only the mark for the marktype specified by arg mt
       QString snum = line[0]; //Get the student number

       //A QMap ingores duplicate keys. so if the map already contains key named stunum warn the user
<<<<<<< HEAD
       if( allMarks.contains( snum ) )
       {
           emit FileParseError( QString( "Duplicate student number found. %1 was found for mark type %2 more then once" ).arg( snum ).arg( mt ) );
=======
       if(allMarks.contains(snum))
       {
           emit FileParseError(QString("Duplicate student number found. %1 was found for mark type %2 more then once").arg(snum).arg(mt));
>>>>>>> Serame-master
       }

       allMarks.insert(snum,mark.toInt());
   }

<<<<<<< HEAD
   if( allMarks.count() != getStudentCount() )  //I shot the dean but I didnt shoot the associate dean ! This should never happen
   {
     emit FileParseError( QString( "Serious error. The total ammount of students are %1 but the ammount of marks returned for %2 is %3" ).arg( getStudentCount() ).arg( mt ).arg( allMarks.count() ) );
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
   if(allMarks.count() != GetStudentCount())  //I shot the dean but I didnt shoot the associate dean ! This should never happen
   {
     emit FileParseError(QString("Serious error. The total ammount of students are %1 but the ammount of marks returned for %2 is %3").arg(GetStudentCount()).arg(mt).arg(allMarks.count()));
>>>>>>> 9741ee93263e965794ac363168e703497d496a37
>>>>>>> Serame-master
   }

 return allMarks;
}

<<<<<<< HEAD
QStringList DocInterface::getAllStudentNumbersPerMarkType( QString mt )
=======
QStringList DocInterface::GetAllStudentNumbersPerMarkType(QString mt)
>>>>>>> 9741ee93263e965794ac363168e703497d496a37
{

    //Will return all student numbers irrespective of mark

<<<<<<< HEAD
    QMap<QString, int> allMarks = getAllMarksPerMarkType( mt );
=======
    QMap<QString, int> allMarks = GetAllMarksPerMarkType(mt);
>>>>>>> 9741ee93263e965794ac363168e703497d496a37

    QStringList snums;

    QMap<QString, int>::const_iterator i = allMarks.constBegin();
<<<<<<< HEAD
     while ( i != allMarks.constEnd() ) {
=======
     while (i != allMarks.constEnd()) {
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
         QString stunum = i.key();
         validateStudentNumber( stunum );
         snums.append( stunum );
         ++i;
     }
     checkDuplicateStudentNumbers( snums );
     return snums;
}

<<<<<<< HEAD
int DocInterface::getStudentMarkPerMarkType( QString mt,QString stunum ) {
   QMap<QString, int> allMarks = getAllMarksPerMarkType( mt );

   QMap<QString, int>::const_iterator i = allMarks.constBegin();
    while ( i != allMarks.constEnd() ) {
        sanitizeString( stunum );
        validateStudentNumber( stunum );
        if( i.key()==stunum ) {
=======
<<<<<<< HEAD
int DocInterface::getStudentMarkPerMarkType( QString mt,QString stunum )
{
   QMap<QString, int> allMarks = getAllMarksPerMarkType( mt );

   QMap<QString, int>::const_iterator i = allMarks.constBegin();
    while (i != allMarks.constEnd()) {
        sanitizeString( stunum );
        validateStudentNumber( stunum );
        if( i.key()==stunum )
        {
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
     while (i != allMarks.constEnd()) {
         QString stunum = i.key();
         validateStudentNumber(stunum);
         snums.append(stunum);
         ++i;
     }
     checkDuplicateStudentNumbers(snums);
     return snums;
}

int DocInterface::GetStudentMarkPerMarkType(QString mt,QString stunum)
{
   QMap<QString, int> allMarks = GetAllMarksPerMarkType(mt);

   QMap<QString, int>::const_iterator i = allMarks.constBegin();
    while (i != allMarks.constEnd()) {
        sanitizeString(stunum);
        validateStudentNumber(stunum);
        if(i.key()==stunum)
        {
>>>>>>> 9741ee93263e965794ac363168e703497d496a37
>>>>>>> Serame-master
         return i.value();
        }
        ++i;
    }
}

<<<<<<< HEAD
 QStringList DocInterface::getStudentNumbersWithNoMark( QString mt ) {
=======
 QStringList DocInterface::getStudentNumbersWithNoMark( QString mt )
 {
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad

  //Will return all student numbers where mark is 0 or empty

 QMap<QString, int> allMarks = getAllMarksPerMarkType( mt );
=======
 QStringList DocInterface::GetStudentNumbersWithNoMark(QString mt)
 {

  //Will return all student numbers where mark is 0 or empty

 QMap<QString, int> allMarks = GetAllMarksPerMarkType(mt);
>>>>>>> 9741ee93263e965794ac363168e703497d496a37

 QStringList nomarks;

 QMap<QString, int>::const_iterator i = allMarks.constBegin();
<<<<<<< HEAD
  while ( i != allMarks.constEnd() ) {
<<<<<<< HEAD
      if( i.value()==0 ) {
=======
      if( i.value()==0 )
      {
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
       QString stunum = i.key();
       sanitizeString( stunum );
       validateStudentNumber( stunum );
        nomarks.append( stunum );
     }
         ++i;
  }
   checkDuplicateStudentNumbers( nomarks );
=======
  while (i != allMarks.constEnd()) {
      if(i.value()==0)
      {
       QString stunum = i.key();
       sanitizeString(stunum);
       validateStudentNumber(stunum);
        nomarks.append(stunum);
     }
         ++i;
  }
   checkDuplicateStudentNumbers(nomarks);
>>>>>>> 9741ee93263e965794ac363168e703497d496a37
    return nomarks;

 }

<<<<<<< HEAD
 int DocInterface::getMarkTypesCount() {
=======
 int DocInterface::getMarkTypesCount()
 {
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
     return getMarkTypesList().count();
=======
 int DocInterface::GetMarkTypesCount()
 {
     return GetMarkTypesList().count();
>>>>>>> 9741ee93263e965794ac363168e703497d496a37
 }
