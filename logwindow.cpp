#include "logwindow.h"
#include "ui_logwindow.h"
#include "qdebug.h"

LogWindow::LogWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LogWindow)
{
    ui->setupUi(this);

}

LogWindow::~LogWindow()
{
    delete ui;
}

void appendLog(QStringList appme)
{

}

void LogWindow::addUpdateHeader(QString fileUsed,QString mtused,QString subject)
{
   QTextCursor cur(ui->textEdit->textCursor());

    cur.clearSelection();
    cur.movePosition(QTextCursor::Start);

    cur.insertText(tr("--- I - Update version %1 --- \n").arg(QApplication::applicationVersion()));
    cur.insertBlock();
    cur.insertText(tr("Mark Update \n"));
    cur.insertText(tr("On %1 \n").arg(QDateTime::currentDateTime().toString()));
    cur.insertText(tr("For subject %1 \n").arg(subject));
    cur.insertText(tr("Using file %1 \n").arg(fileUsed));
    cur.insertText(tr("Using file marktype %1 \n").arg(mtused));

    //Save the subjectName and marktype  for later
    Subname  = subject;
    MarkType = mtused;
}

void  LogWindow::addErrors(QStringList li)
{
 QTextCursor cur(ui->textEdit->textCursor());

 cur.insertBlock();
 cur.insertText(tr("Errors \n"));
 cur.insertBlock();

  ////QTextListFormat listFormat;
  //listFormat.setStyle(QTextListFormat::ListDecimal);
  //listFormat.setNumberPrefix("(");
 // listFormat.setNumberSuffix(")");
 // listFormat.setIndent(listFormat.indent() + 1);
  //cur.insertList(listFormat);

  foreach(QString item,li)
  {
    cur.insertText(tr("%1 \n").arg(item));
  }

}

void LogWindow::addWarning(QStringList li)
{
    QTextCursor cur(ui->textEdit->textCursor());

    cur.insertBlock();
    cur.insertText(tr("Warning \n"));
    cur.insertBlock();

    foreach(QString item,li)
    {
      cur.insertText(tr("%1 \n").arg(item));
    }

}

void LogWindow::addInformation(QStringList li)
{
    QTextCursor cur(ui->textEdit->textCursor());

    cur.insertBlock();
    cur.insertText(tr("Information \n"));
    cur.insertBlock();

    foreach(QString item,li)
    {
      cur.insertText(tr("%1 \n").arg(item));
    }
}


void LogWindow::on_actionSave_triggered()
{
    qDebug() << Q_FUNC_INFO <<"start";
    QDir dir;
     qDebug()<<"Current dir "<<dir.current();

    bool stat =  dir.mkdir(Subname);
    qDebug()<<"New dir created result "<<stat;
    stat = dir.cd(Subname);
    qDebug()<<"Entering new dir result "<<stat;

    QString filename = tr("%1%4%2_UpdateLog_%3-%5-%6@%7-%8.txt").arg(dir.absolutePath()).arg(MarkType).arg(QDateTime::currentDateTime().date().year()).arg("/").arg(QDateTime::currentDateTime().date().month()).arg(QDateTime::currentDateTime().date().day()).arg(QDateTime::currentDateTime().time().hour()).arg(QDateTime::currentDateTime().time().minute());
    qDebug()<<"Writing log to file "<<filename;
    QFile outfile;outfile.setFileName(filename);
    outfile.open(QIODevice::Append| QIODevice::Text);
    QTextStream out(&outfile);
    out<< ui->textEdit->document()->toPlainText()<<endl;




    qDebug() << Q_FUNC_INFO <<"end";
}
