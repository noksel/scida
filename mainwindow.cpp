#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    gWin = new GrphSet();
    gWin->show();
    connect(ui->actionShow_Graphs,SIGNAL(triggered()),this,SLOT(ShowGrpSet()));
    connect(ui->actionAddWindow,SIGNAL(triggered()),this,SLOT(AddWindow()));

    move(0,0);

    dvces.push_back( new RndDev("Random Dev"));
    rSW= new RndSettingsWindow((RndDev*)dvces[0]);

    cmWindow = new CreateMeasurement(dvces);


 /*  qDebug()<<dvces[0]->getChannelsX().value(0)->getName();

   for(int i =0;i<dvces[0]->getChannelsY().count();i++)
   {
       qDebug()<<dvces[0]->getChannelsY()[i]->getY();
   }
*/
   QMenu* rdM = ui->menuDevices->addMenu(dvces[0]->getDevName());
    QAction* cr =rdM->addAction("Settings");

    connect(cr,SIGNAL(triggered()),rSW,SLOT(show()));
    connect(cmWindow,SIGNAL(createdMsrmnWindow(MsrmntWindow*)),this,SLOT(addMsrmntWindow(MsrmntWindow*)));



}

MainWindow::~MainWindow()
{
    delete gWin;
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *ev)
{
    emit closeAll();
   // gWin->close();
    ev->accept();
}

void MainWindow::ShowGrpSet()
{
    if (gWin->isHidden())
    gWin->show();
    else
        gWin->hide();
}

void MainWindow::AddWindow()
{
     cmWindow->show();
  /* GrpWind * dg = new GrpWind();
    dg->show();
    QAction* cr = ui->menuWindows->addAction("window");

    connect(cr,SIGNAL(activated()),dg,SLOT(show()));
  //  connect(cr,SIGNAL(activated()),dg,SLOT(setFocus()));
    connect(cr,SIGNAL(activated()),dg,SLOT(activW()));*/



}

void MainWindow::addMsrmntWindow(MsrmntWindow *window)
{
    QAction* cr = ui->menuWindows->addAction(window->windowTitle());
    connect(cr,SIGNAL(triggered()),window,SLOT(show()));
    connect(cr,SIGNAL(triggered()),window,SLOT(activate()));

}
