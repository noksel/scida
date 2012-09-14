#include "rndsettingswindow.h"
#include "ui_rndsettingswindow.h"

RndSettingsWindow::RndSettingsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RndSettingsWindow)
{
    ui->setupUi(this);
}

RndSettingsWindow::RndSettingsWindow(RndDev *dev): ui(new Ui::RndSettingsWindow)
{
    ui->setupUi(this);
    rdev=dev;
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(setBroad()));
}

RndSettingsWindow::~RndSettingsWindow()
{
    delete ui;
}

void RndSettingsWindow::setBroad()
{
    ((RndChY*)rdev->getChannelsY()[0])->setBroad(ui->spinBox->value());
}
