#ifndef RNDCHY_H
#define RNDCHY_H
#include "channely.h"
#include <QTime>
class RndChY : public ChannelY
{
    Q_OBJECT
private:
    int broad;
    float infl;
public:
    explicit RndChY(QObject *parent = 0);
    RndChY(QString);
    void setBroad(int br);
    double getY();

    bool clearCh();
    
signals:
    
public slots:
    void setInfluence(double);
    
};

#endif // RNDCHY_H
