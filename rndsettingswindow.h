#ifndef RNDSETTINGSWINDOW_H
#define RNDSETTINGSWINDOW_H

#include <QDialog>
#include "rnddev.h"


namespace Ui {
class RndSettingsWindow;
}

class RndSettingsWindow : public QDialog
{
    Q_OBJECT
private:
    RndDev* rdev;
    
public:
    explicit RndSettingsWindow(QWidget *parent = 0);
    RndSettingsWindow(RndDev* dev);
    ~RndSettingsWindow();
    
private:
    Ui::RndSettingsWindow *ui;
public slots:
    void setBroad();
};

#endif // RNDSETTINGSWINDOW_H
