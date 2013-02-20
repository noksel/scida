#include "prxchannel.h"

prxChannel::prxChannel(QObject *parent) :
    QObject(parent)
{
}

QString prxChannel::getName()
{
    return name;
}
