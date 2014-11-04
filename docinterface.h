#ifndef DOCINTERFACE_H
#define DOCINTERFACE_H

#include <QObject>
#include <QStringList>
#include <QFile>
#include "qdebug.h"
#include <QMap>
#include <QIntValidator>

#include <QJsonObject>
#include <QJsonValue>
#include <QJsonDocument>
#include <QJsonArray>


class DocInterface : public QObject
{
    Q_OBJECT
public:
    explicit DocInterface( QObject *parent = 0 );
    QString FilePath();
    void SetFilePath( QString );
    void LoadJsonDoc(QJsonDocument*);

    QString GetFileExt();
    QString GetFileTypeName();
    bool LoadFile();
    QString GetSubjectCode();
    int GetStudentCount();
    QStringList GetMarkTypesList();
    int GetMarkTypeTotalNumberMarks( QString );
    QStringList GetAllStudentNumbersPerMarkType( QString );
    QMap<QString, int> GetAllMarksPerMarkType( QString );
    int GetStudentMarkPerMarkType( QString,QString );

    bool validateStudentNumber( QString );
    bool validateDecimal(double mark);
    void sanitizeString( QString & );

private:
    QString filepath;
    QStringList filecontents;
    QStringList erros;
    QJsonDocument *JDoc;

signals:
    void FileParseError( QString );

public slots:

};

#endif // DOCINTERFACE_H
