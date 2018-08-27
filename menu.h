#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "strategy.h"
#include "simple.h"
#include "programmer.h"
#include "login.h"
#include "currency.h"
#include "showlogs.h"

namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();


private slots:

    void on_pushButton_simple_released();
    void on_pushButton_programmer_released();
    void on_pushButton_login_released();
    void on_pushButton_print_released();
    void on_pushButton_currency_released();

private:
    Ui::Menu *ui;

    Strategy m_strategy;
    Simple m_simple;
    Programmer m_programmer;
    Currency m_currency;
    Login m_login;
    ShowLogs m_showlogs;
};

#endif // MENU_H
