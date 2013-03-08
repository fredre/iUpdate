#include "errorwindow.h"
#include "ui_errorwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

ErrorWindow::ErrorWindow( QWidget *parent ) :
    QMainWindow(parent),
    ui( new Ui::ErrorWindow ) {
    ui->setupUi( this) ;
}
ErrorWindow::~ErrorWindow() {
    delete ui;
}
void ErrorWindow::ErrorList( QStringList errorlist ) {

    ui->listWidget->clear();
    ui->listWidget->addItems(errorlist);
}

void ErrorWindow::on_btnOk_clicked() {
    close();
}



void ErrorWindow::on_btnSave_clicked()
{
    QString directory = QFileDialog::getExistingDirectory(this,tr("Choose or Create Directory"),"/home",QFileDialog::ShowDirsOnly|QFileDialog::DontUseNativeDialog);
        if(directory != "")
        {
            QFile file;
            QString fileName = tr("%1/%2%3%4").arg(directory).arg(QDateTime::currentDateTime().date().year()).arg(QDateTime::currentDateTime().date().dayOfWeek()).arg(".txt");
            file.setFileName(fileName);
            file.open(QIODevice::Append| QIODevice::Text);
            QTextStream write(&file);
            QList<QListWidgetItem *> items = ui->listWidget->findItems(QString("*"),Qt::MatchWrap|Qt::MatchWildcard);
            for(int x = 0; x<items.size();x++)
            {
                write<<items.at(x)->text()<<endl;
            }
            file.close();

            QMessageBox msgBox;
            QString message = tr("All errors Saved to directory %1").arg(directory);
            msgBox.setText(message);
            msgBox.setIcon(QMessageBox::Information);
            msgBox.exec();
            this->close();
        }
}
