#include "rndchx.h"

RndChX::RndChX(QObject *parent) :
    ChannelX(parent)
{
}

RndChX::RndChX(QString chname)
{
    name=chname;

}

bool RndChX::setX(double x)
{


    emit changed(x*10);
    return true;
}



bool RndChX::clearCh()
{

    emit changed(0);
    return true;
}



