#ifndef ERRORDIALOG_H
#define ERRORDIALOG_H

#include <QDialog>

#include <QStringList>

namespace Ui {
class errorDialog;
}

class errorDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit errorDialog(QWidget *parent = 0);
    ~errorDialog();

    //added
    void displayErrors( QStringList );
    
private slots:
    void on_btnOk_clicked();

    void on_btnclose_clicked();

private:
    Ui::errorDialog *ui;
};

#endif // ERRORDIALOG_H
