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
    virtual void setFilePath( QString )= 0;
    virtual QString getFileExt()= 0;
    virtual QString getFileTypeName()= 0;
    virtual bool loadFile()= 0;
    virtual QString getSubjectCode()= 0;
    virtual QString getFirstStudentNumber()= 0;
    virtual QString getLastStudentNumber()= 0;
    virtual int getStudentCount()= 0;
    virtual QStringList getMarkTypesList()= 0;
    virtual int getMarkTypesCount()= 0;
    virtual int getMarkTypeTotalNumberMarks( QString )= 0;
    virtual QStringList getAllStudentNumbersPerMarkType( QString )= 0;
    virtual QMap<QString, int> getAllMarksPerMarkType( QString )= 0;
    virtual int getStudentMarkPerMarkType( QString,QString )= 0;
    virtual QStringList getStudentNumbersWithNoMark( QString )= 0;
};



Q_DECLARE_INTERFACE(DocumentInterface, "org.QT.iupdate.plugins.documents")

#endif // DOCUMENTINTERFACE_H
