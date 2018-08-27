#ifndef LOGPROGRAMMER_H
#define LOGPROGRAMMER_H

#include "decorator.h"
#include <QString>
#include <QDebug>
#include <QFile>

class LogProgrammer: public Decorator
{
public:
    LogProgrammer(Client *c): Decorator(c) {}

    QString showLog();
};

#endif // LOGPROGRAMMER_H
