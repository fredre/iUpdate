#ifndef DOCUMENTINTERFACE_H
#define DOCUMENTINTERFACE_H

#include <QStringList>
#include <QFile>
#include <QMap>

class DocumentInterface
{
public:

<<<<<<< HEAD
    virtual QString echo(    const QString &message    ) = 0;
    virtual QString FilePath()= 0;
    virtual void setFilePath(   QString    )= 0;
=======
    virtual QString echo( const QString &message ) = 0;
    virtual QString FilePath()= 0;
<<<<<<< HEAD
    virtual void setFilePath( QString )= 0;
>>>>>>> 0bf96991929a539aac0a172bd103e1896b41bdda
    virtual QString getFileExt()= 0;
    virtual QString getFileTypeName()= 0;
    virtual bool loadFile()= 0;
    virtual QString getSubjectCode()= 0;
    virtual QString getFirstStudentNumber()= 0;
    virtual QString getLastStudentNumber()= 0;
    virtual int getStudentCount()= 0;
    virtual QStringList getMarkTypesList()= 0;
    virtual int getMarkTypesCount()= 0;
<<<<<<< HEAD
    virtual int getMarkTypeTotalNumberMarks(    QString    )= 0;
    virtual QStringList getAllStudentNumbersPerMarkType(    QString    )= 0;
    virtual QMap<QString, int> getAllMarksPerMarkType(  QString    )= 0;
    virtual int getStudentMarkPerMarkType(    QString    ,   QString    )= 0;
    virtual QStringList getStudentNumbersWithNoMark(    QString    )= 0;
=======
    virtual int getMarkTypeTotalNumberMarks( QString )= 0;
    virtual QStringList getAllStudentNumbersPerMarkType( QString )= 0;
    virtual QMap<QString, int> getAllMarksPerMarkType( QString )= 0;
    virtual int getStudentMarkPerMarkType( QString,QString )= 0;
    virtual QStringList getStudentNumbersWithNoMark( QString )= 0;
>>>>>>> 0bf96991929a539aac0a172bd103e1896b41bdda
=======
    virtual void SetFilePath( QString )= 0;
    virtual QString GetFileExt()= 0;
    virtual QString GetFileTypeName()= 0;
    virtual bool LoadFile()= 0;
    virtual QString GetSubjectCode()= 0;
    virtual QString GetFirstStudentNumber()= 0;
    virtual QString GetLastStudentNumber()= 0;
    virtual int GetStudentCount()= 0;
    virtual QStringList GetMarkTypesList()= 0;
    virtual int GetMarkTypesCount()= 0;
    virtual int GetMarkTypeTotalNumberMarks( QString )= 0;
    virtual QStringList GetAllStudentNumbersPerMarkType( QString )= 0;
    virtual QMap<QString, int> GetAllMarksPerMarkType( QString )= 0;
    virtual int GetStudentMarkPerMarkType( QString,QString )= 0;
    virtual QStringList GetStudentNumbersWithNoMark( QString )= 0;
>>>>>>> 9741ee93263e965794ac363168e703497d496a37
};



Q_DECLARE_INTERFACE(    DocumentInterface   ,    "org.QT.iupdate.plugins.documents"    )

#endif // DOCUMENTINTERFACE_H
