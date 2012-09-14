#ifndef RNDCHX_H
#define RNDCHX_H
#include "channelx.h"

class RndChX : public ChannelX
{
    Q_OBJECT
    double val;
public:
    explicit RndChX(QObject *parent = 0);
    RndChX(QString);
    bool setX(double);
    double getVal();
    bool clearCh();

signals:
    void changed(double);

public slots:
    
};

#endif // RNDCHX_H
