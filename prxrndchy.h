#ifndef PRXRNDCHY_H
#define PRXRNDCHY_H
#include "rndchy.h"
#include "prxchannel.h"

class PrxRndChY : public prxChannel
{
    Q_OBJECT
private:
    RndChY* ch;
public:
    explicit PrxRndChY(QObject *parent = 0);
    PrxRndChY(RndChY* rndChY);
    double getValue();
signals:

public slots:
    
};

#endif // PRXRNDCHY_H
