#include "modeoperation.h"
#include "ui_modeoperation.h"

ModeOperation::ModeOperation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModeOperation)
{
    ui->setupUi(this);
}

ModeOperation::~ModeOperation()
{
    delete ui;
}

void ModeOperation::on_BtnKretschmann_clicked()
{
    objK.show();

}
