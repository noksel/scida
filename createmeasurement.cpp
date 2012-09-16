#include "createmeasurement.h"
#include "ui_createmeasurement.h"

CreateMeasurement::CreateMeasurement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateMeasurement)
{
    ui->setupUi(this);
}

CreateMeasurement::CreateMeasurement(QVector<device *> dvcs):ui(new Ui::CreateMeasurement)
{
    devs=dvcs;

     ui->setupUi(this);

    for(int i =0;i<dvcs[0]->getChannelsX().count();i++)
    {
        ui->comboBox->addItem(dvcs[0]->getChannelsX()[i]->getName());
    }

    for(int i =0;i<dvcs[0]->getChannelsY().count();i++)
    {
        ui->comboBox_2->addItem(dvcs[0]->getChannelsY()[i]->getName());
    }
    connect(ui->crtButton,SIGNAL(clicked()),this,SLOT(createMeasurement()));
    connect(ui->cnclButton,SIGNAL(clicked()),this,SLOT(close()));

}



CreateMeasurement::~CreateMeasurement()
{
    delete ui;
}

void CreateMeasurement::createMeasurement()
{
   // MsrmntWindow* nw = new MsrmntWindow(ui->lineEdit->text(),devs[0]->getChannelsX()[0],devs[0]->getChannelsY()[0]);
    PrxRndChX* x= new PrxRndChX((RndChX*)devs[0]->getChannelsX()[0]);

    PrxRndChY* y = new PrxRndChY((RndChY*)devs[0]->getChannelsY()[0]);

   MsrmntWindow* nw = new MsrmntWindow(ui->lineEdit->text(),x,y);
    nw->show();
    emit createdMsrmnWindow(nw);


    close();
}
