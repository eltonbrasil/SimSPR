#ifndef LAYER_H
#define LAYER_H

#include <QWidget>

namespace Ui {
class Layer;
}

class Layer : public QWidget
{
    Q_OBJECT

public:
    explicit Layer(QWidget *parent = nullptr);
    ~Layer();

private:
    Ui::Layer *ui;
};

#endif // LAYER_H
