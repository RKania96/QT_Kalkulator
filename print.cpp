#include "print.h"

Print::Print()
{

}

void Print::Write(QString file,QString data)
{
    QString path = "C:/Qt/Qt_projects/Kalkulator/Logs/"+file;
    QFile mFile(path);

    if(!mFile.open(QFile::Append | QFile::Text))
    {
        qDebug() << "could not open";
        return;
    }

    QTextStream out(&mFile);

    out<<data;

    mFile.flush();
    mFile.close();
}

void Print::Clear()
{
    QFile mFile("C:/Qt/Qt_projects/Kalkulator/Logs/logBasic.txt");
    mFile.resize(0);

    QFile mFile2("C:/Qt/Qt_projects/Kalkulator/Logs/logProgrammer.txt");
    mFile2.resize(0);

    QFile mFile3("C:/Qt/Qt_projects/Kalkulator/Logs/logCurrency.txt");
    mFile3.resize(0);
}

