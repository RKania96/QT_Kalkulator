#include "logprogrammer.h"



QString LogProgrammer::showLog()
{
    Decorator::showLog();

    QFile mFile("C:/Qt/Qt_projects/Kalkulator/Logs/logProgrammer.txt");

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
