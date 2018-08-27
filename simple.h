#ifndef SIMPLE_H
#define SIMPLE_H

#include <QMainWindow>
#include "ui_simple.h"
#include "print.h"


namespace Ui {
class Simple;
}

class Simple : public QMainWindow
{
    Q_OBJECT

public:
    explicit Simple(QWidget *parent = 0);
    ~Simple();

private:
    Ui::Simple *ui;
    Print* m_print;

private slots:
    void digit_pressed();
    void on_pushButton_decimal_released();
    void unary_operation_pressed();
    void on_pushButton_clear_released();
    void on_pushButton_equals_released();
    void binary_operation_pressed();

};

#endif // SIMPLE_H
