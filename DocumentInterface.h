#ifndef DOCUMENTINTERFACE_H
#define DOCUMENTINTERFACE_H

#include <QStringList>
#include <QFile>
#include <QMap>

class DocumentInterface
{
public:

    virtual QString echo( const QString &message ) = 0;
    virtual QString FilePath()= 0;
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
};



Q_DECLARE_INTERFACE(DocumentInterface, "org.QT.iupdate.plugins.documents")

#endif // DOCUMENTINTERFACE_H
