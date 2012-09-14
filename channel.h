#ifndef CHANNEL_H
#define CHANNEL_H

#include <QObject>
#include <QDebug>

class channel : public QObject
{
    Q_OBJECT
public:
    explicit channel(QObject *parent = 0);
    channel(QString);
    QString getName();
    virtual double getVal()=0;
    virtual bool clearCh()=0;

protected:
    QString name;

private:
   // virtual void absFunc()=0; // just to deny create channel objects;
signals:
    
public slots:
    
};

#endif // CHANNEL_H
