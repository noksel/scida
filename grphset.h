#ifndef GRPHSET_H
#define GRPHSET_H

#include <QDialog>

namespace Ui {
class GrphSet;
}

class GrphSet : public QDialog
{
    Q_OBJECT
    
public:
    explicit GrphSet(QWidget *parent = 0);
    ~GrphSet();
    
private:
    Ui::GrphSet *ui;
};

#endif // GRPHSET_H
