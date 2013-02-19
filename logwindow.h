#ifndef LOGWINDOW_H
#define LOGWINDOW_H

#include <QMainWindow>
#include <QTextCursor>
#include <QDateTime>
#include <QTextCharFormat>
#include <QTextListFormat>
#include <QDir>
#include <QFile>
#include <QTextStream>

namespace Ui {
    class LogWindow;
}

class LogWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LogWindow(QWidget *parent = 0);
    ~LogWindow();
    void AppendLog( QStringList );
    void AddUpdateHeader( QString,QString,QString );
    void AddErrors( QStringList );
    void AddInformation( QStringList );
    void addWarning( QStringList );


private slots:
    void on_actionSave_triggered();

private:
    Ui::LogWindow *ui;
    QString Subname;
    QString MarkType;

};

#endif // LOGWINDOW_H
