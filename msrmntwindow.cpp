#include "msrmntwindow.h"
#include "ui_msrmntwindow.h"
#include "QThread"

MsrmntWindow::MsrmntWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MsrmntWindow)
{
    ui->setupUi(this);
}

/*MsrmntWindow::MsrmntWindow(QString title, ChannelX *chanX, ChannelY *chanY):ui(new Ui::MsrmntWindow)
{

     ui->setupUi(this);
     data= new QStandardItemModel();
     msrmnt= new measurement(title,chanX,chanY,data);

     QThread *th = new QThread(); // delete!!!
     data->moveToThread(th);
     msrmnt->moveToThread(th);
     th->start();


     connect(ui->actionMeasure,SIGNAL(triggered()),msrmnt,SLOT(measure()));

     this->setWindowTitle(msrmnt->getMesTitle());



        QHBoxLayout* chartLayout = new QHBoxLayout( ui->centralwidget );
       KDChart::Widget* chart  = new KDChart::Widget();
        chartLayout->addWidget( chart );


          KDChart::Plotter* plotter = new KDChart::Plotter;
          plotter->setModel(data);
           chart->coordinatePlane()->replaceDiagram( plotter );


           KDChart::CartesianAxis *xAxis = new KDChart::CartesianAxis( plotter );
           KDChart::CartesianAxis *yAxis = new KDChart::CartesianAxis (plotter);
           xAxis->setPosition (KDChart:: CartesianAxis::Bottom );
           yAxis->setPosition ( KDChart::CartesianAxis::Left );
           xAxis->setTitleText ( "Abscissa bottom position" );
           yAxis->setTitleText ( "Ordinate left position" );

           plotter->addAxis( xAxis );
           plotter->addAxis( yAxis );


}*/

MsrmntWindow::MsrmntWindow(QString title, prxChannel *chanX, prxChannel *chanY):ui(new Ui::MsrmntWindow)
{
    ui->setupUi(this);
    data= new QStandardItemModel();
    msrmnt= new measurement(title,chanX,chanY,data);

    QThread *th = new QThread(); // delete!!!
    data->moveToThread(th);
    msrmnt->moveToThread(th);
    connect(chanX,SIGNAL(End()),msrmnt,SLOT(stop()));
    th->start();


    connect(ui->actionMeasure,SIGNAL(triggered()),msrmnt,SLOT(measure()));

    this->setWindowTitle(msrmnt->getMesTitle());



       QHBoxLayout* chartLayout = new QHBoxLayout( ui->centralwidget );
      KDChart::Widget* chart  = new KDChart::Widget();
       chartLayout->addWidget( chart );




         // KDChart::Chart* chart = new KDChart::Chart;
        /* LineDiagram* m_lines = new LineDiagram();
          m_lines->setModel( model );*/

         KDChart::Plotter* plotter = new KDChart::Plotter;
         plotter->setModel(data);
          chart->coordinatePlane()->replaceDiagram( plotter );


          KDChart::CartesianAxis *xAxis = new KDChart::CartesianAxis( plotter );
          KDChart::CartesianAxis *yAxis = new KDChart::CartesianAxis (plotter);
          xAxis->setPosition (KDChart:: CartesianAxis::Bottom );
          yAxis->setPosition ( KDChart::CartesianAxis::Left );
          xAxis->setTitleText ( "Abscissa bottom position" );
          yAxis->setTitleText ( "Ordinate left position" );

          plotter->addAxis( xAxis );
          plotter->addAxis( yAxis );
}

MsrmntWindow::~MsrmntWindow()
{
    delete ui;
}

void MsrmntWindow::activate()
{
    this->activateWindow();
}
