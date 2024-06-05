#include "itsbrowser.h"
#include "mainwindow.h"
#include <QWebView>
#include "ui_mainwindow.h"
#include <QSslSocket>
itsBrowser::itsBrowser( QWidget *parent ) :
    QWebView( parent ){

    //This is needed in Ubuntu under QT 5 for SSL to work
    //Still need to test in Windows7
    //Seems for Windows 7 you need to install SSL binaries located:
    //http://slproweb.com/products/Win32OpenSSL.html
    //QSslConfiguration sslConfig = QSslConfiguration::defaultConfiguration();
    //sslConfig.setProtocol( QSsl::SslV3 ); //Seems under ubuntu we need to specify the version

    //QSslConfiguration::setDefaultConfiguration( sslConfig );


    if(!QSslSocket::supportsSsl())
    {
         qDebug() << "It seems SSL is not supported According to supportsSsl. Have you installed open SSL ?";
    }

    QWebSettings *Tsettings = settings();
    Tsettings->setAttribute( QWebSettings::JavascriptEnabled , true );
    Tsettings->setAttribute( QWebSettings::PluginsEnabled , true );
    Tsettings->setAttribute( QWebSettings::AutoLoadImages , true );
    Tsettings->setAttribute( QWebSettings::JavaEnabled , true );
    Tsettings->setAttribute( QWebSettings::JavascriptCanOpenWindows , true);

    QNetworkCookieJar *myjar = new QNetworkCookieJar();

    this->page()->networkAccessManager()->setCookieJar(myjar);

    connect( page()->networkAccessManager(), SIGNAL( sslErrors( QNetworkReply*, const QList<QSslError> & ) ) ,this,SLOT( handleSslErrors( QNetworkReply*, const QList<QSslError> & ) ) );
    connect( page()->networkAccessManager(), SIGNAL( authenticationRequired( QNetworkReply*,QAuthenticator* ) ) , this,SLOT( ProvideAuthentication(QNetworkReply*,QAuthenticator* ) ) );
    connect( page()->networkAccessManager(), SIGNAL( proxyAuthenticationRequired(const QNetworkProxy &, QAuthenticator *)) , this , SLOT( ProvideProxAuthentication( const QNetworkProxy&, QAuthenticator*) ) );
    connect( page()->networkAccessManager(), SIGNAL( finished ( QNetworkReply *)),this,SLOT(NetworkTaskfinished (QNetworkReply *)));

}

void itsBrowser::NetworkTaskfinished( QNetworkReply *reply ){
    qDebug() << Q_FUNC_INFO <<"start";
    qDebug()<<reply->errorString();
    emit OnNetworkError( reply->errorString() );

    qDebug() << Q_FUNC_INFO <<"end";

}

void itsBrowser::handleSslErrors( QNetworkReply* reply , const QList<QSslError> &errors ){

    qDebug() << Q_FUNC_INFO <<"start";
    qDebug() << "handleSslErrors: !!!!!!!!!!!!!!!! ";
    foreach ( QSslError e , errors )
    {
        qDebug() << "ssl error: " << e;
        emit onAnyError( e.errorString( ));
    }
    reply->ignoreSslErrors();

    qDebug() << Q_FUNC_INFO <<"end";
}

void itsBrowser::ProvideAuthentication( QNetworkReply *rep , QAuthenticator *auth ){
    qDebug()<<"Active directory waisting our time master. Auto engage responce";

        QMessageBox::information(this,"Information","Active Directory login not currently supported due to badly configured TUT Directory Server",QMessageBox::Ok);

        //sets url
        setUrl( QUrl( "www.google.com" ) );
      //  setUrl( QUrl( "https://jupiter.tut.ac.za/staffportal/system/login.php?refscript=/staffportal/index.php" ) );

}

void itsBrowser::ProvideProxAuthentication( const QNetworkProxy &np, QAuthenticator *auth ){
    qDebug()<<"Proxy authentication required !!!!!";
    qDebug()<<"Proxy authentication is requisted !!!!";

}

int itsBrowser::GetInblrMark( QString stn ){
  QVariant result =  this->page()->currentFrame()->evaluateJavaScript( QString( "for(a=0;a<document.frmOne.elements.length;a++ ) { if( document.frmOne.elements[a].value =='%1 ' ) { document.frmOne.elements[a+1].value } }" ).arg( stn ) );
  qDebug()<<result;
  qDebug()<<"getInblrMark Result "<<result;
  return result.toInt();
}

void itsBrowser::SetInblrMark( QString stn, int mark ){
  QString mrk =  tr( "%1" ).arg( mark );
  QVariant result = this->page()->currentFrame()->evaluateJavaScript( QString( "for(a=0;a<document.frmOne.elements.length;a++) { if ( document.frmOne.elements[a].value =='%1 ' ) { document.frmOne.elements[a+1].value = %2 } }" ).arg(stn).arg( mrk ) );
  qDebug()<<result;
  qDebug()<<"Student mark updated itsBrowser.cpp Result "<<result;
}

void itsBrowser::SetInblrMarkAllZero(){
    QVariant result = this->page()->currentFrame()->evaluateJavaScript( QString( "for( a=0;a<document.frmOne.elements.length;a++ ) { if ( document.frmOne.elements[a].value.length == 10 && document.frmOne.elements[a].name=='x_stno' && document.frmOne.elements[a].value !='' && document.frmOne.elements[a].value!=null ) { document.frmOne.elements[a+1].value = '0'} }" ) );
    qDebug()<<"SetInblrMarkAllZero()  itsBrowser.cpp Result "<<result;
}

void itsBrowser::SetInblrMarkZero(){
    QVariant result = this->page()->currentFrame()->evaluateJavaScript( QString( "for(a=0;a<document.frmOne.elements.length;a++ ) { if ( document.frmOne.elements[a].value.length == 10 && document.frmOne.elements[a].name=='x_stno' && document.frmOne.elements[a].value !='' && document.frmOne.elements[a].value!=null ) { if ( document.frmOne.elements[a+1].value == '' ) {document.frmOne.elements[a+1].value = '0'} } }" ) );
    qDebug()<<"SetInblrMarkZero()  itsBrowser.cpp Result "<<result;
}

bool itsBrowser::InblrContainsStuNum( QString stn ){
    QVariant result = this->page()->currentFrame()->evaluateJavaScript( QString( "false; for( a=0;a<document.frmOne.elements.length;a++ ) { if(document.frmOne.elements[a].value =='%1 ' ) {true} }" ).arg( stn ) );
    qDebug()<<result;
   qDebug()<<"Contains student numberexecuted  itsBrowser.cpp Result "<<result;
    return result.toBool();
}

 void itsBrowser::SetInblrCanBlackOut(){
   QVariant result = this->page()->currentFrame()->evaluateJavaScript( QString( "for(a=0;a<document.frmOne.elements.length;a++ ) { if(document.frmOne.elements[a].type='table' ) {for ( i = 0, row; row = document.frmOne.elements[a].rows[i]; i++ ) {}  }  } " ) );
}


