#include "prxrndchx.h"

PrxRndChX::PrxRndChX(QObject *parent) :
    prxChannel(parent)
{
}

PrxRndChX::PrxRndChX(RndChX *rndChX)
{
    ch = rndChX;
    delay=10;
    f_end=false;
    min=0;
    max=590;
    step=10;
    current=min;
    next=min;
    timer.setSingleShot(true);
    connect(&timer,SIGNAL(timeout()),this,SLOT(isSetted()));
    name= "proxyRndCh_X";
    st= new stepper();
    st->addRange(min,max,step);
    st->addRange((max-min)/2-30,(max-min)/2+30,1);
    st->addRange(100,150,0.5);


}

double PrxRndChX::getValue()
{
    qDebug()<<"deprecated method";
/*
    qDebug()<<"curr "<<current<<"stp "<<st->getStep(current);


    if((current>=min)&&(current<=max))
    {
        current=next;
        ch->setX(current);

        emit valueSetted();

        next=current+st->getStep(current); //maby will do proxy for channel and create object "cannel" when we start measurment

        if(next>max||next<min)
        {

            f_bool=false;
            emit End();

        }

        return tmp;
    }*/


    return 0;
}

double PrxRndChX::getCurValue()
{
    return current;
}

bool PrxRndChX::getNextValue()
{

    if((current>=min)&&(current<=max))
    {
        current=next;
      //  qDebug()<<"curr "<<current<<"stp "<<st->getStep(current);
        ch->setX(current);

        timer.start(delay);
        next=current+st->getStep(current); //maby will do proxy for channel and create object "cannel" when we start measurment
    //    qDebug()<<"next "<<next<<"stp "<<st->getStep(current);

      return true;
    }
    return false;

}

bool PrxRndChX::isEnd()
{
    if(next>max||next<min)
    {
        current=min;
        next=min;
        return true;

    }
    return false;
}

void PrxRndChX::isSetted()
{
    emit valueReady(current);
}



