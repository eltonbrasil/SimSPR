#ifndef AXIS_H
#define AXIS_H

#include <QWidget>

namespace Ui {
class Axis;
}

class Axis : public QWidget
{
    Q_OBJECT

public:
    explicit Axis(QWidget *parent = nullptr);
    ~Axis();

private:
    Ui::Axis *ui;
};

#endif // AXIS_H
