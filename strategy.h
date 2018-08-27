#ifndef STRATEGY_H
#define STRATEGY_H

#include <QMessageBox>
#include <iostream>
#include <QDialog>
#include "print.h"
#include "currency.h"
#include "showlogs.h"
#include "simple.h"
#include "programmer.h"
#include "login.h"

class Strategy
{   
private:
   Simple* m_simple;
   Programmer* m_programmer;
   Login* m_login;
   Print* m_print;
   Currency* m_currency;
   ShowLogs* m_showlogs;

public:
    Strategy();
    void set_simple(Simple* s);
    void set_programmer(Programmer* s);
    void set_login(Login* s);
    void set_currency(Currency* s);
    void set_showlogs(ShowLogs* s);

    void show_simple() const;
    void show_programmer() const;
    void show_login() const; 
    void show_currency() const;
    void show_showlogs() const;

    int check_status();

    int is_loged=0;

};

#endif // STRATEGY_H
