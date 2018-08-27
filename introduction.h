#ifndef INTRODUCTION_H
#define INTRODUCTION_H

#include <QString>
#include "client.h"
#include <QDebug>

class Introduction:public Client
{
    QString m_mode;
public:
    Introduction(QString mode);
    QString showLog();
};

#endif // INTRODUCTION_H
