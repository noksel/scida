#include "rnddev.h"

RndDev::RndDev(QObject *parent) :
    device(parent)
{
}

RndDev::RndDev(QString devName)
{
    name=devName;
    chsX.push_back(new RndChX("rndX"));

        chsY.push_back( new RndChY("rndY"));
        chsY.push_back( new RndChY("rndY_1"));
        RndChX* tX=(RndChX*)chsX[0];
        RndChY* tY=(RndChY*)chsY[0];
        connect(tX,SIGNAL(changed(double)),tY,SLOT(setInfluence(double)));

}
