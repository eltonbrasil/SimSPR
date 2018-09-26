#ifndef FILL_H
#define FILL_H

#include <QWidget>

namespace Ui {
class Fill;
}

class Fill : public QWidget
{
    Q_OBJECT

public:
    explicit Fill(QWidget *parent = 0);
    ~Fill();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Fill *ui;
};

#endif // FILL_H
