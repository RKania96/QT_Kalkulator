#ifndef PROGRAMMER_H
#define PROGRAMMER_H

#include <QMainWindow>
#include "print.h"


namespace Ui {
class Programmer;
}

class Programmer : public QMainWindow
{
    Q_OBJECT

public:
    explicit Programmer(QWidget *parent = 0);
    ~Programmer();
    Print* m_print;



private slots:
    void digit_pressed();
    void on_pushButton_clear_released();

    void on_pushButton_binary_released();
    void on_pushButton_decimal_released();

private:
    Ui::Programmer *ui;
};

#endif // PROGRAMMER_H
