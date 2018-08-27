#ifndef PRINT_H
#define PRINT_H

#include <QFile>
#include <QString>
#include <QMessageBox>
#include <QDebug>
#include <QTextStream>


class Print
{
public:
    Print();
    void Write(QString path,QString data);
    void Clear();
};

#endif // PRINT_H
