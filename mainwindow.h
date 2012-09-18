#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include <QWebFrame>
#include <QNetworkCookieJar>
#include <QMovie>
#include <QAuthenticator>
#include "docinterface.h"
#include <QFileDialog>
#include <QDir>
#include <QTableWidgetItem>
#include <QListWidget>
#include <QHeaderView>
#include <QDateTime>
#include <QNetworkProxy>
#include "logwindow.h"
#include <QSettings>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QSettings IUpdatesettings;

private slots:
    void on_pushButton_clicked();

    void on_webViewBrowser_loadProgress(int progress);

    void on_webViewBrowser_loadStarted();

    void on_webViewBrowser_loadFinished(bool );

    void on_webViewBrowser_anyError(QString);

    void on_actionAbout_triggered();

    void on_actionAbout_QT_triggered();

    void on_actionLoad_triggered();

    void PopulateSubjectGrid();
    void PopulateSubjectWeb();

    void on_pushButtonUpdateMrks_clicked();

    void on_actionMake_all_0_triggered();

    void on_actionMake_empty_0_triggered();

    void on_actionBlackout_Cancelled_triggered();

    void on_actionLoad_ec_tut_ac_za_triggered();

    void CsvFileParseError(QString);

private:
    Ui::MainWindow *ui;
    DocInterface csvInter;
    void hideSideWindow();
    void showSideWindow();

};

#endif // MAINWINDOW_H
