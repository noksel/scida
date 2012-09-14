#ifndef MEASURMENT_H
#define MEASURMENT_H

#include <QObject>
#include <QTimer>
#include "channelx.h"
#include "channely.h"
#include <QStandardItemModel>

class measurement : public QObject
{
    Q_OBJECT
public:
    channel* chX;
    channel* chY;
    double min;
    int delay; // between measure
    bool stop_flag;

    double max;
    QString name;
    int i; //current index of point to measure
    int n; // all quantity of points
    int curveId;
    QTimer* tmr;
    QStandardItemModel* data;
    // generator shaga

    explicit measurement(QObject *parent = 0);
    measurement(QString title,ChannelX* chanX,ChannelY* chanY, QStandardItemModel *storage);

    QString getMesTitle();
    
signals:
    
public slots:

    void measure();

private slots:
    void singleMeasure();

    
};

#endif // MEASURMENT_H
