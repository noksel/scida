#ifndef STEPPER_H
#define STEPPER_H

#include <QObject>
#include <QVector>



class stepper : public QObject
{
    Q_OBJECT
    class range :public QObject
    {
        double r_min; // range min
        double r_max; // range max
        double r_step; //range step

    public:
        range (double min,double max,double step)
        {
           r_min=min;
           r_max=max;
           r_step=step;
        }
        double getStep()
        {
            return r_step;
        }
        double getMax()
        {
            return r_max;
        }
        double getMin()
        {
            return r_min;
        }
    };


    QVector<range*> ranges;
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
