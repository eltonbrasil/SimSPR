#include "layer.h"
#include "ui_layer.h"

Layer::Layer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Layer)
{
    ui->setupUi(this);
}

Layer::~Layer()
{
    delete ui;
}
