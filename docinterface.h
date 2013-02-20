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
<<<<<<< HEAD
    explicit DocInterface( QObject *parent = 0 );
    QString FilePath();
    void setFilePath( QString );
    QString getFileExt();
    QString getFileTypeName();
    bool loadFile();
    QString getSubjectCode();
    QString getFirstStudentNumber();
    QString getLastStudentNumber();
    int getStudentCount();
    QStringList getMarkTypesList();
    int getMarkTypesCount();
    int getMarkTypeTotalNumberMarks( QString );
    QStringList getAllStudentNumbersPerMarkType( QString );
    QMap<QString, int> getAllMarksPerMarkType( QString );
    int getStudentMarkPerMarkType( QString,QString );
    QStringList getStudentNumbersWithNoMark( QString );
    int getMarkTypeColumn( QString );
    bool validateStudentNumber( QString );
    void sanitizeString( QString & );
    bool checkDuplicateStudentNumbers( QStringList );
=======
    explicit DocInterface(QObject *parent = 0);
    QString FilePath();
    void SetFilePath(QString);
    QString GetFileExt();
    QString GetFileTypeName();
    bool LoadFile();
    QString GetSubjectCode();
    QString GetFirstStudentNumber();
    QString GetLastStudentNumber();
    int GetStudentCount();
    QStringList GetMarkTypesList();
    int GetMarkTypesCount();
    int GetMarkTypeTotalNumberMarks(QString);
    QStringList GetAllStudentNumbersPerMarkType(QString);
    QMap<QString, int> GetAllMarksPerMarkType(QString);
    int GetStudentMarkPerMarkType(QString,QString);
    QStringList GetStudentNumbersWithNoMark(QString);
    int getMarkTypeColumn(QString);
    bool validateStudentNumber(QString);
    void sanitizeString(QString &);
    bool checkDuplicateStudentNumbers(QStringList);
>>>>>>> Serame-master

private:
    QString filepath;
    QStringList filecontents;


<<<<<<< HEAD
signals:
    void FileParseError( QString );
=======

signals:
    void FileParseError(QString);
>>>>>>> Serame-master

public slots:

};

#endif // DOCINTERFACE_H
