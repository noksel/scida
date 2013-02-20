#ifndef PRXRNDCHX_H
#define PRXRNDCHX_H
#include "prxchannel.h"
#include "rndchx.h"
#include "stepper.h"
#include <QTimer>

class PrxRndChX : public prxChannel
{
    RndChX* ch;
// setting Window!!!
    stepper* st;
    double min;
    double max;
    double step;
    double current;
    double next;
    bool f_end;
    int delay;
    QTimer timer;
    Q_OBJECT
public:
    explicit PrxRndChX(QObject *parent = 0);
    PrxRndChX(RndChX* rndChX);
    double getValue(); // return next value
    double getCurValue(); // get value without changing
    bool getNextValue();
    bool isEnd();
signals:
    void valueReady(double);
    void valueSetted(double); // run the timer


public slots:

private slots:
    void isSetted();
    
};

#endif // PRXRNDCHX_H
