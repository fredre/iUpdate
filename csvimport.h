#ifndef CSVIMPORT_H
#define CSVIMPORT_H

#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QStandardItemModel>
#include <QSettings>
#include <QMenu>

#include <QJsonObject>
#include <QJsonValue>
#include <QJsonDocument>
#include <QJsonArray>
#include <QPalette>

namespace Ui {
class CSVImport;
}

class CSVImport : public QDialog
{
    Q_OBJECT
    
public:
    explicit CSVImport(QWidget *parent = 0);
    ~CSVImport();
     QSettings IUpdatesettings;
     QJsonDocument* getJDoc();

private slots:
    void on_action_Open_triggered();
    void checkString(QString &temp, QChar character = 0);
    
    void on_btnOpen_clicked();

    void on_tableView_customContextMenuRequested(const QPoint &pos);

    void customHeaderMenuRequested(QPoint pos);

      void customRowMenuRequested(QPoint pos);

    void on_actionSet_cell_as_subject_name_triggered();

    void on_actionSet_as_student_number_colomn_triggered();

    void on_actionSet_as_mark_type_row_triggered();

    void on_btnDone_clicked();

    void on_actionSet_as_last_row_triggered();

private:
    Ui::CSVImport *ui;

    QList<QStringList> csv;
    QStandardItemModel *model;
    QList<QStandardItem*> standardItemList;

    QModelIndex currRclickIndex;
    int currRclickcolumn;
    int  currRclickrow;
    int  currRclickLastrow;
     QJsonDocument *jdoc;

     enum LoadingStage { Step1, Step2, Step3, Step4, Step5, Step6 } CurrentStep;
     void guiSetStep();

signals:
    void JSonGenerated(QJsonDocument *generatedDoc);

};

#endif // CSVIMPORT_H
