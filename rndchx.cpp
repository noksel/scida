#include "rndchx.h"

RndChX::RndChX(QObject *parent) :
    ChannelX(parent)
{
}

RndChX::RndChX(QString chname)
{
    name=chname;
    val=0;
}

bool RndChX::setX(double x)
{
    qDebug()<<name<<"set:"<<x;
    val=x;
    emit changed(val*10);
    return true;
}

double RndChX::getVal()
{

    emit changed(val*10);

    return val++*10;
}

bool RndChX::clearCh()
{
    val=0;
    emit changed(val*10);
    return true;
}



