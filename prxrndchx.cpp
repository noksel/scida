#include "prxrndchx.h"

PrxRndChX::PrxRndChX(QObject *parent) :
    prxChannel(parent)
{
}

PrxRndChX::PrxRndChX(RndChX *rndChX)
{
    ch = rndChX;
    min=0;
    max=490;
    step=10;
    current=min-step;
    name= "proxyRndCh_X";

}

double PrxRndChX::getValue()
{
    current+=step;



    if((current>=min)&&(current<=max))
    {
        ch->setX(current);
        double tmp=current;

        if((current+step)>max)
        {
            current=min-step;
            emit End();


        }

        return tmp;
    }


    return 0;
}
