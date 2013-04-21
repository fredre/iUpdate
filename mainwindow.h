#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
//#include <QWebFrame>
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
#include "errorwindow.h"

//added
#include <QStringList>
#include "errordialog.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow( QWidget *parent = 0 );
    ~MainWindow();
    QSettings IUpdatesettings;

    //added
    QStringList getErrorList();
    void setErrorlist(QStringList);
    int CheckCoulumnMarkAvailability(QString mt);
    void setComboBox();

    Q_INVOKABLE void on_JS_Subject_change(QString); //When the user selects a different subject

private slots:
    void on_pushButton_clicked();

    void on_webViewBrowser_loadProgress( int progress );

    void on_webViewBrowser_loadStarted();

    void on_webViewBrowser_loadFinished( bool );

    void on_webViewBrowser_anyError( QString );

    void on_webViewBrowser_networkError( QString );

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

    void CsvFileParseError( QString );


    void on_comboBoxMarkTypeSlct_currentIndexChanged( const QString &arg1 );

    void on_webViewSubjectInfo_loadFinished( bool arg1 );

    void on_webViewSubjectInfo_loadStarted();

    void on_actionLoad_Local_Tes_triggered();

    void on_actionGo_back_to_login_page_triggered();

    void addJSObject();

private:
    Ui::MainWindow *ui;
    DocInterface csvInter;
    void hideSideWindow();
    void showSideWindow();
    QStringList errorlist;
    ErrorWindow *errorwindow = new ErrorWindow( this );

};

#endif // MAINWINDOW_H
