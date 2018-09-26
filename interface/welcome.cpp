#include "welcome.h"
#include "ui_welcome.h"

Welcome::Welcome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);
    this->ui->progressBar->setValue(0);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerEvent()));
    timer->start(1000);
}

Welcome::~Welcome()
{
    delete ui;
}

void Welcome::timerEvent(){
    int value = this->ui->progressBar->value();
    this->ui->progressBar->setValue(value+10);
    if(value == 100)
    {

        mo.show();
        close();
    }
}
