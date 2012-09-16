#ifndef PRXCHANNEL_H
#define PRXCHANNEL_H

#include <QObject>

class prxChannel : public QObject
{
    Q_OBJECT
protected:
    QString name;
public:
    QString getName();
    explicit prxChannel(QObject *parent = 0);
   virtual double getValue()=0;
    
signals:
    void End();
    
public slots:
    
};

#endif // PRXCHANNEL_H
