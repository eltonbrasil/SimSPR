#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <general.h>
#include <axis.h>
#include <layer.h>
#include <help.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionGeneral_triggered();

    void on_actionAxis_triggered();

    void on_actionLayer_triggered();

    void on_actionInfo_triggered();

private:
    Ui::MainWindow *ui;
    General general;
    Axis axis;
    Layer layer;
    Help help;
};

#endif // MAINWINDOW_H
