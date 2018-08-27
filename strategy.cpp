#include "strategy.h"

Strategy::Strategy()
{
    m_print->Clear();
}

void Strategy::set_simple(Simple* s) {m_simple =s;}
void Strategy::set_programmer(Programmer* s) {m_programmer =s;}
void Strategy::set_login(Login* s) {m_login = s;}
void Strategy::set_currency(Currency *s){ m_currency =s;  }
void Strategy::set_showlogs(ShowLogs *s){ m_showlogs =s;  }

void Strategy::show_simple() const
{
    m_simple->show();
    m_print->Write("logBasic.txt","In Simple mode:");
    m_print->Write("logBasic.txt","\n");
}
void Strategy::show_programmer() const
{
    m_programmer->show();
    m_print->Write("logProgrammer.txt","In Programmer mode:");
    m_print->Write("logProgrammer.txt","\n");

}

void Strategy::show_login() const
{
    m_login->show();
}

void Strategy::show_currency() const
{
    m_currency->show();
    m_print->Write("logCurrency.txt","In Currency mode:");
    m_print->Write("logCurrency.txt","\n");
}

void Strategy::show_showlogs() const
{
    m_showlogs->show();
}

int Strategy::check_status()
{
    return m_login->check_login_status();
}
