#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "qdebug.h"
#include <QNetworkDiskCache>
#include "errorwindow.h"

#ifdef Q_OS_WIN //This may not be needed (unless the entire TUT switch to Linux from Monday)
    #include "Templates\html_template.h"
#endif

#ifdef Q_OS_LINUX
    #include "Templates/html_template.h"
#endif


#include <QTextEdit>

using namespace std;
using namespace tmpl;


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



    ui->progressBarWebInd->hide();
    ui->labelProgress->hide();

    hideSideWindow(); //Maximizes the splitter window


    QMovie *movie = new QMovie( ":/images/ajax-loader.gif" );

    ui->labelProgress->setMovie( movie );

    movie->start();

    //Hook up to the csv inter error reporter
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


  qDebug() << Q_FUNC_INFO <<"end";

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

}

 void MainWindow::on_webViewBrowser_networkError( QString error )
 {
     qDebug() << Q_FUNC_INFO <<"start";

     qDebug()<<error;

      tmpl::html_template errorPage( ":/templ/conerror.tmpl" );


      errorPage( "ERMES" ) = error.toStdString();

 \
     // ui->wFitsbrowser->setHtml(QString::fromStdString(errorPage.Process()));



      qDebug() << Q_FUNC_INFO <<"end";
 }

void MainWindow::on_webViewBrowser_anyError( QString error )
{
    qDebug() << Q_FUNC_INFO <<"start";

    ui->statusBar->showMessage( "Error on browser load: "+error );

    qDebug() << Q_FUNC_INFO <<"end";
}

void MainWindow::on_webViewBrowser_loadProgress( int progress )
{
   qDebug() << Q_FUNC_INFO <<"start";
   ui->progressBarWebInd->setValue( progress );
   qDebug() << Q_FUNC_INFO <<"end";
}

void MainWindow::on_webViewBrowser_loadStarted()
{
    qDebug() << Q_FUNC_INFO <<"start";
    ui->progressBarWebInd->show();
    ui->labelProgress->show();
    ui->statusBar->showMessage( ui->wFitsbrowser->url().toString() );
    qDebug() << Q_FUNC_INFO <<"end";
}

void MainWindow::on_webViewBrowser_loadFinished( bool ok )
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
                       "Copyright (C) <2010> <Fredre Hattingh>\n\n<hattinghfg@tut.ac.za>\n\n"

                         "This program comes with ABSOLUTELY NO WARRANTY\n\n\n"

                           "This program is free software: you can redistribute it and/or modify\n"
                           "it under the terms of the GNU General Public License as published by\n"
                           "the Free Software Foundation, either version 3 of the License, or\n"
                           "(at your option) any later version.\n\n"

                           "This program is distributed in the hope that it will be useful,\n"
                           "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
                           "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the\n"
                           "GNU General Public License for more details.\n\n"

                           "You should have received a copy of the GNU General Public License\n"
                           "along with this program. If not, see <http://www.gnu.org/licenses/>.\n"
                       );

qDebug() << Q_FUNC_INFO <<"end";
}

void MainWindow::on_actionAbout_QT_triggered()
{
    qDebug() << Q_FUNC_INFO <<"start";
    QMessageBox::aboutQt ( this );
    qDebug() << Q_FUNC_INFO <<"end";
}

void MainWindow::on_actionLoad_triggered()
{
    qDebug() << Q_FUNC_INFO <<"start";
    ui->labelProgress->show();

    //First try to load settings
    QString lstload = IUpdatesettings.value( "lastLoadPath",QDir::homePath() ).toString();

    csvInter.SetFilePath(QFileDialog::getOpenFileName( this,tr( "Open %1 Marks File" ).arg( csvInter.GetFileTypeName() ), lstload, tr( "%1" ).arg( csvInter.GetFileExt() ) ) );

    if ( csvInter.LoadFile() ){

    //Update setting
    QDir d = QFileInfo( csvInter.FilePath() ).absoluteDir();

    IUpdatesettings.setValue( "lastLoadPath",d.absolutePath() );

    //PopulateSubjectGrid();
     PopulateSubjectWeb();

    //ADD POPULATE HTML INFO HERE


    //Load the marktypes into the combo box
    ui->comboBoxMarkTypeSlct->clear();
    ui->comboBoxMarkTypeSlct->addItems( csvInter.GetMarkTypesList() );

    showSideWindow();

    } else {

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
QTableWidgetItem *NameItm = new QTableWidgetItem(csvInter.GetSubjectCode());
ui->tableSubjecInfo->setItem(0,0,NameItm);

QTableWidgetItem *TCountItm = new QTableWidgetItem(tr("%1").arg(csvInter.GetStudentCount()));
ui->tableSubjecInfo->setItem(1,0,TCountItm);

QTableWidgetItem *frstStuItm = new QTableWidgetItem(csvInter.GetFirstStudentNumber());
ui->tableSubjecInfo->setItem(2,0,frstStuItm);

QTableWidgetItem *lsttStuItm = new QTableWidgetItem(csvInter.GetLastStudentNumber ui->tableSubjecInfo->setItem(3,0,lsttStuItm);

ui->tableSubjecInfo->setRowCount(ui->tableSubjecInfo->rowCount()+csvInter.GetMarkTypesCount());

for(int a=0,x=4;a < csvInter.GetMarkTypesList().count();a++,x++)
{
//Add the header for each marktype
ui->tableSubjecInfo->setVerticalHeaderItem(x,new QTableWidgetItem(tr("Mark Type: %1").arg(csvInter.GetMarkTypesList()[a])));

//Insert a new tEXTeDIT
//QTextEdit *mtDetails = new QTextEdit(this);
//mtDetails->setStyleSheet(" border: 1px solid gray;padding: 4px;border-radius: 6px;");

//Insert a new QWebView
QWebView *mtDetails;
mtDetails = new QWebView(this);

tmpl::html_template one(":/templ/mtdetails.tmpl");

one("NUMMARKS") = csvInter.GetMarkTypeTotalNumberMarks(csvInter.GetMarkTypesList()[a]);
one("MISMARKS") = csvInter.GetStudentCount()-csvInter.GetMarkTypeTotalNumberMarks(csvInter.GetMarkTypesList()[a]);

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

 //Method for checking if the coluomn has marks
 int MainWindow::CheckCoulumnMarkAvailability(QString mt){
     QMap<QString,int> marks = csvInter.GetAllMarksPerMarkType(mt);
     QMapIterator<QString,int>i(marks);
     //Check if the coulumn is empty
     //If the number of zeros is equal the number of marks it simply means the whole doesnt have marks, its not quantum physics

     int countZeros =0;
     while(i.hasNext())
     {
         i.next();
         QString mrk = QString("%1").arg(i.value());
         if(mrk == "0")
         {
             countZeros+=1;

         }
     }

     return countZeros;

 }

 void MainWindow::PopulateSubjectWeb()
 {
     qDebug() << Q_FUNC_INFO <<"start";

     tmpl::html_template one( ":/templ/mtdetails.tmpl" );

     loop_t loop_marktypes;


     row_t row_marktypes;


     //Get all the marktypes and add a row
     QStringList marktypes = csvInter.GetMarkTypesList();
     qDebug()<<marktypes.count();

    for( int a=0;a < marktypes.count();a++ )
     {

        QString mtName = marktypes[a];

        qDebug()<<mtName;

       row_marktypes( "name" ) = mtName.toStdString();
       row_marktypes( "nummarks" ) = csvInter.GetMarkTypeTotalNumberMarks( mtName );
       row_marktypes( "mismarks" ) = csvInter.GetStudentCount()-csvInter.GetMarkTypeTotalNumberMarks( mtName );


       //Loop start
        loop_t loop_marks;
        row_t row_marks;

        QMap<QString,int> marks= csvInter.GetAllMarksPerMarkType( mtName );
        int numZeros = CheckCoulumnMarkAvailability(mtName);


         QMapIterator<QString, int> i( marks ); //For each marktype get the marks and stu num then add to loop marks
         while ( i.hasNext() ) {
             i.next();
             QString onemark = QString( "%1" ).arg( i.value() );
             QString stunumber = i.key();

             if(numZeros != marks.count()){
             row_marks( "onemark" ) = onemark.toStdString();
             row_marks( "stunumber" ) = stunumber.toStdString();
             loop_marks+=row_marks;
             }

        }


       row_marktypes( "allmarks" ) = loop_marks; //Now add loop_marks as a row to the orig loop called loop_marktypes (See template docss for more info)
       loop_marktypes += row_marktypes;
       loop_marks.Empty();

       //Loop end



      }

     one( "MARKTYPES" ) = loop_marktypes;


     one( "NUMMARKS" ) = csvInter.GetMarkTypeTotalNumberMarks( csvInter.GetMarkTypesList()[0] );
     one( "MISMARKS" ) = csvInter.GetStudentCount()-csvInter.GetMarkTypeTotalNumberMarks( csvInter.GetMarkTypesList()[0] );

    // ui->webViewSubjectInfo->setc

    // ui->webViewSubjectInfo->settings()->setUserStyleSheetUrl(QUrl::from);

     qDebug()<<QString::fromStdString(one.Process() );



     ui->webViewSubjectInfo->setHtml( QString::fromStdString(one.Process() ),QUrl("http://code.jquery.com") );
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

     ui->splitter->setSizes( currentSizes );
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
     currentSizes[0] = ( this->width() * 25/100 );

     ui->splitter->setSizes( currentSizes );
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

    QStringList stunumbers = csvInter.GetAllStudentNumbersPerMarkType( ui->comboBoxMarkTypeSlct->currentText() );

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

   UpdateMarksLog->AddUpdateHeader( csvInter.FilePath(),ui->comboBoxMarkTypeSlct->currentText(),csvInter.GetSubjectCode() );


    foreach ( const QString snum,stunumbers )
    {
        qDebug()<<"Updating student number: "<<snum;

        if( !ui->wFitsbrowser->InblrContainsStuNum( snum ) ){

            logErrors.append( tr( "Student not found on Inabler: %1 No update made" ).arg( snum ) );
            qDebug()<<"Student "<<snum<< "not found on Inabler";
            qDebug()<<"MARK NOT UPDATED "<<snum;
        }else{

            int oldm = ui->wFitsbrowser->GetInblrMark(snum);
            QString oldMark;
            oldMark = tr("%1").arg(oldm);
            qDebug()<<"Old mark: ";
            qDebug()<< oldMark;
            qDebug()<<"New mark: ";
            int newmark = csvInter.GetStudentMarkPerMarkType(ui->comboBoxMarkTypeSlct->currentText(),snum);
            qDebug()<<newmark;

            if( oldm > newmark ){

                logWarnings.append( tr( "Student %3 Old mark ( %1 ) > ( %2 ) No update made" ).arg( oldMark ).arg( newmark ).arg( snum ) );
            }else{

            ui->wFitsbrowser->SetInblrMark( snum,newmark );

            logInformation.append(tr( "Mark Updated %3 : %1 --> %2" ).arg( oldMark ).arg( newmark ).arg( snum ) );
            }
        }


      qDebug()<<"";

    }
UpdateMarksLog->AddErrors( logErrors );
UpdateMarksLog->AddWarning( logWarnings );
UpdateMarksLog->AddInformation( logInformation );
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

     switch ( ret ) {
        case QMessageBox::Yes:
            // Yes was clicked
             {
                qDebug()<<"Making all marks 0";
                ui->wFitsbrowser->SetInblrMarkAllZero();
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

void MainWindow::on_actionMake_empty_0_triggered() {
    qDebug() << Q_FUNC_INFO <<"start";
    ui->wFitsbrowser->SetInblrMarkZero();
    qDebug() << Q_FUNC_INFO <<"end";
}

void MainWindow::on_actionBlackout_Cancelled_triggered() {

    qDebug() << Q_FUNC_INFO <<"start";
  ui->wFitsbrowser->SetInblrCanBlackOut();
  qDebug() << Q_FUNC_INFO <<"end";
}

void MainWindow::on_actionLoad_ec_tut_ac_za_triggered() {

    qDebug() << Q_FUNC_INFO <<"start";
   qDebug()<<"Testing to see if ec.tut.ac.za loads";
   ui->wFitsbrowser->setUrl(QUrl( "http://ec.tut.ac.za" ) );
   qDebug() << Q_FUNC_INFO <<"end";
}


void MainWindow::CsvFileParseError( QString mes ){
    qDebug() << Q_FUNC_INFO <<"start";
   //This slot will react to any errors when the CSv file is parced. It will report the message and the user must fix the problem.

    QString messageToUser = QString("Error When Reading File:\n%1\n\nThe problem seems to be:\n%2\n\nPlease note:\nYou can still use the application but please fix the problem before continuing to avoid problems.\n\n========================================================================================" ).arg( csvInter.FilePath() ).arg( mes );

    if( !errorlist.empty() ){

         errorwindow->show();

    }
     errorlist.append(messageToUser);
     errorwindow->ErrorList(errorlist);

    qDebug() << Q_FUNC_INFO <<"end";

}
void MainWindow::on_comboBoxMarkTypeSlct_editTextChanged( const QString &arg1 )
{

}

void MainWindow::on_comboBoxMarkTypeSlct_currentIndexChanged( const QString &arg1 )
{
    qDebug()<<arg1;
    ui->webViewSubjectInfo->findText( QString( " " ) );
    ui->webViewSubjectInfo->findText( arg1,QWebPage::FindWrapsAroundDocument );
}

void MainWindow::on_webViewSubjectInfo_loadFinished( bool arg1 )
{


}

void MainWindow::on_webViewSubjectInfo_loadStarted()
{

}

