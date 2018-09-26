#include "axis.h"
#include "ui_axis.h"

Axis::Axis(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Axis)
{
    ui->setupUi(this);
}

Axis::~Axis()
{
    delete ui;
}
