#include "itsbrowser.h"

itsBrowser::itsBrowser(QWidget *parent) :
    QWebView(parent)
{



    QWebSettings *Tsettings = settings();
    Tsettings->setAttribute(QWebSettings::JavascriptEnabled, true);
    Tsettings->setAttribute(QWebSettings::PluginsEnabled, true);
    Tsettings->setAttribute(QWebSettings::AutoLoadImages, true);
    Tsettings->setAttribute(QWebSettings::JavaEnabled, true);
    Tsettings->setAttribute(QWebSettings::JavascriptCanOpenWindows, true);




    QNetworkCookieJar *myjar = new QNetworkCookieJar();


    this->page()->networkAccessManager()->setCookieJar(myjar);

    connect(page()->networkAccessManager(),SIGNAL(sslErrors(QNetworkReply*, const QList<QSslError> & )),this,SLOT(handleSslErrors(QNetworkReply*, const QList<QSslError> & )));
    connect(page()->networkAccessManager(),SIGNAL(authenticationRequired(QNetworkReply*,QAuthenticator*)),this,SLOT(provideAuthentication(QNetworkReply*,QAuthenticator*)));
    connect(page()->networkAccessManager(),SIGNAL(proxyAuthenticationRequired(const QNetworkProxy &, QAuthenticator *)),this,SLOT(provideProxAuthentication(const QNetworkProxy&, QAuthenticator*)));
    connect(page()->networkAccessManager(),SIGNAL(finished ( QNetworkReply *)),this,SLOT(networkTaskfinished (QNetworkReply *)));


}

void itsBrowser::networkTaskfinished(QNetworkReply *reply)
{
    qDebug() << Q_FUNC_INFO <<"start";
    qDebug()<<reply->errorString();
    emit onNetworkError(reply->errorString());
    qDebug() << Q_FUNC_INFO <<"end";
}

void itsBrowser::handleSslErrors(QNetworkReply* reply, const QList<QSslError> &errors)
{
   qDebug() << Q_FUNC_INFO <<"start";
    qDebug() << "handleSslErrors: ";
    foreach (QSslError e, errors)
    {
        qDebug() << "ssl error: " << e;
        emit onAnyError(e.errorString());
    }

    reply->ignoreSslErrors();
    qDebug() << Q_FUNC_INFO <<"end";
}

void itsBrowser::provideAuthentication(QNetworkReply *rep ,QAuthenticator *auth)
{
    qDebug()<<"Active directory waisting our time master. Auto engage responce";

    bool ok;
    QString user = QInputDialog::getText(this, tr("Provide user name"),tr("User name:"), QLineEdit::Normal,tr("tut\\"), &ok);

    QString pass = QInputDialog::getText(this, tr("Provide password"), tr("Password:"), QLineEdit::Normal,tr(""), &ok);


    auth->setUser(user);
    auth->setPassword(pass);


    qDebug() << rep->readAll();
    qDebug()<<auth->password();
    qDebug()<<auth->user();
    qDebug()<<rep->error();
    rep->ignoreSslErrors();

    rep->url().setUserInfo(QString("%1:%2").arg(user).arg(pass));

    this->load(rep->url());

}

void itsBrowser::provideProxAuthentication(const QNetworkProxy &np, QAuthenticator *auth)
{
    qDebug()<<"Proxy authentication required !!!!!";

    qDebug()<<"Proxy authentication is requisted !!!!";

    bool ok;
    QString user = QInputDialog::getText(this, tr("Provide user name"),tr("User name:"), QLineEdit::Normal,tr("tut\\"), &ok);

    QString pass = QInputDialog::getText(this, tr("Provide password"), tr("Password:"), QLineEdit::Normal,tr(""), &ok);

    auth->setUser(user);
    auth->setPassword(pass);





}

int itsBrowser::getInblrMark(QString stn)
{
  QVariant result =  this->page()->currentFrame()->evaluateJavaScript(QString("for(a=0;a<document.frmOne.elements.length;a++){ if(document.frmOne.elements[a].value =='%1 ') { document.frmOne.elements[a+1].value}}").arg(stn));
  qDebug()<<result;
  qDebug()<<"getInblrMark Result "<<result;
  return result.toInt();
}

void itsBrowser::setInblrMark(QString stn,int mark)
{
  QString mrk =  tr("%1").arg(mark);
  QVariant result = this->page()->currentFrame()->evaluateJavaScript(QString("for(a=0;a<document.frmOne.elements.length;a++){ if(document.frmOne.elements[a].value =='%1 '){ document.frmOne.elements[a+1].value = %2}}").arg(stn).arg(mrk));
  qDebug()<<result;
  qDebug()<<"Student mark updated itsbrowser.cpp Result "<<result;
}

void itsBrowser::setInblrMarkAllZero()
{
    QVariant result = this->page()->currentFrame()->evaluateJavaScript(QString("for(a=0;a<document.frmOne.elements.length;a++){ if(document.frmOne.elements[a].value.length == 10 && document.frmOne.elements[a].name=='x_stno' && document.frmOne.elements[a].value !='' && document.frmOne.elements[a].value!=null ){ document.frmOne.elements[a+1].value = '0'}}"));
    qDebug()<<"setInblrMarkAllZero()  itsbrowser.cpp Result "<<result;
}

void itsBrowser::setInblrMarkZero()
{
    QVariant result = this->page()->currentFrame()->evaluateJavaScript(QString("for(a=0;a<document.frmOne.elements.length;a++){ if(document.frmOne.elements[a].value.length == 10 && document.frmOne.elements[a].name=='x_stno' && document.frmOne.elements[a].value !='' && document.frmOne.elements[a].value!=null ){ if(document.frmOne.elements[a+1].value == ''){document.frmOne.elements[a+1].value = '0'}}}"));
    qDebug()<<"setInblrMarkZero()  itsbrowser.cpp Result "<<result;
}

bool itsBrowser::InblrContainsStuNum(QString stn)
{
    QVariant result = this->page()->currentFrame()->evaluateJavaScript(QString("false; for(a=0;a<document.frmOne.elements.length;a++){ if(document.frmOne.elements[a].value =='%1 '){true}}").arg(stn));
    qDebug()<<result;
   qDebug()<<"Contains student numberexecuted  itsbrowser.cpp Result "<<result;
    return result.toBool();
}

 void itsBrowser::setInblrCanBlackOut()
 {
   QVariant result = this->page()->currentFrame()->evaluateJavaScript(QString("for(a=0;a<document.frmOne.elements.length;a++){ if(document.frmOne.elements[a].type='table'){for ( i = 0, row; row = document.frmOne.elements[a].rows[i]; i++) {}  }  } "));
 }
