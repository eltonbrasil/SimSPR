#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionGeneral_triggered()
{
    general.show();
}

void MainWindow::on_actionAxis_triggered()
{
    axis.show();
}

void MainWindow::on_actionLayer_triggered()
{
    layer.show();
}

void MainWindow::on_actionInfo_triggered()
{
    help.showNormal();
}
