#include "channel.h"

channel::channel(QObject *parent) :
    QObject(parent)
{
}

channel::channel(QString ch_name)
{
    name=ch_name;
}

QString channel::getName()
{
    return name;
}
