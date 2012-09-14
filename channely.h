#ifndef CHANNELY_H
#define CHANNELY_H
#include "channel.h"

class ChannelY : public channel
{
    Q_OBJECT
public:
    explicit ChannelY(QObject *parent = 0);
    virtual double getY()=0;
    
signals:
    
public slots:
    
};

#endif // CHANNELY_H
