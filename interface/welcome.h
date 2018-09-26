#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>
#include <QTimer>

#include "modeoperation.h"

namespace Ui {
class Welcome;
}

class Welcome : public QWidget
{
    Q_OBJECT

public:
    explicit Welcome(QWidget *parent = 0);
    ~Welcome();
public slots:
    void timerEvent();

private:
    Ui::Welcome *ui;
    ModeOperation mo;
};

#endif // WELCOME_H
