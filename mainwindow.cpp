
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "qdebug.h"
#include <QNetworkDiskCache>

#ifdef Q_OS_WIN //This may not be needed (unless the entire TUT switch to Linux from Monday)
    #include "Templates\html_template.h"
#endif

#ifdef Q_OS_LINUX
    #include "Templates/html_template.h"
#endif


#include <QTextEdit>

using namespace std;
using namespace tmpl;


<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qDebug() << Q_FUNC_INFO <<"start";

    ui->setupUi(this);

<<<<<<< HEAD
<<<<<<< HEAD
    //Setup the setting class
    QCoreApplication::setOrganizationName("TUT");
    QCoreApplication::setOrganizationDomain("tut.ac.za");
    QCoreApplication::setApplicationName("IUpdate");
=======
MainWindow::MainWindow( QWidget *parent ) :
    QMainWindow( parent ),
    ui( new Ui::MainWindow )
{
    qDebug() << Q_FUNC_INFO <<"start";

    ui->setupUi( this );

    //Setup the settings class
    QCoreApplication::setOrganizationName( "TUT" );
    QCoreApplication::setOrganizationDomain( "tut.ac.za" );
    QCoreApplication::setApplicationName( "IUpdate" );
>>>>>>> 0bf96991929a539aac0a172bd103e1896b41bdda
=======
=======
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
    //Setup the settings class
    QCoreApplication::setOrganizationName("TUT");
    QCoreApplication::setOrganizationDomain("tut.ac.za");
    QCoreApplication::setApplicationName("IUpdate");
<<<<<<< HEAD
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9



    ui->progressBarWebInd->hide();
    ui->labelProgress->hide();

    hideSideWindow(); //Maximizes the splitter window


<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
    QMovie *movie = new QMovie(":/images/ajax-loader.gif");

    ui->labelProgress->setMovie(movie);
=======
    QMovie *movie = new QMovie( ":/images/ajax-loader.gif" );

    ui->labelProgress->setMovie( movie );
>>>>>>> 0bf96991929a539aac0a172bd103e1896b41bdda
=======
    QMovie *movie = new QMovie(":/images/ajax-loader.gif");

    ui->labelProgress->setMovie(movie);
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
    QMovie *movie = new QMovie(":/images/ajax-loader.gif");

    ui->labelProgress->setMovie(movie);
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9

    movie->start();

    //Hook up to the csv inter error reporter
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
     connect(&csvInter,SIGNAL(FileParseError(QString)),this,SLOT(CsvFileParseError(QString)));

    //Hook up to the loadprogress and loadstarted
    connect(ui->wFitsbrowser,SIGNAL(loadProgress (int)),this,SLOT(on_webViewBrowser_loadProgress(int)));
    connect(ui->wFitsbrowser,SIGNAL(loadStarted ()),this,SLOT(on_webViewBrowser_loadStarted()));
    connect(ui->wFitsbrowser,SIGNAL(loadFinished (bool)),this,SLOT(on_webViewBrowser_loadFinished(bool)));
    connect(ui->wFitsbrowser,SIGNAL(onAnyError(QString)),this,SLOT(on_webViewBrowser_anyError(QString)));
    connect(ui->wFitsbrowser,SIGNAL(onNetworkError(QString)),this,SLOT(on_webViewBrowser_networkError(QString)));

    ui->wFitsbrowser->setUrl(QUrl("https://jupiter.tut.ac.za/staffportal/system/login.php?refscript=/staffportal/index.php"));



    QNetworkDiskCache *diskCache = new QNetworkDiskCache(this);
    diskCache->setCacheDirectory("cachedir");
    ui->webViewSubjectInfo->page()->networkAccessManager()->setCache(diskCache );
<<<<<<< HEAD
<<<<<<< HEAD
=======
     connect( &csvInter,SIGNAL( FileParseError( QString ) ),this,SLOT( CsvFileParseError( QString ) ) );

    //Hook up to the loadprogress and loadstarted
    connect(ui->wFitsbrowser,SIGNAL( loadProgress( int ) ),this,SLOT( on_webViewBrowser_loadProgress( int ) ) );
    connect(ui->wFitsbrowser,SIGNAL( loadStarted () ),this,SLOT( on_webViewBrowser_loadStarted() ) );
    connect(ui->wFitsbrowser,SIGNAL( loadFinished ( bool ) ),this,SLOT(on_webViewBrowser_loadFinished( bool ) ) );
    connect(ui->wFitsbrowser,SIGNAL( onAnyError( QString ) ),this,SLOT( on_webViewBrowser_anyError( QString ) ) );
    connect(ui->wFitsbrowser,SIGNAL( onNetworkError( QString ) ),this,SLOT( on_webViewBrowser_networkError( QString ) ) );

    ui->wFitsbrowser->setUrl( QUrl( "https://jupiter.tut.ac.za/staffportal/system/login.php?refscript=/staffportal/index.php" ) );



    QNetworkDiskCache *diskCache = new QNetworkDiskCache( this );
    diskCache->setCacheDirectory( "cachedir" );
    ui->webViewSubjectInfo->page()->networkAccessManager()->setCache( diskCache );
>>>>>>> 0bf96991929a539aac0a172bd103e1896b41bdda
=======
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9


  qDebug() << Q_FUNC_INFO <<"end";

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

}

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
 void MainWindow::on_webViewBrowser_networkError(QString error)
=======
 void MainWindow::on_webViewBrowser_networkError( QString error )
>>>>>>> 0bf96991929a539aac0a172bd103e1896b41bdda
=======
 void MainWindow::on_webViewBrowser_networkError(QString error)
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
 void MainWindow::on_webViewBrowser_networkError(QString error)
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
 {
     qDebug() << Q_FUNC_INFO <<"start";

     qDebug()<<error;

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
      tmpl::html_template errorPage(":/templ/conerror.tmpl");


      errorPage("ERMES") = error.toStdString();
<<<<<<< HEAD
<<<<<<< HEAD
=======
      tmpl::html_template errorPage( ":/templ/conerror.tmpl" );


      errorPage( "ERMES" ) = error.toStdString();
>>>>>>> 0bf96991929a539aac0a172bd103e1896b41bdda
=======
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9

 \
     // ui->wFitsbrowser->setHtml(QString::fromStdString(errorPage.Process()));



      qDebug() << Q_FUNC_INFO <<"end";
 }

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
void MainWindow::on_webViewBrowser_anyError(QString error)
{
    qDebug() << Q_FUNC_INFO <<"start";

    ui->statusBar->showMessage("Error on browser load: "+error);
<<<<<<< HEAD
<<<<<<< HEAD
=======
void MainWindow::on_webViewBrowser_anyError( QString error )
{
    qDebug() << Q_FUNC_INFO <<"start";

    ui->statusBar->showMessage( "Error on browser load: "+error );
>>>>>>> 0bf96991929a539aac0a172bd103e1896b41bdda
=======
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9

    qDebug() << Q_FUNC_INFO <<"end";
}

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
void MainWindow::on_webViewBrowser_loadProgress(int progress)
{
   qDebug() << Q_FUNC_INFO <<"start";
   ui->progressBarWebInd->setValue(progress);
<<<<<<< HEAD
<<<<<<< HEAD
=======
void MainWindow::on_webViewBrowser_loadProgress( int progress )
{
   qDebug() << Q_FUNC_INFO <<"start";
   ui->progressBarWebInd->setValue( progress );
>>>>>>> 0bf96991929a539aac0a172bd103e1896b41bdda
=======
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
   qDebug() << Q_FUNC_INFO <<"end";
}

void MainWindow::on_webViewBrowser_loadStarted()
{
    qDebug() << Q_FUNC_INFO <<"start";
    ui->progressBarWebInd->show();
    ui->labelProgress->show();
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
    ui->statusBar->showMessage(ui->wFitsbrowser->url().toString());
    qDebug() << Q_FUNC_INFO <<"end";
}

void MainWindow::on_webViewBrowser_loadFinished(bool ok)
<<<<<<< HEAD
<<<<<<< HEAD
=======
    ui->statusBar->showMessage( ui->wFitsbrowser->url().toString() );
    qDebug() << Q_FUNC_INFO <<"end";
}

void MainWindow::on_webViewBrowser_loadFinished( bool ok )
>>>>>>> 0bf96991929a539aac0a172bd103e1896b41bdda
=======
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
{
qDebug() << Q_FUNC_INFO <<"start";
    ui->progressBarWebInd->hide();
    ui->labelProgress->hide();
    ui->statusBar->clearMessage();
qDebug() << Q_FUNC_INFO <<"end";
}

void MainWindow::on_actionAbout_triggered()
{
    qDebug() << Q_FUNC_INFO <<"start";
    QMessageBox::about( this, "ITS Update",
                       "Copyright (C) <2010>  <Fredre Hattingh>\n\n<hattinghfg@tut.ac.za>\n\n"

                         "This program comes with ABSOLUTELY NO WARRANTY\n\n\n"

                           "This program is free software: you can redistribute it and/or modify\n"
                           "it under the terms of the GNU General Public License as published by\n"
                           "the Free Software Foundation, either version 3 of the License, or\n"
                           "(at your option) any later version.\n\n"

                           "This program is distributed in the hope that it will be useful,\n"
                           "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
                           "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
                           "GNU General Public License for more details.\n\n"

                           "You should have received a copy of the GNU General Public License\n"
                           "along with this program.  If not, see <http://www.gnu.org/licenses/>.\n"
                       );

qDebug() << Q_FUNC_INFO <<"end";
}

void MainWindow::on_actionAbout_QT_triggered()
{
    qDebug() << Q_FUNC_INFO <<"start";
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
    QMessageBox::aboutQt (this);
=======
    QMessageBox::aboutQt ( this );
>>>>>>> 0bf96991929a539aac0a172bd103e1896b41bdda
=======
    QMessageBox::aboutQt (this);
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
    QMessageBox::aboutQt (this);
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
    qDebug() << Q_FUNC_INFO <<"end";
}

void MainWindow::on_actionLoad_triggered()
{
    qDebug() << Q_FUNC_INFO <<"start";
    ui->labelProgress->show();

    //First try to load settings
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
    QString lstload = IUpdatesettings.value("lastLoadPath",QDir::homePath()).toString();

    csvInter.setFilePath(QFileDialog::getOpenFileName(this,tr("Open %1 Marks File").arg(csvInter.getFileTypeName()), lstload, tr("%1").arg(csvInter.getFileExt())));

    if(csvInter.loadFile())
    {
    //Update setting
    QDir d = QFileInfo(csvInter.FilePath()).absoluteDir();

    IUpdatesettings.setValue("lastLoadPath",d.absolutePath());
<<<<<<< HEAD
<<<<<<< HEAD
=======
    QString lstload = IUpdatesettings.value( "lastLoadPath",QDir::homePath() ).toString();

    csvInter.SetFilePath(QFileDialog::getOpenFileName( this,tr( "Open %1 Marks File" ).arg( csvInter.GetFileTypeName() ), lstload, tr( "%1" ).arg( csvInter.GetFileExt() ) ) );

    if ( csvInter.LoadFile() ){

    //Update setting
    QDir d = QFileInfo( csvInter.FilePath() ).absoluteDir();

    IUpdatesettings.setValue( "lastLoadPath",d.absolutePath() );
>>>>>>> 0bf96991929a539aac0a172bd103e1896b41bdda
=======
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9

    //PopulateSubjectGrid();
     PopulateSubjectWeb();

    //ADD POPULATE HTML INFO HERE


    //Load the marktypes into the combo box
    ui->comboBoxMarkTypeSlct->clear();
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
>>>>>>> Serame-master
=======
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
    ui->comboBoxMarkTypeSlct->addItems(csvInter.getMarkTypesList());

    showSideWindow();

    }
    else
    {
<<<<<<< HEAD
<<<<<<< HEAD
=======
    ui->comboBoxMarkTypeSlct->addItems( csvInter.getMarkTypesList() );
=======
    ui->comboBoxMarkTypeSlct->addItems( csvInter.GetMarkTypesList() );
>>>>>>> 9741ee93263e965794ac363168e703497d496a37

    showSideWindow();

    } else {

>>>>>>> 0bf96991929a539aac0a172bd103e1896b41bdda
=======
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
        qDebug()<<"File not loaded (Perhaps cancell was clicked)";
    }
    ui->labelProgress->hide();
    qDebug() << Q_FUNC_INFO <<"end";
}


 void MainWindow::PopulateSubjectGrid()
 {
     /*
     //Not used anymore ! Rather have a single template with everything needed in html loaded in webview

    qDebug() << Q_FUNC_INFO <<"start";

    //Clear all from the table
    ui->tableSubjecInfo->clear();
    ui->tableSubjecInfo->setRowCount(4);

    //Setup the table for subject info by adding the headers
    QTableWidgetItem *newItem = new QTableWidgetItem("Subject Name: ");
    ui->tableSubjecInfo->setVerticalHeaderItem(0,newItem);

    QTableWidgetItem *newItem1 = new QTableWidgetItem("Total Students: ");
    ui->tableSubjecInfo->setVerticalHeaderItem(1,newItem1);

    QTableWidgetItem *newItem2 = new QTableWidgetItem("First Student: ");
    ui->tableSubjecInfo->setVerticalHeaderItem(2,newItem2);

    QTableWidgetItem *newItem3 = new QTableWidgetItem("Last Student: ");
    ui->tableSubjecInfo->setVerticalHeaderItem(3,newItem3);

    //Add the info for the headers
<<<<<<< HEAD
     QTableWidgetItem *NameItm = new QTableWidgetItem(csvInter.GetSubjectCode());
     ui->tableSubjecInfo->setItem(0,0,NameItm);

     QTableWidgetItem *TCountItm = new QTableWidgetItem(tr("%1").arg(csvInter.GetStudentCount()));
     ui->tableSubjecInfo->setItem(1,0,TCountItm);

     QTableWidgetItem *frstStuItm = new QTableWidgetItem(csvInter.GetFirstStudentNumber());
     ui->tableSubjecInfo->setItem(2,0,frstStuItm);

     QTableWidgetItem *lsttStuItm = new QTableWidgetItem(csvInter.GetLastStudentNumber     ui->tableSubjecInfo->setItem(3,0,lsttStuItm);

     ui->tableSubjecInfo->setRowCount(ui->tableSubjecInfo->rowCount()+csvInter.GetMarkTypesCount());

     for(int a=0,x=4;a < csvInter.GetMarkTypesList().count();a++,x++)
     {
         //Add the header for each marktype
         ui->tableSubjecInfo->setVerticalHeaderItem(x,new QTableWidgetItem(tr("Mark Type: %1").arg(csvInter.GetMarkTypesList()[a])));
=======
     QTableWidgetItem *NameItm = new QTableWidgetItem(csvInter.getSubjectCode());
     ui->tableSubjecInfo->setItem(0,0,NameItm);

     QTableWidgetItem *TCountItm = new QTableWidgetItem(tr("%1").arg(csvInter.getStudentCount()));
     ui->tableSubjecInfo->setItem(1,0,TCountItm);

     QTableWidgetItem *frstStuItm = new QTableWidgetItem(csvInter.getFirstStudentNumber());
     ui->tableSubjecInfo->setItem(2,0,frstStuItm);

     QTableWidgetItem *lsttStuItm = new QTableWidgetItem(csvInter.getLastStudentNumber());
     ui->tableSubjecInfo->setItem(3,0,lsttStuItm);

     ui->tableSubjecInfo->setRowCount(ui->tableSubjecInfo->rowCount()+csvInter.getMarkTypesCount());

     for(int a=0,x=4;a < csvInter.getMarkTypesList().count();a++,x++)
     {
         //Add the header for each marktype
         ui->tableSubjecInfo->setVerticalHeaderItem(x,new QTableWidgetItem(tr("Mark Type: %1").arg(csvInter.getMarkTypesList()[a])));
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9

         //Insert a new tEXTeDIT
         //QTextEdit *mtDetails = new QTextEdit(this);
         //mtDetails->setStyleSheet(" border: 1px solid gray;padding: 4px;border-radius: 6px;");

         //Insert a new QWebView
         QWebView *mtDetails;
         mtDetails = new QWebView(this);

         tmpl::html_template one(":/templ/mtdetails.tmpl");

<<<<<<< HEAD
         one("NUMMARKS") =  csvInter.GetMarkTypeTotalNumberMarks(csvInter.GetMarkTypesList()[a]);
         one("MISMARKS") = csvInter.GetStudentCount()-csvInter.GetMarkTypeTotalNumberMarks(csvInter.GetMarkTypesList()[a]);
=======
         one("NUMMARKS") =  csvInter.getMarkTypeTotalNumberMarks(csvInter.getMarkTypesList()[a]);
         one("MISMARKS") = csvInter.getStudentCount()-csvInter.getMarkTypeTotalNumberMarks(csvInter.getMarkTypesList()[a]);
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9

         mtDetails->setHtml(QString::fromStdString(one.Process()));

         ui->tableSubjecInfo->setCellWidget(x,0, mtDetails);
     }

     ui->tableSubjecInfo->verticalHeader()->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);
     ui->tableSubjecInfo->verticalHeaderItem(3)->setSizeHint(QSize(120,120));

     ui->tableSubjecInfo->resizeColumnsToContents();
     ui->tableSubjecInfo->resizeRowsToContents();
qDebug() << Q_FUNC_INFO <<"end";
 */
 }

 void  MainWindow::PopulateSubjectWeb()
 {
     qDebug() << Q_FUNC_INFO <<"start";

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
     tmpl::html_template one(":/templ/mtdetails.tmpl");
=======
     tmpl::html_template one( ":/templ/mtdetails.tmpl" );
>>>>>>> 0bf96991929a539aac0a172bd103e1896b41bdda
=======
     tmpl::html_template one(":/templ/mtdetails.tmpl");
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
     tmpl::html_template one(":/templ/mtdetails.tmpl");
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9

     loop_t loop_marktypes;


     row_t row_marktypes;


     //Get all the marktypes and add a row
<<<<<<< HEAD
     QStringList marktypes = csvInter.GetMarkTypesList();
     qDebug()<<marktypes.count();

<<<<<<< HEAD
<<<<<<< HEAD
    for(int a=0;a < marktypes.count();a++)
=======
    for( int a=0;a < marktypes.count();a++ )
>>>>>>> 0bf96991929a539aac0a172bd103e1896b41bdda
=======
    for(int a=0;a < marktypes.count();a++)
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
     QStringList marktypes = csvInter.getMarkTypesList();
     qDebug()<<marktypes.count();

    for(int a=0;a < marktypes.count();a++)
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
     {

        QString mtName = marktypes[a];

        qDebug()<<mtName;

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
       row_marktypes("name") = mtName.toStdString();
       row_marktypes("nummarks") = csvInter.getMarkTypeTotalNumberMarks(mtName);
       row_marktypes("mismarks") = csvInter.getStudentCount()-csvInter.getMarkTypeTotalNumberMarks(mtName);
=======
       row_marktypes( "name" ) = mtName.toStdString();
<<<<<<< HEAD
       row_marktypes( "nummarks" ) = csvInter.getMarkTypeTotalNumberMarks( mtName );
       row_marktypes( "mismarks" ) = csvInter.getStudentCount()-csvInter.getMarkTypeTotalNumberMarks( mtName );
>>>>>>> 0bf96991929a539aac0a172bd103e1896b41bdda
=======
<<<<<<< HEAD
       row_marktypes("name") = mtName.toStdString();
       row_marktypes("nummarks") = csvInter.getMarkTypeTotalNumberMarks(mtName);
       row_marktypes("mismarks") = csvInter.getStudentCount()-csvInter.getMarkTypeTotalNumberMarks(mtName);
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
       row_marktypes( "nummarks" ) = csvInter.GetMarkTypeTotalNumberMarks( mtName );
       row_marktypes( "mismarks" ) = csvInter.GetStudentCount()-csvInter.GetMarkTypeTotalNumberMarks( mtName );
>>>>>>> 9741ee93263e965794ac363168e703497d496a37
>>>>>>> Serame-master
=======
       row_marktypes("name") = mtName.toStdString();
       row_marktypes("nummarks") = csvInter.getMarkTypeTotalNumberMarks(mtName);
       row_marktypes("mismarks") = csvInter.getStudentCount()-csvInter.getMarkTypeTotalNumberMarks(mtName);
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9


       //Loop start
        loop_t loop_marks;
        row_t row_marks;

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
>>>>>>> Serame-master
=======
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
        QMap<QString,int>  marks= csvInter.getAllMarksPerMarkType(mtName);


         QMapIterator<QString, int> i(marks); //For each marktype get the marks and stu num then add to loop marks
         while (i.hasNext()) {
             i.next();
             QString onemark = QString("%1").arg(i.value());
             QString stunumber = i.key();
             row_marks("onemark") = onemark.toStdString();
             row_marks("stunumber") = stunumber.toStdString();
<<<<<<< HEAD
<<<<<<< HEAD
=======
        QMap<QString,int>  marks= csvInter.getAllMarksPerMarkType( mtName );
=======
        QMap<QString,int>  marks= csvInter.GetAllMarksPerMarkType( mtName );
>>>>>>> 9741ee93263e965794ac363168e703497d496a37


         QMapIterator<QString, int> i( marks ); //For each marktype get the marks and stu num then add to loop marks
         while ( i.hasNext() ) {
             i.next();
             QString onemark = QString( "%1" ).arg( i.value() );
             QString stunumber = i.key();
             row_marks( "onemark" ) = onemark.toStdString();
             row_marks( "stunumber" ) = stunumber.toStdString();
>>>>>>> 0bf96991929a539aac0a172bd103e1896b41bdda
=======
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
            loop_marks+=row_marks;

        }


<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
       row_marktypes("allmarks") = loop_marks; //Now add loop_marks as a row to the orig loop called loop_marktypes (See template docss for more info)
=======
       row_marktypes( "allmarks" ) = loop_marks; //Now add loop_marks as a row to the orig loop called loop_marktypes (See template docss for more info)
>>>>>>> 0bf96991929a539aac0a172bd103e1896b41bdda
=======
       row_marktypes("allmarks") = loop_marks; //Now add loop_marks as a row to the orig loop called loop_marktypes (See template docss for more info)
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
       row_marktypes("allmarks") = loop_marks; //Now add loop_marks as a row to the orig loop called loop_marktypes (See template docss for more info)
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
       loop_marktypes += row_marktypes;
       loop_marks.Empty();

       //Loop end



      }

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
     one("MARKTYPES") = loop_marktypes;


     one("NUMMARKS") =  csvInter.getMarkTypeTotalNumberMarks(csvInter.getMarkTypesList()[0]);
     one("MISMARKS") = csvInter.getStudentCount()-csvInter.getMarkTypeTotalNumberMarks(csvInter.getMarkTypesList()[0]);
<<<<<<< HEAD
<<<<<<< HEAD
=======
     one( "MARKTYPES" ) = loop_marktypes;


<<<<<<< HEAD
     one( "NUMMARKS" ) =  csvInter.getMarkTypeTotalNumberMarks( csvInter.getMarkTypesList()[0] );
     one( "MISMARKS" ) = csvInter.getStudentCount()-csvInter.getMarkTypeTotalNumberMarks( csvInter.getMarkTypesList()[0] );
>>>>>>> 0bf96991929a539aac0a172bd103e1896b41bdda
=======
<<<<<<< HEAD
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
     one( "NUMMARKS" ) =  csvInter.GetMarkTypeTotalNumberMarks( csvInter.GetMarkTypesList()[0] );
     one( "MISMARKS" ) = csvInter.GetStudentCount()-csvInter.GetMarkTypeTotalNumberMarks( csvInter.GetMarkTypesList()[0] );
>>>>>>> 9741ee93263e965794ac363168e703497d496a37
>>>>>>> Serame-master
=======
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9

    // ui->webViewSubjectInfo->setc

    // ui->webViewSubjectInfo->settings()->setUserStyleSheetUrl(QUrl::from);

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
     ui->webViewSubjectInfo->setHtml(QString::fromStdString(one.Process()));
=======
     ui->webViewSubjectInfo->setHtml( QString::fromStdString(one.Process() ) );
>>>>>>> 0bf96991929a539aac0a172bd103e1896b41bdda
=======
     ui->webViewSubjectInfo->setHtml(QString::fromStdString(one.Process()));
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
     ui->webViewSubjectInfo->setHtml(QString::fromStdString(one.Process()));
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
     qDebug() << Q_FUNC_INFO <<"end";

}


 void MainWindow::hideSideWindow()
{
    qDebug() << Q_FUNC_INFO <<"start";
     ui->pushButtonUpdateMrks->hide();
     ui->comboBoxMarkTypeSlct->hide();
     ui->webViewSubjectInfo->hide();
     QList<int> currentSizes = ui->splitter->sizes();
     // adjust sizes individually

     currentSizes[1] = ui->wFitsbrowser->width();

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
     ui->splitter->setSizes(currentSizes);
=======
     ui->splitter->setSizes( currentSizes );
>>>>>>> 0bf96991929a539aac0a172bd103e1896b41bdda
=======
     ui->splitter->setSizes(currentSizes);
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
     ui->splitter->setSizes(currentSizes);
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
     qDebug() << Q_FUNC_INFO <<"end";
 }

 void MainWindow::showSideWindow()
 {
     qDebug() << Q_FUNC_INFO <<"start";
     ui->pushButtonUpdateMrks->show();
     ui->comboBoxMarkTypeSlct->show();
     ui->webViewSubjectInfo->show();

     QList<int> currentSizes = ui->splitter->sizes();
     // adjust sizes individually

     currentSizes[0] = 0;
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
     currentSizes[0] = (this->width() * 25/100);

     ui->splitter->setSizes(currentSizes);
=======
     currentSizes[0] = ( this->width() * 25/100 );

     ui->splitter->setSizes( currentSizes );
>>>>>>> 0bf96991929a539aac0a172bd103e1896b41bdda
=======
     currentSizes[0] = (this->width() * 25/100);

     ui->splitter->setSizes(currentSizes);
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
     currentSizes[0] = (this->width() * 25/100);

     ui->splitter->setSizes(currentSizes);
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
     qDebug() << Q_FUNC_INFO <<"end";
 }

void MainWindow::on_pushButtonUpdateMrks_clicked()
{
    qDebug() << Q_FUNC_INFO <<"start";

    //qDebug()<<"Testing getInblrMark (Student With mark) :";
    //qDebug() <<ui->wFitsbrowser->getInblrMark("200300154");
    //qDebug()<<"Testing getInblrMark (Student With empty mark) :";
    //qDebug() <<ui->wFitsbrowser->getInblrMark("200000844");

    //qDebug()<<"Testing setInblrMark (200300154 --> 40): " ;
    //ui->wFitsbrowser->setInblrMark("200300154",40);

    //qDebug()<<"Testing InblrContainsStuNum (200300154): Should be true: ";
    //qDebug()<<ui->wFitsbrowser->InblrContainsStuNum("200300154");

    //qDebug()<<"Testing InblrContainsStuNum (204063982): Should be false: ";
    //qDebug()<<ui->wFitsbrowser->InblrContainsStuNum("204063982");

    ui->labelProgress->show();

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
    QStringList stunumbers = csvInter.getAllStudentNumbersPerMarkType(ui->comboBoxMarkTypeSlct->currentText());
=======
    QStringList stunumbers = csvInter.getAllStudentNumbersPerMarkType( ui->comboBoxMarkTypeSlct->currentText() );
>>>>>>> 0bf96991929a539aac0a172bd103e1896b41bdda
=======
<<<<<<< HEAD
    QStringList stunumbers = csvInter.getAllStudentNumbersPerMarkType(ui->comboBoxMarkTypeSlct->currentText());
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
    QStringList stunumbers = csvInter.GetAllStudentNumbersPerMarkType( ui->comboBoxMarkTypeSlct->currentText() );
>>>>>>> 9741ee93263e965794ac363168e703497d496a37
>>>>>>> Serame-master
=======
    QStringList stunumbers = csvInter.getAllStudentNumbersPerMarkType(ui->comboBoxMarkTypeSlct->currentText());
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9

    LogWindow *UpdateMarksLog = new LogWindow();

    QStringList logErrors;
    QStringList logWarnings;
    QStringList logInformation;

    qDebug()<<"--- ITS Update trunc version ---";
    qDebug()<<"Updating marks";
    qDebug()<<QDateTime::currentDateTime().toString();
    qDebug()<<"File Name:" <<csvInter.FilePath();
    qDebug()<<"Mark Type: "<<ui->comboBoxMarkTypeSlct->currentText();
    qDebug()<<"";

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
   UpdateMarksLog->addUpdateHeader(csvInter.FilePath(),ui->comboBoxMarkTypeSlct->currentText(),csvInter.getSubjectCode());
=======
   UpdateMarksLog->AddUpdateHeader(csvInter.FilePath(),ui->comboBoxMarkTypeSlct->currentText(),csvInter.getSubjectCode());
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
   UpdateMarksLog->addUpdateHeader(csvInter.FilePath(),ui->comboBoxMarkTypeSlct->currentText(),csvInter.getSubjectCode());
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9


    foreach (const QString snum,stunumbers)
    {
        qDebug()<<"Updating student number: "<<snum;

        if(!ui->wFitsbrowser->InblrContainsStuNum(snum))
        {
            logErrors.append(tr("Student not found on Inabler: %1 No update made").arg(snum));
            qDebug()<<"Student "<<snum<< "not found on Inabler";
            qDebug()<<"MARK NOT UPDATED "<<snum;
        }
       else
        {
<<<<<<< HEAD
<<<<<<< HEAD
=======
   UpdateMarksLog->addUpdateHeader( csvInter.FilePath(),ui->comboBoxMarkTypeSlct->currentText(),csvInter.getSubjectCode() );
=======
   UpdateMarksLog->addUpdateHeader( csvInter.FilePath(),ui->comboBoxMarkTypeSlct->currentText(),csvInter.GetSubjectCode() );
>>>>>>> 9741ee93263e965794ac363168e703497d496a37


    foreach ( const QString snum,stunumbers )
    {
        qDebug()<<"Updating student number: "<<snum;

        if( !ui->wFitsbrowser->InblrContainsStuNum( snum ) ){

            logErrors.append( tr( "Student not found on Inabler: %1 No update made" ).arg( snum ) );
            qDebug()<<"Student "<<snum<< "not found on Inabler";
            qDebug()<<"MARK NOT UPDATED "<<snum;
        }else{

>>>>>>> 0bf96991929a539aac0a172bd103e1896b41bdda
=======
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
            int oldm = ui->wFitsbrowser->getInblrMark(snum);
=======
            int oldm = ui->wFitsbrowser->GetInblrMark(snum);
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
            QString oldMark;
            oldMark = tr("%1").arg(oldm);
            qDebug()<<"Old mark: ";
            qDebug()<< oldMark;
            qDebug()<<"New mark: ";
<<<<<<< HEAD
            int newmark = csvInter.GetStudentMarkPerMarkType(ui->comboBoxMarkTypeSlct->currentText(),snum);
            qDebug()<<newmark;

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
            int newmark = csvInter.getStudentMarkPerMarkType(ui->comboBoxMarkTypeSlct->currentText(),snum);
            qDebug()<<newmark;

>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
            if(oldm > newmark)
            {
                logWarnings.append(tr("Student %3 Old mark  (%1) > (%2) No update made").arg(oldMark).arg(newmark).arg(snum));
            }
            else
            {

<<<<<<< HEAD
            ui->wFitsbrowser->setInblrMark(snum,newmark);

            logInformation.append(tr("Mark Updated %3 : %1 --> %2").arg(oldMark).arg(newmark).arg(snum));
<<<<<<< HEAD
=======
            if( oldm > newmark ){

                logWarnings.append( tr( "Student %3 Old mark  ( %1 ) > ( %2 ) No update made" ).arg( oldMark ).arg( newmark ).arg( snum ) );
            }else{

            ui->wFitsbrowser->setInblrMark( snum,newmark );

            logInformation.append(tr( "Mark Updated %3 : %1 --> %2" ).arg( oldMark ).arg( newmark ).arg( snum ) );
>>>>>>> 0bf96991929a539aac0a172bd103e1896b41bdda
=======
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
            ui->wFitsbrowser->SetInblrMark(snum,newmark);

            logInformation.append(tr("Mark Updated %3 : %1 --> %2").arg(oldMark).arg(newmark).arg(snum));
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
            }
        }


      qDebug()<<"";

    }
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
UpdateMarksLog->addErrors(logErrors);
UpdateMarksLog->addWarning(logWarnings);
UpdateMarksLog->addInformation(logInformation);
=======
UpdateMarksLog->addErrors( logErrors );
UpdateMarksLog->addWarning( logWarnings );
UpdateMarksLog->addInformation( logInformation );
>>>>>>> 0bf96991929a539aac0a172bd103e1896b41bdda
=======
UpdateMarksLog->AddErrors(logErrors);
UpdateMarksLog->AddWarning(logWarnings);
UpdateMarksLog->AddInformation(logInformation);
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
UpdateMarksLog->addErrors(logErrors);
UpdateMarksLog->addWarning(logWarnings);
UpdateMarksLog->addInformation(logInformation);
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
ui->labelProgress->hide();
UpdateMarksLog->show();
qDebug() << Q_FUNC_INFO <<"end";
}

void MainWindow::on_actionMake_all_0_triggered()
{
    //Turn all the marks on iblr to 0
    //Will sound warning for every mark that is not 0

    qDebug() << Q_FUNC_INFO <<"start";

    QMessageBox msgBox;
     msgBox.setText("All the marks will be changed to 0");
     msgBox.setInformativeText("Are you sure ? This action cannot be undone !");
     msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
     msgBox.setDefaultButton(QMessageBox::No);
     int ret = msgBox.exec();

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
     switch (ret) {
=======
     switch ( ret ) {
>>>>>>> 0bf96991929a539aac0a172bd103e1896b41bdda
=======
     switch (ret) {
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
     switch (ret) {
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
        case QMessageBox::Yes:
            // Yes was clicked
             {
                qDebug()<<"Making all marks 0";
<<<<<<< HEAD
                ui->wFitsbrowser->setInblrMarkAllZero();
=======
                ui->wFitsbrowser->SetInblrMarkAllZero();
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
             }
            break;
        case QMessageBox::No:
            // No Save was clicked
            qDebug()<<"No was clicked";
        default:
            // should never be reached
            qDebug()<<"The fool closed the dialog";
            break;
      }
qDebug() << Q_FUNC_INFO <<"end";
}

void MainWindow::on_actionMake_empty_0_triggered()
{
    qDebug() << Q_FUNC_INFO <<"start";
<<<<<<< HEAD
    ui->wFitsbrowser->setInblrMarkZero();
=======
    ui->wFitsbrowser->SetInblrMarkZero();
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
    qDebug() << Q_FUNC_INFO <<"end";
}

void MainWindow::on_actionBlackout_Cancelled_triggered()
{
  qDebug() << Q_FUNC_INFO <<"start";
<<<<<<< HEAD
  ui->wFitsbrowser->setInblrCanBlackOut();
=======
  ui->wFitsbrowser->SetInblrCanBlackOut();
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
  qDebug() << Q_FUNC_INFO <<"end";
}

void MainWindow::on_actionLoad_ec_tut_ac_za_triggered()
{
   qDebug() << Q_FUNC_INFO <<"start";
   qDebug()<<"Testing to see if ec.tut.ac.za loads";
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
   ui->wFitsbrowser->setUrl(QUrl("http://ec.tut.ac.za"));
   qDebug() << Q_FUNC_INFO <<"end";
}

void MainWindow::CsvFileParseError(QString mes)
<<<<<<< HEAD
<<<<<<< HEAD
=======
   ui->wFitsbrowser->setUrl(QUrl( "http://ec.tut.ac.za" ) );
   qDebug() << Q_FUNC_INFO <<"end";
}

void MainWindow::CsvFileParseError( QString mes )
>>>>>>> 0bf96991929a539aac0a172bd103e1896b41bdda
=======
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
{
    qDebug() << Q_FUNC_INFO <<"start";
    //This slot will react to any errors when the CSv file is parced. It will report the message and the user must fix the problem.
    QMessageBox msgBox;
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
    QString messageToUser = QString("Error When Reading File:\n\n%1\n\nThe problem seems to be\n\n%2\n\nYou can still use the application but please fix the problem before continuing to avoid problems.").arg(csvInter.FilePath()).arg(mes);

    msgBox.setText(messageToUser);
    msgBox.setIcon(QMessageBox::Critical);
<<<<<<< HEAD
<<<<<<< HEAD
=======
    QString messageToUser = QString( "Error When Reading File:\n\n%1\n\nThe problem seems to be\n\n%2\n\nYou can still use the application but please fix the problem before continuing to avoid problems." ).arg( csvInter.FilePath() ).arg( mes );

    msgBox.setText( messageToUser );
    msgBox.setIcon( QMessageBox::Critical );
>>>>>>> 0bf96991929a539aac0a172bd103e1896b41bdda
=======
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
    msgBox.exec();
    qDebug() << Q_FUNC_INFO <<"end";

}

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
void MainWindow::on_comboBoxMarkTypeSlct_editTextChanged(const QString &arg1)
=======
void MainWindow::on_comboBoxMarkTypeSlct_editTextChanged( const QString &arg1 )
>>>>>>> 0bf96991929a539aac0a172bd103e1896b41bdda
=======
void MainWindow::on_comboBoxMarkTypeSlct_editTextChanged(const QString &arg1)
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
void MainWindow::on_comboBoxMarkTypeSlct_editTextChanged(const QString &arg1)
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
{

}

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
void MainWindow::on_comboBoxMarkTypeSlct_currentIndexChanged(const QString &arg1)
{
    qDebug()<<arg1;
    ui->webViewSubjectInfo->findText(QString(" "));
    ui->webViewSubjectInfo->findText(arg1,QWebPage::FindWrapsAroundDocument);
}

void MainWindow::on_webViewSubjectInfo_loadFinished(bool arg1)
<<<<<<< HEAD
<<<<<<< HEAD
=======
void MainWindow::on_comboBoxMarkTypeSlct_currentIndexChanged( const QString &arg1 )
{
    qDebug()<<arg1;
    ui->webViewSubjectInfo->findText( QString( " " ) );
    ui->webViewSubjectInfo->findText( arg1,QWebPage::FindWrapsAroundDocument );
}

void MainWindow::on_webViewSubjectInfo_loadFinished( bool arg1 )
>>>>>>> 0bf96991929a539aac0a172bd103e1896b41bdda
=======
>>>>>>> a4212718bf384bf0fceb4835198e3a3bc1d9ebad
=======
>>>>>>> 0513e5bed07b7f959d3fe8fb5ef149750a4012c9
{


}

void MainWindow::on_webViewSubjectInfo_loadStarted()
{

}
