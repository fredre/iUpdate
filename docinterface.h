#ifndef DOCINTERFACE_H
#define DOCINTERFACE_H

#include <QObject>
#include <QStringList>
#include <QFile>
#include "qdebug.h"
#include <QMap>
#include <QIntValidator>


class DocInterface : public QObject
{
    Q_OBJECT
public:
    explicit DocInterface( QObject *parent = 0 );
    QString FilePath();
    void SetFilePath( QString );
    QString GetFileExt();
    QString GetFileTypeName();
    bool LoadFile();
    QString GetSubjectCode();
    QString GetFirstStudentNumber();
    QString GetLastStudentNumber();
    int GetStudentCount();
    QStringList GetMarkTypesList();
    int GetMarkTypesCount();
    int GetMarkTypeTotalNumberMarks( QString );
    QStringList GetAllStudentNumbersPerMarkType( QString );
    QMap<QString, int> GetAllMarksPerMarkType( QString );
    int GetStudentMarkPerMarkType( QString,QString );
    QStringList GetStudentNumbersWithNoMark( QString );
    int getMarkTypeColumn( QString );
    bool validateStudentNumber( QString );
    bool validateDecimal(QString);
    void sanitizeString( QString & );
    bool checkDuplicateStudentNumbers( QStringList );


private:
    QString filepath;
    QStringList filecontents;
    QStringList erros;

    bool isWithoutEnd = false;



signals:
    void FileParseError( QString );

public slots:

};

#endif // DOCINTERFACE_H
