#include "logwindow.h"
#include "ui_logwindow.h"
#include "qdebug.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

LogWindow::LogWindow( QWidget *parent ) :
    QMainWindow( parent ),
    ui( new Ui::LogWindow ){
    ui->setupUi( this );

}

LogWindow::~LogWindow(){
    delete ui;
}

void AppendLog( QStringList appme ){

}

void LogWindow::AddUpdateHeader( QString fileUsed,QString mtused,QString subject ){
    qDebug() << Q_FUNC_INFO <<"start";

   QTextCursor cur( ui->textEdit->textCursor() );

    cur.clearSelection();
    cur.movePosition( QTextCursor::Start );

    cur.insertText( tr( "--- I - Update version %1 --- \n" ).arg( QApplication::applicationVersion() ) );
    cur.insertBlock();
    cur.insertText( tr( "Mark Update \n" ) );
    cur.insertText( tr( "On %1 \n" ).arg( QDateTime::currentDateTime().toString() ) );
    cur.insertText( tr( "For subject %1 \n" ).arg( subject ) );
    cur.insertText( tr( "Using file %1 \n" ).arg( fileUsed ) );
    cur.insertText( tr( "Using file marktype %1 \n" ).arg( mtused ) );

    //Save the subjectName and marktype  for later
    Subname  = subject.trimmed();
    Subname  = subject.simplified();

    if( Subname.contains( ' ' ) ){
        qDebug()<<"Removed spaces from subject name";
        Subname= Subname.remove( QChar( ' ' ), Qt::CaseInsensitive);
    }

    MarkType = mtused;
    MarkType = MarkType.trimmed();
    MarkType = MarkType.simplified();

    qDebug() << Q_FUNC_INFO <<"end";
}

void  LogWindow::AddErrors( QStringList li ){
 QTextCursor cur( ui->textEdit->textCursor() );

 cur.insertBlock();
 cur.insertText( tr( "Errors \n" ) );
 cur.insertBlock();


  foreach( QString item,li ){
    cur.insertText( tr( "%1 \n" ).arg( item ) );
  }

}

void LogWindow::AddWarning( QStringList li ){
    QTextCursor cur( ui->textEdit->textCursor() );

    cur.insertBlock();
    cur.insertText( tr( "Warning \n" ) );
    cur.insertBlock();

    foreach(QString item,li){
      cur.insertText( tr( "%1 \n" ).arg(item) );
    }
}

void LogWindow::AddInformation( QStringList li ){
    QTextCursor cur( ui->textEdit->textCursor() );

    cur.insertBlock();
    cur.insertText( tr( "Information \n" ) );
    cur.insertBlock();

    foreach( QString item,li ){
      cur.insertText( tr( "%1 \n" ).arg( item ) );
    }
}


void LogWindow::On_actionSave_triggered(){
    qDebug() << Q_FUNC_INFO <<"start";
     QDir dir;
     qDebug()<<"Current dir "<<dir.current();

    bool stat =  dir.mkdir( Subname );
    qDebug()<<"New dir created result "<<stat;
    stat = dir.cd( Subname );
    qDebug()<<"Entering new dir result "<<stat;

    QString filename = tr( "%1%4%2_UpdateLog_%3-%5-%6@%7-%8.txt" ).arg( dir.absolutePath() ).arg( MarkType ).arg( QDateTime::currentDateTime().date().year() ).arg( "/" ).arg( QDateTime::currentDateTime().date().month() ).arg( QDateTime::currentDateTime().date().day() ).arg( QDateTime::currentDateTime().time().hour() ).arg( QDateTime::currentDateTime().time().minute() );
    qDebug()<<"Writing log to file "<<filename;
    QFile outfile;
    outfile.setFileName( filename );
    outfile.open( QIODevice::Append| QIODevice::Text );
    QTextStream out(&outfile);
    out<< ui->textEdit->document()->toPlainText()<<endl;


    qDebug() << Q_FUNC_INFO <<"end";
}

void LogWindow::on_pushButton_2_clicked()
{
    QMessageBox msgBox;
    qDebug() << Q_FUNC_INFO <<"start";

    QString directory = QFileDialog::getExistingDirectory(this,tr("Choose or Create Directory"),QDir::homePath(),QFileDialog::ShowDirsOnly);
    if(directory != "")
    {
        QDir savedir(directory);
        QString fileName = tr( "%1%4_%9_%2_UpdateLog_%3-%5-%6@%7-%8.txt" ).arg( savedir.absolutePath() ).arg( MarkType ).arg( QDateTime::currentDateTime().date().year() ).arg( QDir::separator() ).arg( QDateTime::currentDateTime().date().month() ).arg( QDateTime::currentDateTime().date().day() ).arg( QDateTime::currentDateTime().time().hour() ).arg( QDateTime::currentDateTime().time().minute()).arg(Subname);
        QFile file;
        file.setFileName(fileName);
        file.open(QIODevice::Append| QIODevice::Text);
        QTextStream write(&file);
        write<<ui->textEdit->toPlainText();

        msgBox.setText(QString("Log file saved at %1").arg(fileName) );
        msgBox.setWindowTitle("Update Log saved");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
        this->close();
        file.close();

    }
    else{
        msgBox.setText("Log file not saved. Problem with directory structure" );
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("ERROR");
        msgBox.exec();
    }


qDebug() << Q_FUNC_INFO <<"end";


}

void LogWindow::on_pushButton_clicked()
{
    this->close();
}
