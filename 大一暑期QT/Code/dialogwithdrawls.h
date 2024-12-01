#ifndef DIALOGWITHDRAWLS_H
#define DIALOGWITHDRAWLS_H

#include <QDialog>
#include <QMessageBox>
#include <withdrawls.h>
#include <savings.h>
#include <QSound>
namespace Ui {
class DialogWithdrawls;
}

class DialogWithdrawls : public QDialog
{
    Q_OBJECT

public:
    explicit DialogWithdrawls(QWidget *parent,QList<Withdrawls>& listWithdrawls,QList<savings>& listSavings,int& indexWithdrawl);
    ~DialogWithdrawls();


private:
    Ui::DialogWithdrawls *ui;
    Withdrawls withdrwalMaker(savings save,QString Date);
    bool isValidDate(QString Date,const savings& target);
    int distPassProfit = -1;
    int distPassStart = -1;
    int yearFirst = 0;
    int yearSecond = 0;
    int yearThird = 0;
    int yearLessFirst = 0;
    int yearLessSecond = 0;
    int yearLessThird = 0;
    int yearLessFourth = 0;
    int yearLessFive = 0;
    bool isLost = false;
};

#endif // DIALOGWITHDRAWLS_H
