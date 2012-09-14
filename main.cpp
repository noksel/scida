#include <QtGui/QApplication>
#include "mainwindow.h"
#include "channel.h"
#include "channelx.h"
#include "rndchx.h"
#include "rndchy.h"
#include "device.h"
#include "rnddev.h"

#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    w.show();




    QObject::connect(&w,SIGNAL(closeAll()),&a,SLOT(closeAllWindows()));


    
    return a.exec();
}
