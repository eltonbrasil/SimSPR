#include "kretschmann.h"
#include "ui_kretschmann.h"

Kretschmann::Kretschmann(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Kretschmann)
{
    ui->setupUi(this);
}

Kretschmann::~Kretschmann()
{
    delete ui;
}

void Kretschmann::on_pushButton_3_clicked()
{

    close();
}

void Kretschmann::on_pushButton_clicked()
{

}

void Kretschmann::on_pushButton_2_clicked()
{
    objF.show();
}
