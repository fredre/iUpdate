#include <QGuiApplication>
#include "mainwindow.h"
#include <QApplication>
#include <QtDebug>
#include <QFile>
#include <QTextStream>


/*
  TODO:

  Check for duplicate student numbers
  Check the bug on number of missing marks.

  Onderskei tussen missing marks en marks wat 0 is
  Heimo se hy overwrite punte met ander punte
  Trim die subject name anderste kry mens white space conflict as hy n folder maak

  */

void myMessageHandler( QtMsgType type, const char *msg ) {
QString txt;
switch ( type ) {
case QtDebugMsg:
txt = QString( "Debug: %1" ).arg( msg );
break;
case QtWarningMsg:
txt = QString( "Warning: %1" ).arg( msg );
break;
case QtCriticalMsg:
txt = QString( "Critical: %1" ).arg( msg );
break;
case QtFatalMsg:
txt = QString( "Fatal: %1" ).arg( msg );
abort();
}
QFile outFile( "LOGFILE.txt" );
outFile.open( QIODevice::WriteOnly | QIODevice::Append );
QTextStream ts( &outFile );
ts << txt << endl;
}

int main( int argc, char *argv[] ) {
    QApplication a( argc, argv );



   // qInstallMsgHandler( myMessageHandler );
    // Setting the Application version
        a.setApplicationVersion( APP_VERSION );
        qDebug()<<APP_VERSION;

    MainWindow w;
    w.show();

    return a.exec();
}
