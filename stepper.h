#ifndef STEPPER_H
#define STEPPER_H

#include <QObject>

class stepper : public QObject
{
    Q_OBJECT

    double _min;
    double _max;
    double _step;

public:
    explicit stepper(QObject *parent = 0);
    int addRange(double l_min,double l_max, double step);
    double getStep(double curVal);

    
signals:
    
public slots:
    
};

#endif // STEPPER_H
