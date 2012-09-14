#ifndef CREATEMEASUREMENT_H
#define CREATEMEASUREMENT_H

#include <QDialog>
#include "device.h"
#include <QVector>
#include "msrmntwindow.h"
/* crate measuremetnObj(chX,chY,data_storage), create measurementWindow(measurementObj) [get dataStorage from measurementObj]
  createmeasurment send SIGNAL(createedMes(measurementWindow)) to MainWindow SLOT(addNewWindow(measurementWindow))
  */
namespace Ui {
class CreateMeasurement;
}

class CreateMeasurement : public QDialog
{
    Q_OBJECT
    
public:
    explicit CreateMeasurement(QWidget *parent = 0);
    CreateMeasurement(QVector<device*> dvcs);
    ~CreateMeasurement();
    
private:
    Ui::CreateMeasurement *ui;
    QVector<device*> devs;
signals:
   void createdMsrmnWindow(MsrmntWindow* window);
public slots:
    void createMeasurement();
};

#endif // CREATEMEASUREMENT_H
