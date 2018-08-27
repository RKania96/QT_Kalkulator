#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "print.h"
#include <QFile>
#include <QDebug>
#include <fstream>

class Downloader : public QObject
{
    Q_OBJECT
public:
    Downloader();

    void getHtml(QString url);
    void readTxt();

    QString GBP;
    QString USD;
    QString EUR;

private slots:
     void finished(QNetworkReply *reply);


private:
    QNetworkAccessManager *m_network;



};

#endif // DOWNLOADER_H
