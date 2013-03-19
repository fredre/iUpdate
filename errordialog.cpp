#include "errordialog.h"
#include "ui_errordialog.h"

errorDialog::errorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::errorDialog)
{
    ui->setupUi(this);
}

errorDialog::~errorDialog()
{
    delete ui;
}

//added
void errorDialog::displayErrors( QStringList errorlist ){

    ui->lstdisplayErrors->clear();
    ui->lstdisplayErrors->addItems(errorlist);
}


void errorDialog::on_btnclose_clicked()
{
    close();
}
