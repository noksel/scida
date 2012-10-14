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
    return 0;
}

double stepper::getStep(double curVal)
{
    if (((_max-_min)/2-30<=curVal)&&(curVal<=(_max-_min)/2+30))
    {
        return 1;
    }
    else if ((_min<=curVal)&&(curVal<=_max))
            return _step;
    return 0;
}
