#ifndef LOGCURRENCY_H
#define LOGCURRENCY_H

#include "decorator.h"
#include <QString>
#include <QDebug>
#include <QFile>

class LogCurrency: public Decorator
{
public:
    LogCurrency(Client *c): Decorator(c) {}

    QString showLog();
};

#endif // LOGCURRENCY_H
