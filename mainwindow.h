#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <grphset.h>
#include <QCloseEvent>

#include "channel.h"
#include "channelx.h"
#include "rndchx.h"
#include "rndchy.h"
#include "device.h"
#include "rnddev.h"
#include "rndsettingswindow.h"
#include <QVector>
#include "createmeasurement.h"
#include "msrmntwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void closeEvent(QCloseEvent *);
private:
    Ui::MainWindow *ui;
    GrphSet *gWin;
    QVector <device*> dvces;
    RndSettingsWindow* rSW;
    CreateMeasurement* cmWindow;

signals:
    void closeAll();

public slots:
    void addMsrmntWindow(MsrmntWindow* window);
    void ShowGrpSet();
    void AddWindow();
    //void ;
};

#endif // MAINWINDOW_H
