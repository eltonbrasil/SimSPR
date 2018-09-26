#ifndef KRETSCHMANN_H
#define KRETSCHMANN_H

#include <QWidget>
#include <QMessageBox>
#include "fill.h"


namespace Ui {
class Kretschmann;
}

class Kretschmann : public QWidget
{
    Q_OBJECT

public:
    explicit Kretschmann(QWidget *parent = 0);
    ~Kretschmann();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Kretschmann *ui;

    Fill objF;
};

#endif // KRETSCHMANN_H
