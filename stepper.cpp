#include "stepper.h"

stepper::stepper(QObject *parent) :
    QObject(parent)
{
}

int stepper::addRange(double l_min, double l_max, double step)
{
    _min=l_min;
    _max=l_max;
    _step=step;
    range *rn=new range(l_min,l_max,step);
    ranges.prepend(rn);
    return 0;
}

double stepper::getStep(double curVal)
{
     QVector<range*>::iterator i;

     for(i=ranges.begin();i!=ranges.end();++i)
     {
         if (((*i)->getMin() <=curVal)&&(curVal<= (*i)->getMax()))
                return (*i)->getStep();
     }


    return 0;
}
