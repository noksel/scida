#ifndef PRXRNDCHX_H
#define PRXRNDCHX_H
#include "prxchannel.h"
#include "rndchx.h"

class PrxRndChX : public prxChannel
{
    RndChX* ch;
    double min;
    double max;
    double step;
    double current;
    Q_OBJECT
public:
    explicit PrxRndChX(QObject *parent = 0);
    PrxRndChX(RndChX* rndChX);
    double getValue();
signals:
    
public slots:
    
};

#endif // PRXRNDCHX_H
