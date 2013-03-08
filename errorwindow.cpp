#include "errorwindow.h"
#include "ui_errorwindow.h"

//added
#include <QDir>
#include "docinterface.h"
#include <QFileDialog>
#include <QDebug>
#include <QFile>
#include <QDateTime>
#include <QIODevice>
#include <QtCore/QTextStream>
#include "mainwindow.h"

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
    ErrorWindow::setErrorList(errorlist);
}

void ErrorWindow::on_btnOk_clicked() {
    close();
}

QStringList ErrorWindow::getErrorList(){
    return errorList;
}

void ErrorWindow::setErrorList(QStringList errorList){
    this->errorList = errorList;
}


void ErrorWindow::on_btnSave_clicked()
{
    QString fileExtention = ".txt";


    QString directory = QFileDialog::getExistingDirectory(this,tr("Select a directory to save in"),QDir::currentPath(),QFileDialog::ShowDirsOnly);


    qDebug() << directory;

    if(directory != ""){
        qDebug() << "file not empty";

        QFile file;

        QString fileName = tr("%1/%2-%3-%4%5").arg(directory).arg(QDateTime::currentDateTime().date().day()).arg(QDateTime::currentDateTime().date().month()).arg(QDateTime::currentDateTime().date().year()).arg(fileExtention);

        file.setFileName(fileName);

        file.open(QIODevice::WriteOnly);
        qDebug() << file.fileName();

        QTextStream writer(&file);


        for(int i=0; i < errorList.size(); i++){

            writer << errorList.value(i);
            qDebug() << errorList.value(i);

        }

    }

}
