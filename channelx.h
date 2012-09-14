#ifndef CHANNELX_H
#define CHANNELX_H

#include "channel.h"
class ChannelX : public channel
{
    Q_OBJECT
public:
    explicit ChannelX(QObject *parent = 0);
    virtual bool setX(double)=0;
    
signals:
    
public slots:
    
};

#endif // CHANNELX_H
