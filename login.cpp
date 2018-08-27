#include "login.h"


Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_login_clicked()
{

        Singleton *acc = Singleton::getInstance();

        if(acc->getUsername() == ui->lineEdit_username->text().toStdString() &&
                acc->getPassword() == ui->lineEdit_password->text().toStdString())
        {

            QMessageBox::information(this,"Login","Username and password is correct");
            hide();
            is_loged=1;
            m_print->Clear();

        }
        else
        {
            QMessageBox::warning(this,"Login","Username and password is not correct");
            ui->lineEdit_password->setText("");
            ui->lineEdit_username->setText("");
        }

}

int Login::check_login_status()
{
    return is_loged;
}
