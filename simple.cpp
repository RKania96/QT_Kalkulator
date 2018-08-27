#include "simple.h"


double firstNum;
bool userIsTypingSecondNumber = false;

Simple::Simple(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Simple)
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

    connect(ui->pushButton_plusMinus,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
    connect(ui->pushButton_percent,SIGNAL(released()),this,SLOT(unary_operation_pressed()));

    connect(ui->pushButton_add,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_substract,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_multiply,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_divide,SIGNAL(released()),this,SLOT(binary_operation_pressed()));

    ui->pushButton_add->setCheckable(true);
    ui->pushButton_substract->setCheckable(true);
    ui->pushButton_divide->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
}

Simple::~Simple()
{
    delete ui;
}

void Simple::digit_pressed()
{
    QPushButton * button = (QPushButton*)sender();

    double labelNumber;
    QString newLabel;

    if((ui->pushButton_add->isChecked() || ui->pushButton_substract->isChecked() ||
            ui->pushButton_multiply->isChecked() || ui->pushButton_divide->isChecked()) && (!userIsTypingSecondNumber))
    {
        labelNumber = button->text().toDouble();
        userIsTypingSecondNumber=true;
        newLabel = QString::number(labelNumber,'g',15);
    }
    else
    {   if(ui->lineEdit->text().contains('.') && button->text()=="0")
        {
            newLabel = ui->lineEdit->text() + button->text();

        }
        else
        {
            labelNumber =(ui->lineEdit->text() + button->text()).toDouble();
            newLabel = QString::number(labelNumber,'g',15);
        }
    }


    ui -> lineEdit -> setText(newLabel);
}

void Simple::on_pushButton_decimal_released()
{
    ui->lineEdit->setText(ui->lineEdit->text() + ".");
}

void Simple::unary_operation_pressed()
{
    QPushButton * button = (QPushButton*)sender();
    double labelNumber;
    QString newLabel;

    if(button->text() == "+/-")
    {
        labelNumber = ui->lineEdit->text().toDouble();
        labelNumber = labelNumber * -1;
        newLabel = QString::number(labelNumber,'g',15);
        ui->lineEdit->setText(newLabel);
    }
    if(button->text() == "%")
    {
        labelNumber = ui->lineEdit->text().toDouble();
        labelNumber = labelNumber * 0.01;
        newLabel = QString::number(labelNumber,'g',15);
        ui->lineEdit->setText(newLabel);
    }
}

void Simple::on_pushButton_clear_released()
{
    ui->pushButton_add->setChecked(false);
    ui->pushButton_substract->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_divide->setChecked(false);

    userIsTypingSecondNumber = false;

    ui->lineEdit->setText("0");
    m_print->Write("logBasic.txt","\n");
}

void Simple::on_pushButton_equals_released()
{
    double labelNumber, secondNum;
    QString newLabel,secondNumStr;
    secondNumStr = ui->lineEdit->text();
    secondNum = ui->lineEdit->text().toDouble();

    if(ui->pushButton_add ->isChecked())
    {
        labelNumber = firstNum + secondNum;
        QString newFirstNum = QString::number(firstNum,'g',15);
        m_print->Write("logBasic.txt",newFirstNum+"+");
        m_print->Write("logBasic.txt",secondNumStr);
        newLabel = QString::number(labelNumber,'g',15);
        ui->lineEdit->setText(newLabel);
        m_print->Write("logBasic.txt","="+newLabel);
        ui->pushButton_add->setChecked(false);
    }
    else if(ui->pushButton_substract ->isChecked())
    {
        labelNumber = firstNum - secondNum;
        QString newFirstNum = QString::number(firstNum,'g',15);
        m_print->Write("logBasic.txt",newFirstNum+"-");
        m_print->Write("logBasic.txt",secondNumStr);
        newLabel = QString::number(labelNumber,'g',15);
        ui->lineEdit->setText(newLabel);
        m_print->Write("logBasic.txt","="+newLabel);
        ui->pushButton_substract->setChecked(false);
    }
    else if(ui->pushButton_multiply ->isChecked())
    {
        labelNumber = firstNum * secondNum;
        QString newFirstNum = QString::number(firstNum,'g',15);
        m_print->Write("logBasic.txt",newFirstNum+"*");
        m_print->Write("logBasic.txt",secondNumStr);
        newLabel = QString::number(labelNumber,'g',15);
        ui->lineEdit->setText(newLabel);
        m_print->Write("logBasic.txt","="+newLabel);
        ui->pushButton_multiply->setChecked(false);
    }
    else if(ui->pushButton_divide ->isChecked())
    {
        labelNumber = firstNum / secondNum;
        QString newFirstNum = QString::number(firstNum,'g',15);
        m_print->Write("logBasic.txt",newFirstNum+"/");
        m_print->Write("logBasic.txt",secondNumStr);
        newLabel = QString::number(labelNumber,'g',15);
        ui->lineEdit->setText(newLabel);
        m_print->Write("logBasic.txt","="+newLabel);
        ui->pushButton_divide->setChecked(false);
    }
    userIsTypingSecondNumber = false;
}

void Simple::binary_operation_pressed()
{
    QPushButton * button = (QPushButton*)sender();

    firstNum = ui->lineEdit->text().toDouble();

    button -> setChecked(true);


}
