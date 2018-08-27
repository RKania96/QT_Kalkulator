#ifndef DECORATOR_H
#define DECORATOR_H

#include "client.h"
#include <QString>

class Decorator: public Client
{
    Client *client;

public:
    Decorator(Client *c);
    QString showLog();
};

#endif // DECORATOR_H


