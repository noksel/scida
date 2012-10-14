#include "prxrndchx.h"

PrxRndChX::PrxRndChX(QObject *parent) :
    prxChannel(parent)
{
}

PrxRndChX::PrxRndChX(RndChX *rndChX)
{
    ch = rndChX;
    min=0;
    max=590;
    step=10;
    current=min;
    name= "proxyRndCh_X";
    st= new stepper();
    st->addRange(min,max,step);

}

double PrxRndChX::getValue()
{
    qDebug()<<"curr "<<current<<"stp "<<st->getStep(current);




    if((current>=min)&&(current<=max))
    {
        ch->setX(current);
        double tmp=current;
        current+=st->getStep(current);
        if(current>max)
        {
            current=min;
            emit End();

        }

        return tmp;
    }


    return 0;
}
