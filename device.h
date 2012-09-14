#ifndef DEVICE_H
#define DEVICE_H

#include <QObject>
#include "channelx.h"
#include "channely.h"

#include "rndchx.h"
#include "rndchy.h"
#include <QVector>


class device : public QObject
{
    Q_OBJECT
private:
  //  virtual void abstFunc()=0; //just to deny create device objects
protected:
    QString name;
    QVector<ChannelX*> chsX;
    QVector<ChannelY*> chsY;
public:
    explicit device(QObject *parent = 0);
    device(QString);
    QString getDevName();
    QVector<ChannelX*>& getChannelsX();
    QVector<ChannelY*>& getChannelsY();
    
signals:
    
public slots:
    
};

#endif // DEVICE_H
