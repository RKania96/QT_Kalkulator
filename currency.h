#ifndef CURRENCY_H
#define CURRENCY_H

#include <QDialog>
#include "downloader.h"
#include "print.h"

namespace Ui {
class Currency;
}

class Currency : public QDialog
{
    Q_OBJECT

public:
    explicit Currency(QWidget *parent = 0);

    ~Currency();

private slots:
    void on_pushButton_start_released();
    void on_pushButton_GBP_released();
    void on_pushButton_EUR_released();
    void on_pushButton_USD_released();

private:
    Ui::Currency *ui;
    Print* m_print;

};

#endif // CURRENCY_H
