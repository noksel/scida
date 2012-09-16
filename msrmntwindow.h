#ifndef MSRMNTWINDOW_H
#define MSRMNTWINDOW_H

#include <QMainWindow>
#include "measurement.h"
#include <QStandardItemModel>
#include "channelx.h"
#include "channely.h"
#include <KDChart/KDChartChart>
#include <KDChart/KDChartWidget>
#include <KDChart/KDChartPlotter>
#include <KDChart/KDChartCartesianAxis>

//#include <tr1/stdlib.h>
#include <QStandardItemModel>
#include <QTimer>
#include "prxchannel.h"

namespace Ui {
class MsrmntWindow;
}

class MsrmntWindow : public QMainWindow
{
    Q_OBJECT
    measurement *msrmnt;
    QStandardItemModel * data;

public:
    explicit MsrmntWindow(QWidget *parent = 0);
//    MsrmntWindow(QString title,ChannelX* chanX,ChannelY* chanY );
    //uncommit if want to realese watching after channel.
     MsrmntWindow(QString title,prxChannel* chanX, prxChannel* chanY );
    ~MsrmntWindow();
public slots:
    void activate();
    
private:
    Ui::MsrmntWindow *ui;
};

#endif // MSRMNTWINDOW_H
