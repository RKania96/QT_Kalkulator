#include "introduction.h"

Introduction::Introduction(QString mode)
{
    m_mode = mode;
}

QString Introduction::showLog()
{
    qDebug()  << m_mode;
    return 0;
}
