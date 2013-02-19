#ifndef itsBrowser_H
#define itsBrowser_H

#include<QtWebKit>
//#include<QtWebKitWidgets>
#include <QWebView>
#include <QNetworkCookieJar>
#include "qdebug.h"
#include <QSslError>
#include <QNetworkReply>
#include <QMessageBox>
#include <QDialog>
#include <QLineEdit>
#include <QInputDialog>
#include <QAuthenticator>
#include <QWebFrame>
#include <QNetworkProxy>
#include <QNetworkReply>

class itsBrowser : public QWebView
{
    Q_OBJECT
public:
    explicit itsBrowser( QWidget *parent = 0 );
    int GetInblrMark( QString );
    void SetInblrMark( QString,int );
    void SetInblrMarkAllZero();
    void SetInblrMarkZero();
    bool InblrContainsStuNum( QString );
    void SetInblrCanBlackOut();

signals:
    void onAnyError( QString );
    void OnNetworkError( QString ); //Problem with network connectivity
public slots:
    void HandleSslErrors( QNetworkReply* reply, const QList<QSslError> &errors );
    void ProvideAuthentication( QNetworkReply*,QAuthenticator* );
    void ProvideProxAuthentication( const QNetworkProxy &, QAuthenticator* );
    void NetworkTaskfinished ( QNetworkReply * );

};

#endif // itsBrowser_H
