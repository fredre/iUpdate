#ifndef DOCUMENTINTERFACE_H
#define DOCUMENTINTERFACE_H

#include <QStringList>
#include <QFile>
#include <QMap>

class DocumentInterface
{
public:

    virtua QString echo(const QString &message) = 0;
};



Q_DECLARE_INTERFACE(DocumentInterface, "org.QT.iupdate.plugins.documents")

#endif // DOCUMENTINTERFACE_H
