#ifndef MEASURMENT_H
#define MEASURMENT_H

#include <QObject>
#include <QTimer>
#include "channelx.h"
#include "channely.h"
#include <QStandardItemModel>
#include "prxchannel.h"
#include "prxrndchx.h"

class measurement : public QObject
{
    Q_OBJECT
public:
  //  channel* chX; //old version
 //   channel* chY; //old version
    prxChannel* chX;
    prxChannel* chY;

    double min;
    int delay; // between measure
    bool stop_flag;


    QString name;
    int i; //current index of point to measure
    int n; // all quantity of points
    int curveId;
    QTimer* tmr;
    QStandardItemModel* data;
    // generator shaga

    explicit measurement(QObject *parent = 0);
  //  measurement(QString title,ChannelX* chanX,ChannelY* chanY, QStandardItemModel *storage);
      measurement(QString title, prxChannel* chanX,prxChannel* chanY, QStandardItemModel *storage);

    QString getMesTitle();
    
signals:
    
public slots:

    void measure();

private slots:
    void singleMeasure();
    void stop();
    void getData(double x);

    
};

#endif // MEASURMENT_H
