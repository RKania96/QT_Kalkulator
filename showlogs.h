#ifndef SHOWLOGS_H
#define SHOWLOGS_H

#include <QDialog>
#include "client.h"
#include "introduction.h"
#include "decorator.h"
#include "logbasic.h"
#include "logprogrammer.h"
#include "logcurrency.h"
namespace Ui {
class ShowLogs;
}

class ShowLogs : public QDialog
{
    Q_OBJECT

public:
    explicit ShowLogs(QWidget *parent = 0);
    ~ShowLogs();

private slots:
    void on_pushButton_basi_released();
    void on_pushButton_progr_released();
    void on_pushButton_curr_released();


private:
    Ui::ShowLogs *ui;
};

#endif // SHOWLOGS_H
