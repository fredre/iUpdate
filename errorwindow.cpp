#include "errorwindow.h"
#include "ui_errorwindow.h"

ErrorWindow::ErrorWindow( QWidget *parent ) :
    QMainWindow(parent),
    ui( new Ui::ErrorWindow )
{
    ui->setupUi( this) ;
}

ErrorWindow::~ErrorWindow()
{
    delete ui;
}
void ErrorWindow::ErrorList( QStringList errorlist ) {

    ui->listWidget->clear();
    ui->listWidget->addItems(errorlist);


}

void ErrorWindow::on_btnOk_clicked()
{
    close();
}

void ErrorWindow::on_btnCancel_clicked()
{
    ui->listWidget->clear();
}
