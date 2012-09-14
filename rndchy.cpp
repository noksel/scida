#include "rndchy.h"

RndChY::RndChY(QObject *parent) :
    ChannelY(parent)
{
}

RndChY::RndChY(QString chname)
{
    name=chname;
    qsrand(QTime::currentTime().msec());
    broad=0;
    infl=0;
}

void RndChY::setBroad(int br)
{
    broad = br;
}

double RndChY::getY()
{
    if (broad==0)
        return ((double)qrand()+infl);
    else
        return ((double)(qrand()%broad)+infl);
}

double RndChY::getVal()
{
    if (broad==0)
        return ((double)qrand()+infl);
    else
        return ((double)(qrand()%broad)+infl);
}

bool RndChY::clearCh()
{
    return true;
}

void RndChY::setInfluence(double influence)
{
    infl=influence;
}
