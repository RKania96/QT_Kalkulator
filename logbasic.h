#ifndef LOGBASIC_H
#define LOGBASIC_H


#include "decorator.h"
#include <QString>
#include <QDebug>
#include <QFile>

class LogBasic:public Decorator
{
public:

    LogBasic(Client *c): Decorator(c) {}

    QString showLog();
};

#endif // LOGBASIC_H
