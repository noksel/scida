#include "prxrndchy.h"

PrxRndChY::PrxRndChY(QObject *parent) :
    prxChannel(parent)
{
}

PrxRndChY::PrxRndChY(RndChY *rndChY)
{
    ch=rndChY;
    name= "proxyRndCh_Y";
}

double PrxRndChY::getValue()
{
   return ch->getY();
}
