#include "decorator.h"

Decorator::Decorator(Client *c)
{
    client=c;
}

QString Decorator::showLog()
{
        client->showLog();

}
