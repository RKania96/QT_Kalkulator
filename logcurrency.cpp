#include "logcurrency.h"


QString LogCurrency::showLog()
{
   Decorator::showLog();

    QFile mFile("C:/Qt/Qt_projects/Kalkulator/Logs/logCurrency.txt");

    if(!mFile.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "could not open";
        return 0;
    }

    QTextStream in(&mFile);
    QString mText = in.readAll();



    mFile.close();

    return mText;
}
