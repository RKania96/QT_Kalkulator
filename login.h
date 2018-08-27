#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QDebug>
#include "ui_login.h"
#include <QMessageBox>
#include "singleton.h"
#include "print.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

    static Login* _instance;
    Print* m_print;

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    int is_loged=0;
    int check_login_status();

private slots:
    void on_pushButton_login_clicked();



private:
    Ui::Login *ui;
};

#endif // LOGIN_H
