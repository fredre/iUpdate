#include "csvimport.h"
#include "ui_csvimport.h"
#include <QDebug>

CSVImport::CSVImport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CSVImport)
{
    ui->setupUi(this);
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);


    ui->tableView->horizontalHeader()->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableView->horizontalHeader(),SIGNAL(customContextMenuRequested(QPoint)),SLOT(customHeaderMenuRequested(QPoint)));

     ui->tableView->verticalHeader()->setContextMenuPolicy(Qt::CustomContextMenu);
     connect(ui->tableView->verticalHeader(),SIGNAL(customContextMenuRequested(QPoint)),SLOT(customRowMenuRequested(QPoint)));

     CurrentStep = Step1;
     guiSetStep();
}

CSVImport::~CSVImport()
{
    delete ui;
}

 void CSVImport::guiSetStep()
 {
      QFont highLight(QString("MS Shell Dlg 2"),12,QFont::Bold,false);
      QFont normal(QString("MS Shell Dlg 2"),10,QFont::Light,false);

     switch(CurrentStep)
     {
     case Step1:
       ui->btnOpen->setFont(highLight);
       ui->tableView->hide();
       ui->lblLastRow->hide();
       ui->lblLastRow_2->hide();
       ui->lblMtRow->hide();
       ui->lblMtRow_2->hide();
       ui->lblStuNumCol->hide();
       ui->lblStuNumCol_2->hide();
       ui->lblSubName->hide();
       ui->lblSubName_2->hide();
       ui->btnDone->hide();
       ui->actionSet_as_last_row->setEnabled(false);
       ui->actionSet_as_mark_type_row->setEnabled(false);
       ui->actionSet_as_student_number_colomn->setEnabled(false);
       ui->actionSet_cell_as_subject_name->setEnabled(false);
     break;

     case Step2:
       ui->btnOpen->setFont(normal);
       ui->btnOpen->hide();
       ui->tableView->show();
       ui->lblLastRow->hide();
       ui->lblLastRow_2->hide();
       ui->lblMtRow->hide();
       ui->lblMtRow_2->hide();
       ui->lblStuNumCol->hide();
       ui->lblStuNumCol_2->hide();

       ui->lblSubName_2->show();
       ui->lblSubName_2->setFont(highLight);

       ui->btnDone->hide();
       ui->actionSet_as_last_row->setEnabled(false);
       ui->actionSet_as_mark_type_row->setEnabled(false);
       ui->actionSet_as_student_number_colomn->setEnabled(false);
       ui->actionSet_cell_as_subject_name->setEnabled(true);


       //Virie grap
       for(int i=0; i<model->columnCount(); i++)
           {
             for(int j=0; j<model->rowCount(); j++)
             {

                   model->item(j,i)->setData(QBrush(QColor(0, 85, 127,255)), Qt::BackgroundRole);
                   model->item(j,i)->setData(QBrush(Qt::white), Qt::ForegroundRole);

             }
           }


     break;

     case Step3:
       ui->lblLastRow->hide();
       ui->lblLastRow_2->hide();
       ui->lblMtRow->hide();
       ui->lblMtRow_2->hide();
       ui->lblSubName_2->hide();
       ui->lblSubName->hide();


       ui->lblSubName_2->setFont(normal);
       ui->lblStuNumCol_2->show();

       ui->btnDone->hide();
       ui->actionSet_as_last_row->setEnabled(false);
       ui->actionSet_as_mark_type_row->setEnabled(false);
       ui->actionSet_as_student_number_colomn->setEnabled(true);




       //Virie grap net selecte een
       for(int i=0; i<model->columnCount(); i++)
           {
             for(int j=0; j<model->rowCount(); j++)
             {


                 if(model->item(j,i)->text() ==  ui->lblSubName->text())
                 {
                     model->item(j,i)->setData(QBrush(QColor(0, 85, 127,255)), Qt::BackgroundRole);
                     model->item(j,i)->setData(QBrush(Qt::white), Qt::ForegroundRole);

                 }
                 else
                 {
                 model->item(j,i)->setData(QBrush(Qt::white), Qt::BackgroundRole);
                 model->item(j,i)->setData(QBrush(Qt::black), Qt::ForegroundRole);
                 }

             }
           }


     break;

     case Step4:
       ui->lblLastRow->hide();
       ui->lblLastRow_2->hide();
       ui->lblStuNumCol_2->hide();
       ui->lblStuNumCol->hide();

       ui->lblMtRow_2->show();


       ui->btnDone->hide();
       ui->actionSet_as_last_row->setEnabled(false);
       ui->actionSet_as_mark_type_row->setEnabled(true);
     break;

     case Step5:

       ui->lblMtRow_2->setFont(normal);
       ui->lblLastRow_2->show();
       ui->lblLastRow_2->setFont(highLight);

       ui->btnDone->hide();
       ui->actionSet_as_last_row->setEnabled(true);
     break;

     case Step6:

       ui->lblLastRow_2->setFont(normal);
       ui->btnDone->show();
       ui->btnDone->setFont(highLight);
     break;



    }
 }

void CSVImport::on_action_Open_triggered()
{

}

void CSVImport::checkString(QString &temp, QChar character)
{
    if(temp.count("\"")%2 == 0) {
        //if (temp.size() == 0 && character != ',') //problem with line endings
        //    return;
        if (temp.startsWith( QChar('\"')) && temp.endsWith( QChar('\"') ) ) {
             temp.remove( QRegExp("^\"") );
             temp.remove( QRegExp("\"$") );
        }
        //FIXME: will possibly fail if there are 4 or more reapeating double quotes
        temp.replace("\"\"", "\"");
        QStandardItem *item = new QStandardItem(temp);
        standardItemList.append(item);
        if (character != QChar(',')) {
            model->appendRow(standardItemList);
            standardItemList.clear();
        }
        temp.clear();
    } else {
        temp.append(character);
    }
}

void CSVImport::on_btnOpen_clicked()
{
    model = new QStandardItemModel(this);
    ui->tableView->setModel(model);

    //First try to load settings
    //QString lstload = IUpdatesettings.value( "lastLoadPath",QDir::homePath() ).toString();


    QString fileName = QFileDialog::getOpenFileName (this, "Open CSV file",
                                                     QDir::currentPath(), "CSV (*.csv)");
    QFile file (fileName);
    if (file.open(QIODevice::ReadOnly)) {

        //QDir d = QFileInfo( file ).absoluteDir();
        //IUpdatesettings.setValue( "lastLoadPath",d.absolutePath() );

        QString data = file.readAll();
        data.remove( QRegExp("\r") ); //remove all ocurrences of CR (Carriage Return)
        QString temp;
        QChar character;
        QTextStream textStream(&data);
        while (!textStream.atEnd()) {
            textStream >> character;
            if (character == ',') {
                checkString(temp, character);
            } else if (character == '\n') {
                checkString(temp, character);
            } else if (textStream.atEnd()) {
                temp.append(character);
                checkString(temp);
            } else {
                temp.append(character);
            }
        }
    }

    CurrentStep = Step2;
    guiSetStep();


}

void CSVImport::on_tableView_customContextMenuRequested(const QPoint &pos)
{
       currRclickIndex = ui->tableView->indexAt(pos);

       QMenu *menu=new QMenu(this);

       menu->addAction(ui->actionSet_cell_as_subject_name);

       menu->popup(ui->tableView->viewport()->mapToGlobal(pos));
}

void CSVImport::on_actionSet_cell_as_subject_name_triggered()
{
    qDebug()<<model->data(currRclickIndex);
    ui->lblSubName->setText(model->data(currRclickIndex).toString());
    ui->lblSubName->show();
    CurrentStep = Step3;
    guiSetStep();
}

void  CSVImport::customHeaderMenuRequested(QPoint pos){
    currRclickcolumn=ui->tableView->horizontalHeader()->logicalIndexAt(pos);

    QMenu *menu=new QMenu(this);
    menu->addAction(ui->actionSet_as_student_number_colomn);

    menu->popup(ui->tableView->horizontalHeader()->viewport()->mapToGlobal(pos));

}

void CSVImport::on_actionSet_as_student_number_colomn_triggered()
{
    qDebug()<<currRclickcolumn;
    ui->lblStuNumCol->setText(QString("%1").arg(currRclickcolumn+1));
    ui->lblStuNumCol->show();
    CurrentStep = Step4;
    guiSetStep();
}

void  CSVImport::customRowMenuRequested(QPoint pos)
{
    currRclickrow=ui->tableView->verticalHeader()->logicalIndexAt(pos);
    currRclickLastrow = ui->tableView->verticalHeader()->logicalIndexAt(pos);

    QMenu *menu=new QMenu(this);
    menu->addAction(ui->actionSet_as_mark_type_row);
     menu->addAction(ui->actionSet_as_last_row);

    menu->popup(ui->tableView->verticalHeader()->viewport()->mapToGlobal(pos));
}

void CSVImport::on_actionSet_as_mark_type_row_triggered()
{
  qDebug()<<currRclickrow;
  ui->lblMtRow->setText(QString("%1").arg(currRclickrow+1));
   ui->lblMtRow->show();
  CurrentStep = Step5;
  guiSetStep();
}

void CSVImport::on_actionSet_as_last_row_triggered()
{
    qDebug()<< currRclickLastrow;
    ui->lblLastRow->setText(QString("%1").arg(currRclickLastrow+1));
    ui->lblLastRow->show();

    CurrentStep = Step6;
    guiSetStep();
}

void CSVImport::on_btnDone_clicked()
{
    QString subname = ui->lblSubName->text();//Subject name
    int MTindex = ui->lblMtRow->text().toInt()-1; //The index of the row containg the marktypes
    int StuNumindex = ui->lblStuNumCol->text().toInt()-1; //The index of the coloumn containing the student numbers
    int LastStuNumindex = ui->lblLastRow->text().toInt()-1; //The index of the last row to be considered

    //Create the main JSON Object
    QJsonObject *jsonO_Subject = new QJsonObject();

    //Create a value for the subject name
    QJsonValue *jsonV_SubjectName = new QJsonValue(subname);

    //Create an array for all the student numbers
    QJsonArray *jsonA_StudentNumbers = new QJsonArray();

    for(int a = MTindex+1;a<=LastStuNumindex;a++)
    {
    QString snum = model->item(a,StuNumindex)->text();
    QJsonValue oneSnum(snum);
    jsonA_StudentNumbers->append(oneSnum);
    }

    //Create an array of all the marktypes
    QJsonArray *jsonA_AllmarkTypes = new QJsonArray();

    for(int a = 1;a<model->columnCount();a++)
    {
    QString mt = model->item(MTindex,a)->text();
    QJsonValue oneMarkType(mt);
    jsonA_AllmarkTypes->append(oneMarkType);
    }

    //for each MT create a new object
    for(int a = 1;a<model->columnCount();a++)
    {
    QString mt = model->item(MTindex,a)->text();
   // qDebug()<<"The MT is: "<<mt;

    QJsonObject *jsonO_MarkType = new QJsonObject();

        //For each student for the marktype. get the student number and the mark
        for(int b = MTindex+1;b<=LastStuNumindex;b++)
        {
        QString snum = model->item(b,StuNumindex)->text();
        QString smark = model->item(b,a)->text();

        //Create a JSON value for the mark
        QJsonValue *jsonV_OneMark = new QJsonValue(smark.toDouble());

        //Add the mark to the created object the key will be the student number
        jsonO_MarkType->insert(snum,*jsonV_OneMark);
        }
     //The obeject is now loaded. Add to the main object
     jsonO_Subject->insert(mt,*jsonO_MarkType);
    }


    //Add the student numbers to the object
    jsonO_Subject->insert("AllStudentNumbers",*jsonA_StudentNumbers);

    //Add the marktypes to the object
    jsonO_Subject->insert("AllMarkTypes",*jsonA_AllmarkTypes);


    //Add the subject name to the object
    jsonO_Subject->insert("SubjectName",*jsonV_SubjectName);


    jdoc = new  QJsonDocument(*jsonO_Subject);

    //qDebug()<<jdoc->toJson();
    emit JSonGenerated(jdoc);

    CurrentStep = Step1;
    guiSetStep();
}

QJsonDocument* CSVImport::getJDoc()
{
    return jdoc;
}

