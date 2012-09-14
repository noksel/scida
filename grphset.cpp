#include "grphset.h"
#include "ui_grphset.h"

GrphSet::GrphSet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GrphSet)
{
    ui->setupUi(this);
    move(0,185);
}

GrphSet::~GrphSet()
{
    delete ui;
}
