#ifndef ERRORWINDOW_H
#define ERRORWINDOW_H

#include <QMainWindow>

namespace Ui {
class ErrorWindow;
}

class ErrorWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ErrorWindow(QWidget *parent = 0);
    ~ErrorWindow();
    void ErrorList( QStringList );
    void setErrorList( QStringList );
    QStringList getErrorList();

    
private slots:
    void on_btnOk_clicked();


    void on_btnSave_clicked();

private:
    Ui::ErrorWindow *ui;
    QStringList errorList;

};

#endif // ERRORWINDOW_H
