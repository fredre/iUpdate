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
    void ErrorList(QStringList );
    
private slots:
    void on_btnOk_clicked();

    void on_btnCancel_clicked();

private:
    Ui::ErrorWindow *ui;

};

#endif // ERRORWINDOW_H
