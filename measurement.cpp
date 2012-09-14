#include "measurement.h"

measurement::measurement(QObject *parent) :
    QObject(parent)
{
}

measurement::measurement(QString title,ChannelX *chanX, ChannelY *chanY, QStandardItemModel* storage)
{
    chX=chanX;
    chY=chanY;
    tmr=0;
    delay = 100;
    stop_flag=false;
    i=0;
    n=50;
    curveId=-1;
    data=storage;
    this->name=title;


}


QString measurement::getMesTitle()
{
    return name;
}



void measurement::measure()
{
    if(!tmr)
    {
    tmr = new QTimer();
    connect(tmr,SIGNAL(timeout()),this,SLOT(singleMeasure()));
    }
    curveId++;
   data->setColumnCount((curveId+1)*2);
    data->setRowCount(1000);
    tmr->start(delay);




   /* for( int i = 0; i < 50; ++i )
    {

        data->setData( data->index( i, 0 ), i );
        data->setData( data->index( i, 1 ), chY->getY());
    }
    qDebug()<<"measure";*/
}

void measurement::singleMeasure()
{

    if(i<n)  // !stop_flag
    {
       // chX->setX(i*10);

        data->setData( data->index( i, curveId*2 ),  chX->getVal());
        data->setData( data->index( i, curveId*2+1 ), chY->getVal());
        i++;
    }
    else
    {
        i=0;
        chX->clearCh();
        chY->clearCh();
        tmr->stop();


    }
}
