#include "downloader.h"
#include <iostream>

Downloader::Downloader()
{
    m_network = new QNetworkAccessManager(this);
    QObject::connect(m_network,&QNetworkAccessManager::finished,this,&Downloader::finished);
}

void Downloader::getHtml(QString url)
{
    m_network->get(QNetworkRequest(QUrl(url)));
}



void Downloader::finished(QNetworkReply *reply)
{
    QFile mFile("C:/Qt/Qt_projects/Kalkulator/kursy.txt");

    if(!mFile.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << "could not open";
        return;
    }

    QTextStream out(&mFile);

    out<<reply->readAll();

    mFile.flush();
    mFile.close();

}

void Downloader::readTxt()
{
    QFile mFile("C:/Qt/Qt_projects/Kalkulator/kursy.txt");

    if(!mFile.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "could not open";
        return;
    }

    QTextStream in(&mFile);


    QString textGBP;
    QString textEUR;
    QString textUSD;

    in.seek(140850);
    textGBP = in.readLine(600);
    in.seek(140600);
    textUSD = in.readLine(600);
    in.seek(140575);
    textEUR = in.readLine(600);

    mFile.close();

    QString GBPcompare = "GBPPLN=";  // skopiowac ze strony jakas wartosc const np." data::GBP= "
    QString EURcompare = "EURPLN=";
    QString USDcompare = "USDPLN=";


    for(int i=0; i <= textEUR.size(); i++)
   {
    if( textEUR.mid(i,EURcompare.size()) != EURcompare ) // porownuje tekst z pliku z tekstem oczekiwanym
        {
        continue;
        }
    else
        {
    EUR = textEUR.mid(i+58,6); // gdy porownal przesuwa o 58 czyli tyle miejsc w pliku do tego co chcemy
        }
    }

    for(int i=0; i <= textGBP.size(); i++)
   {
    if( textGBP.mid(i,GBPcompare.size()) != GBPcompare )
        {
        continue;
        }
    else
        {
    GBP = textGBP.mid(i+57,6);
        }
    }

    for(int i=0; i <= textUSD.size(); i++)
   {
    if( textUSD.mid(i,USDcompare.size()) != USDcompare )
        {
        continue;
        }
    else
        {
    USD = textUSD.mid(i+57,6);
        }
    }



    //qDebug()<<textGBP;
    //qDebug()<<GBP;
    //qDebug()<<textUSD;
    //qDebug()<<USD;
    //qDebug()<<textEUR;
    //qDebug()<<EUR;


}
