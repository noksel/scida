#ifndef RNDDEV_H
#define RNDDEV_H
#include "device.h"


class RndDev : public device
{
    Q_OBJECT
private:

public:
    explicit RndDev(QObject *parent = 0);
    RndDev(QString devName);
    
signals:
    
public slots:
    
};

#endif // RNDDEV_H
