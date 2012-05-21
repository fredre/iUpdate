#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "qdebug.h"
#include "Templates\html_template.h"
#include <QTextEdit>

using namespace std;
using namespace tmpl;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qDebug() << Q_FUNC_INFO <<"start";

    ui->setupUi(this);

    ui->progressBarWebInd->hide();
    ui->labelProgress->hide();

    hideSideWindow(); //Maximizes the splitter window


    QMovie *movie = new QMovie(":/images/ajax-loader.gif");

    ui->labelProgress->setMovie(movie);

    movie->start();



    //Hook up to the loadprogress and loadstarted
    connect(ui->wFitsbrowser,SIGNAL(loadProgress (int)),this,SLOT(on_webViewBrowser_loadProgress(int)));
    connect(ui->wFitsbrowser,SIGNAL(loadStarted ()),this,SLOT(on_webViewBrowser_loadStarted()));
    connect(ui->wFitsbrowser,SIGNAL(loadFinished (bool)),this,SLOT(on_webViewBrowser_loadFinished(bool)));
    connect(ui->wFitsbrowser,SIGNAL(onAnyError(QString)),this,SLOT(on_webViewBrowser_anyError(QString)));

    ui->wFitsbrowser->setUrl(QUrl("https://jupiter.tut.ac.za/staffportal/system/login.php?refscript=/staffportal/index.php"));
    //https://jupiter.tut.ac.za/staffportal/apps/its/leave.php?action=app_self  //Direct
    //https://jupiter.tut.ac.za/staffportal/system/login.php?refscript=/staffportal/index.php  //Normal
    //file:///C:/Documents%20and%20Settings/Fredre/Desktop/test/w06pkg.w06marks_entry.htm //Test
    //file:///C:/Documents%20and%20Settings/Fredre/Desktop/w06pkg.html

    //Setup the table for subject info
    QTableWidgetItem *newItem = new QTableWidgetItem("Subject Name: ");
    ui->tableSubjecInfo->setVerticalHeaderItem(0,newItem);

    QTableWidgetItem *newItem1 = new QTableWidgetItem("Total Students: ");
    ui->tableSubjecInfo->setVerticalHeaderItem(1,newItem1);

    QTableWidgetItem *newItem2 = new QTableWidgetItem("First Student: ");
    ui->tableSubjecInfo->setVerticalHeaderItem(2,newItem2);

    QTableWidgetItem *newItem3 = new QTableWidgetItem("Last Student: ");
    ui->tableSubjecInfo->setVerticalHeaderItem(3,newItem3);

    ui->tableSubjecInfo->resizeColumnsToContents();
    ui->tableSubjecInfo->resizeRowsToContents();

    //Stretch last
    QHeaderView *header =  ui->tableSubjecInfo->horizontalHeader();
    header->setStretchLastSection(true);



    //Test the templating system
    //tmpl::html_template one("F:\\Dropbox\\ProjectIncubator\\IUpdate-build-desktop\\debug\\test.tmpl");

  qDebug() << Q_FUNC_INFO <<"end";

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_webViewBrowser_anyError(QString error)
{
    qDebug() << Q_FUNC_INFO <<"start";

    ui->statusBar->showMessage("Eish: "+error);

    qDebug() << Q_FUNC_INFO <<"end";
}

void MainWindow::on_webViewBrowser_loadProgress(int progress)
{
   qDebug() << Q_FUNC_INFO <<"start";
   ui->progressBarWebInd->setValue(progress);
   qDebug() << Q_FUNC_INFO <<"end";
}

void MainWindow::on_webViewBrowser_loadStarted()
{
    qDebug() << Q_FUNC_INFO <<"start";
    ui->progressBarWebInd->show();
    ui->labelProgress->show();
    ui->statusBar->showMessage(ui->wFitsbrowser->url().toString());
    qDebug() << Q_FUNC_INFO <<"end";
}

void MainWindow::on_webViewBrowser_loadFinished(bool ok)
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
                       "In my opinion the best solution would be to develop a \"Dropbox\" way of entering marks. The lecturer will update an automatically generated (created) spreadsheet that will synch up to ITS automatically (both ways if more than one lecturer teaches the course). For more information on how Dropbox works see the Dropbox website.\n\n"
                       "The above solution cannot be implemented without access to some kind of ITS API. If you have access to the API I will happily spend a few weekends implementing the above solution.\n\n"

                         "\tThis program comes with ABSOLUTELY NO WARRANTY\n\n\n"

                           "\tThis program is free software: you can redistribute it and/or modify\n"
                           "\tit under the terms of the GNU General Public License as published by\n"
                           "\tthe Free Software Foundation, either version 3 of the License, or\n"
                           "\t(at your option) any later version.\n\n"

                           "\tThis program is distributed in the hope that it will be useful,\n"
                           "\tbut WITHOUT ANY WARRANTY; without even the implied warranty of\n"
                           "\tMERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
                           "\tGNU General Public License for more details.\n\n"

                           "\tYou should have received a copy of the GNU General Public License\n"
                           "\talong with this program.  If not, see <http://www.gnu.org/licenses/>.\n"
                       );

qDebug() << Q_FUNC_INFO <<"end";
}

void MainWindow::on_actionAbout_QT_triggered()
{
    qDebug() << Q_FUNC_INFO <<"start";
    QMessageBox::aboutQt (this);
    qDebug() << Q_FUNC_INFO <<"end";
}

void MainWindow::on_actionLoad_triggered()
{
    qDebug() << Q_FUNC_INFO <<"start";
    ui->labelProgress->show();
    csvInter.setFilePath(QFileDialog::getOpenFileName(this,tr("Open %1 Marks File").arg(csvInter.getFileTypeName()), QDir::homePath(), tr("%1").arg(csvInter.getFileExt())));
    csvInter.loadFile();
    PopulateSubjectGrid();

    //Load the marktypes into the combo box
    ui->comboBoxMarkTypeSlct->addItems(csvInter.getMarkTypesList());

    showSideWindow();
    ui->labelProgress->hide();
    qDebug() << Q_FUNC_INFO <<"end";
}

 void MainWindow::PopulateSubjectGrid()
 {
qDebug() << Q_FUNC_INFO <<"start";

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
          ui->tableSubjecInfo->setVerticalHeaderItem(x,new QTableWidgetItem(tr("Mark Type: %1").arg(csvInter.getMarkTypesList()[a])));

//          //Insert a list for each marktype that will show more details
//           QListWidget *MarkTypeListWidget = new QListWidget(this);

//           QStringList MarkTypeListWidgetContents;

//           MarkTypeListWidgetContents.append(tr("Number of marks: %1").arg(csvInter.getMarkTypeTotalNumberMarks(csvInter.getMarkTypesList()[a])));
//           MarkTypeListWidgetContents.append(tr("Missing marks: %1").arg(csvInter.getStudentCount()-csvInter.getMarkTypeTotalNumberMarks(csvInter.getMarkTypesList()[a])));

//           //Show all the student numbers that does not have a mark for this marktype
//           foreach(const QString &stnum,csvInter.getStudentNumbersWithNoMark(csvInter.getMarkTypesList()[a]))
//           {
//                MarkTypeListWidgetContents.append(tr("No mark or mark is 0 for %1").arg(stnum));
//           }


//           MarkTypeListWidget->insertItems(0,MarkTypeListWidgetContents);

//           ui->tableSubjecInfo->setCellWidget(x,0, MarkTypeListWidget);

          //Insert a new tEXTeDIT
         QTextEdit *mtDetails = new QTextEdit(this);
         mtDetails->setStyleSheet(" border: 1px solid gray;padding: 4px;border-radius: 6px;");



         tmpl::html_template one(":/templ/mtdetails.tmpl");



         one("NUMMARKS") =  csvInter.getMarkTypeTotalNumberMarks(csvInter.getMarkTypesList()[a]);
         one("MISMARKS") = csvInter.getStudentCount()-csvInter.getMarkTypeTotalNumberMarks(csvInter.getMarkTypesList()[a]);

         mtDetails->setHtml(QString::fromStdString(one.Process()));

         ui->tableSubjecInfo->setCellWidget(x,0, mtDetails);
     }

     ui->tableSubjecInfo->verticalHeader()->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);
     ui->tableSubjecInfo->verticalHeaderItem(3)->setSizeHint(QSize(120,120));

     ui->tableSubjecInfo->resizeColumnsToContents();
     ui->tableSubjecInfo->resizeRowsToContents();
qDebug() << Q_FUNC_INFO <<"end";
 }

 void MainWindow::hideSideWindow()
{
    qDebug() << Q_FUNC_INFO <<"start";
     ui->pushButtonUpdateMrks->hide();
     ui->comboBoxMarkTypeSlct->hide();
     ui->tableSubjecInfo->hide();
     QList<int> currentSizes = ui->splitter->sizes();
     // adjust sizes individually

     currentSizes[1] = ui->wFitsbrowser->width();

     ui->splitter->setSizes(currentSizes);
     qDebug() << Q_FUNC_INFO <<"end";
 }

 void MainWindow::showSideWindow()
 {
     qDebug() << Q_FUNC_INFO <<"start";
     ui->pushButtonUpdateMrks->show();
     ui->comboBoxMarkTypeSlct->show();
     ui->tableSubjecInfo->show();

     QList<int> currentSizes = ui->splitter->sizes();
     // adjust sizes individually

     currentSizes[0] = 0;
     currentSizes[0] = (this->width() * 25/100);

     ui->splitter->setSizes(currentSizes);
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

    QStringList stunumbers = csvInter.getAllStudentNumbersPerMarkType(ui->comboBoxMarkTypeSlct->currentText());

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

   UpdateMarksLog->addUpdateHeader(csvInter.FilePath(),ui->comboBoxMarkTypeSlct->currentText(),csvInter.getSubjectCode());


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
            int oldm = ui->wFitsbrowser->getInblrMark(snum);
            QString oldMark;
            oldMark = tr("%1").arg(oldm);
            qDebug()<<"Old mark: ";
            qDebug()<< oldMark;
            qDebug()<<"New mark: ";
            int newmark = csvInter.getStudentMarkPerMarkType(ui->comboBoxMarkTypeSlct->currentText(),snum);
            qDebug()<<newmark;

            if(oldm > newmark)
            {
                logWarnings.append(tr("Student %3 Old mark  (%1) > (%2) No update made").arg(oldMark).arg(newmark).arg(snum));
            }
            else
            {

            ui->wFitsbrowser->setInblrMark(snum,newmark);

            logInformation.append(tr("Mark Updated %3 : %1 --> %2").arg(oldMark).arg(newmark).arg(snum));
            }
        }


      qDebug()<<"";

    }
UpdateMarksLog->addErrors(logErrors);
UpdateMarksLog->addWarning(logWarnings);
UpdateMarksLog->addInformation(logInformation);
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

     switch (ret) {
        case QMessageBox::Yes:
            // Yes was clicked
             {
                qDebug()<<"Making all marks 0";
                ui->wFitsbrowser->setInblrMarkAllZero();
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
    ui->wFitsbrowser->setInblrMarkZero();
    qDebug() << Q_FUNC_INFO <<"end";
}

void MainWindow::on_actionBlackout_Cancelled_triggered()
{
  qDebug() << Q_FUNC_INFO <<"start";
  ui->wFitsbrowser->setInblrCanBlackOut();
  qDebug() << Q_FUNC_INFO <<"end";
}

void MainWindow::on_actionLoad_ec_tut_ac_za_triggered()
{
   qDebug() << Q_FUNC_INFO <<"start";
   qDebug()<<"Testing to see if ec.tut.ac.za loads";
   ui->wFitsbrowser->setUrl(QUrl("http://ec.tut.ac.za"));
   qDebug() << Q_FUNC_INFO <<"end";
}
