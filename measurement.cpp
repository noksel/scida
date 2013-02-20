#include "measurement.h"

measurement::measurement(QObject *parent) :
    QObject(parent)
{
}



measurement::measurement(QString title, prxChannel* chanX,prxChannel* chanY, QStandardItemModel *storage)
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
    connect( ((PrxRndChX*)chX), SIGNAL(valueReady(double)),this,SLOT(getData(double)));
    }
    curveId++;
    i=0;
   data->setColumnCount((curveId+1)*2);
    data->setRowCount(1000);
    singleMeasure();
  //  tmr->start(delay);




   /* for( int i = 0; i < 50; ++i )
    {

        data->setData( data->index( i, 0 ), i );
        data->setData( data->index( i, 1 ), chY->getY());
    }
 */
}

void measurement::singleMeasure()
{

       // chX->setX(i*10);double d=
    if (!((PrxRndChX*)chX)->isEnd())
    {
          ((PrxRndChX*)chX)->getNextValue();
     /*   qDebug()<<d;

        data->setData( data->index( i, curveId*2 ),  d);
        data->setData( data->index( i, curveId*2+1 ), chY->getValue());
        i++;*/
    }
    else
    {
        qDebug()<<"stop";
        tmr->stop();
    }



}

void measurement::stop()
{

    tmr->stop();

}

void measurement::getData(double x)
{
    double x1=((PrxRndChX*)chX)->getCurValue();
    double y=chY->getValue();

    data->setData( data->index( i, curveId*2 ), x );
    data->setData( data->index( i, curveId*2+1 ), y);
    qDebug()<<"x " << x <<"y " <<y;
     i++;
     if (!((PrxRndChX*)chX)->isEnd())
     {
        singleMeasure();
     }
}
