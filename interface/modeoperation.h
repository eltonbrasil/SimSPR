#ifndef MODEOPERATION_H
#define MODEOPERATION_H

#include <QWidget>
#include <mainwindow.h>

namespace Ui {
class ModeOperation;
}

class ModeOperation : public QWidget
{
    Q_OBJECT

public:
    explicit ModeOperation(QWidget *parent = 0);
    ~ModeOperation();

private slots:
    void on_BtnKretschmann_clicked();

private:
    Ui::ModeOperation *ui;

    MainWindow objK;
};

#endif // MODEOPERATION_H
