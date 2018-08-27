#include "currency.h"
#include "ui_currency.h"
#include "QDebug"

Currency::Currency(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Currency)
{
    ui->setupUi(this);

}


Currency::~Currency()
{
    delete ui;
}


void Currency::on_pushButton_start_released()
{

    Downloader d;
    d.getHtml("https://businessinsider.com.pl/finanse/kursy-walut");
    d.readTxt();

    ui->label_actual_EUR->setText(d.EUR);
    ui->label_actual_GBP->setText(d.GBP);
    ui->label_actual_USD->setText(d.USD);

}



void Currency::on_pushButton_GBP_released()
{

    QString PLN = ui->label_actual_GBP->text();
    QString GBP = ui->lineEdit_push_GBP->text();

    double scoreGBP = PLN.toDouble() * GBP.toDouble();
    QString newLineGBP = QString::number(scoreGBP,'g',15);
    ui->lineEdit_score_GBP->setText(newLineGBP);
    m_print->Write("logCurrency.txt","GBP: "+GBP);
    m_print->Write("logCurrency.txt","    ->  PLN: ");
    m_print->Write("logCurrency.txt",newLineGBP);
    m_print->Write("logCurrency.txt","\n");
}

void Currency::on_pushButton_EUR_released()
{
    QString PLN = ui->label_actual_EUR->text();
    QString EUR = ui->lineEdit_push_EUR->text();

    double scoreEUR = PLN.toDouble() * EUR.toDouble();
    QString newLineEUR = QString::number(scoreEUR,'g',15);
    ui->lineEdit_score_EUR->setText(newLineEUR);
    m_print->Write("logCurrency.txt","EUR: "+EUR);
    m_print->Write("logCurrency.txt","    ->  PLN: ");
    m_print->Write("logCurrency.txt",newLineEUR);
    m_print->Write("logCurrency.txt","\n");
}

void Currency::on_pushButton_USD_released()
{
    QString PLN = ui->label_actual_USD->text();
    QString USD = ui->lineEdit_push_USD->text();

    double scoreUSD = PLN.toDouble() * USD.toDouble();
    QString newLineUSD = QString::number(scoreUSD,'g',15);
    ui->lineEdit_score_USD->setText(newLineUSD);
    m_print->Write("logCurrency.txt","USD: "+USD);
    m_print->Write("logCurrency.txt","    ->  PLN: ");
    m_print->Write("logCurrency.txt",newLineUSD);
    m_print->Write("logCurrency.txt","\n");
}
