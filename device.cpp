#include "device.h"

device::device(QObject *parent) :
    QObject(parent)
{
}

device::device(QString devName)
{
    name=devName;
   /* chsX.push_back(new RndChX("rndX"));

    chsY.push_back( new RndChY("rndY"));
    chsY.push_back( new RndChY("rndY_1"));*/

}

QString device::getDevName()
{
    return name;
}

QVector<ChannelX*> &device::getChannelsX()
{
    return chsX;
}

QVector<ChannelY *> &device::getChannelsY()
{
    return chsY;
}



