#include "showlogs.h"
#include "ui_showlogs.h"

ShowLogs::ShowLogs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowLogs)
{
    ui->setupUi(this);
}

ShowLogs::~ShowLogs()
{
    delete ui;
}

void ShowLogs::on_pushButton_basi_released()
{
    Client *client = new LogBasic(new Introduction("basic"));
    ui->textEdit->setText(client->showLog());

}

void ShowLogs::on_pushButton_progr_released()
{
    Client *client = new LogProgrammer(new Introduction("programmer"));
    ui->textEdit->setText(client->showLog());
}

void ShowLogs::on_pushButton_curr_released()
{
    Client *client = new LogCurrency(new Introduction("currency"));
    ui->textEdit->setText(client->showLog());
}
