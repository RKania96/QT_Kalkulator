#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);

}

Menu::~Menu()
{
    delete ui;
}


void Menu::on_pushButton_simple_released()
{

    m_strategy.set_simple(&m_simple);
    m_strategy.show_simple();
}

void Menu::on_pushButton_programmer_released()
{
    m_strategy.set_programmer(&m_programmer);
    m_strategy.show_programmer();
}

void Menu::on_pushButton_login_released()
{
    int i=0;
    switch(i)
    {
    case 0:
            m_strategy.set_login(&m_login);
            m_strategy.show_login();
            i=1;
        break;
    default:
            if(m_strategy.check_status()==0)
            {
                m_strategy.set_login(&m_login);
                m_strategy.show_login();
                i=2;
            }
            else {QMessageBox::warning(this,"Warning","You are loged in.");}
        break;
    }
}

void Menu::on_pushButton_print_released()
{
    m_strategy.set_login(&m_login);            // must set, because must be checked is_loged status before print_released

    if(m_strategy.check_status()==1)     // now we can compare status
    {
        m_strategy.set_showlogs(&m_showlogs);
        m_strategy.show_showlogs();

    }
    else
    {
       QMessageBox::warning(this,"Warning","You are not loged in.");
    }
}


void Menu::on_pushButton_currency_released()
{
    m_strategy.set_currency(&m_currency);
    m_strategy.show_currency();
}
