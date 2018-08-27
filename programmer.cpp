#include "programmer.h"
#include "ui_programmer.h"

Programmer::Programmer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Programmer)
{
    ui->setupUi(this);
    connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(digit_pressed()));
}

Programmer::~Programmer()
{
    delete ui;
}

void Programmer::digit_pressed()
{
    QPushButton * button = (QPushButton*)sender();

    double labelNumber;
    QString newLabel;

    if(ui->lineEdit->text() == "")
    {
        labelNumber = button->text().toDouble();
        newLabel = QString::number(labelNumber,'g',15);

    }
    else
        {
            labelNumber =(ui->lineEdit->text() + button->text()).toDouble();
            newLabel = QString::number(labelNumber,'g',15);
        }

    ui -> lineEdit -> setText(newLabel);
}




void Programmer::on_pushButton_clear_released()
{
    ui->lineEdit->setText("");
    m_print->Write("logProgrammer.txt","\n");
}



void Programmer::on_pushButton_binary_released()
{
    m_print->Write("logProgrammer.txt",ui->lineEdit->text());
    int n = ui->lineEdit->text().toInt();
    int binaryNumber = 0;
    int remainder, i = 1;

        while (n!=0)
        {
            remainder = n%2;
            n /= 2;
            binaryNumber += remainder*i;
            i *= 10;
        }
        QString nbr = QString::number(binaryNumber);
        if(binaryNumber==1) {m_print->Write("logProgrammer.txt","   BIN:     1");}
        m_print->Write("logProgrammer.txt","   BIN:    ");
        ui -> lineEdit ->setText(nbr);
        m_print->Write("logProgrammer.txt",ui->lineEdit->text());

}

void Programmer::on_pushButton_decimal_released()
{
    m_print->Write("logProgrammer.txt",ui->lineEdit->text());
    int n = ui->lineEdit->text().toInt();
    int decimalNumber = 0, i = 0, remainder;

    if(n%10!=0 && n%10!=1)
    {
        ui->lineEdit->setText("->ERROR");
        m_print->Write("logProgrammer.txt",ui->lineEdit->text());
        return;
     }
            while (n != 0)
            {
                remainder = n % 10;
                n /= 10;
                decimalNumber += remainder * pow(2, i);
                 ++i;
            }

                QString nbr = QString::number(decimalNumber);
                if(decimalNumber==1) {m_print->Write("logProgrammer.txt","   DEC:     1");}
                m_print->Write("logProgrammer.txt","   DEC:    ");
                ui -> lineEdit ->setText(nbr);
                m_print->Write("logProgrammer.txt",ui->lineEdit->text());

}
