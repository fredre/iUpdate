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
    explicit DocInterface(QObject *parent = 0);
    QString FilePath();
    void setFilePath(QString);
    QString getFileExt();
    QString getFileTypeName();
    bool loadFile();
    QString getSubjectCode();
    QString getFirstStudentNumber();
    QString getLastStudentNumber();
    int getStudentCount();
    QStringList getMarkTypesList();
    int getMarkTypesCount();
    int getMarkTypeTotalNumberMarks(QString);
    QStringList getAllStudentNumbersPerMarkType(QString);
    QMap<QString, int> getAllMarksPerMarkType(QString);
    int getStudentMarkPerMarkType(QString,QString);
    QStringList getStudentNumbersWithNoMark(QString);
    int getMarkTypeColumn(QString);
    bool validateStudentNumber(QString);
    void sanitizeString(QString &);

private:
    QString filepath;
    QStringList filecontents;



signals:
    void FileParseError(QString);

public slots:

};

#endif // DOCINTERFACE_H
