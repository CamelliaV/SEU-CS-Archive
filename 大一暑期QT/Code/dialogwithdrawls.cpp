#include "dialogwithdrawls.h"
#include "ui_dialogwithdrawls.h"
#include <QDebug>
#include <QRegExp>
#include <QRegExpValidator>
#include <QStringList>
DialogWithdrawls::DialogWithdrawls(QWidget *parent, QList<Withdrawls>& listWithdrawls, QList<savings>& listSavings, int &indexWithdrawl):
    QDialog(parent),
    ui(new Ui::DialogWithdrawls)
{
    ui->setupUi(this);
    this->setWindowTitle("取款办理");
    this->setWindowIcon(QIcon(":/res/Decision tree.png"));


    ui->lineAccount->setValidator(new QRegExpValidator(QRegExp("^[a-zA-Z0-9]{4,10}")));
    //4-10位，仅允许字母（大小写）数字
    ui->lineName->setValidator(new QRegExpValidator(QRegExp("^[a-zA-Z]{2,15}")));
    ui->linePassword->setValidator(new QRegExpValidator(QRegExp("^[a-zA-Z0-9]{4,10}")));
    ui->lineType->setValidator(new QRegExpValidator(QRegExp("(1|3|5){1}")));

    //取款日期正则(日期晚于起息日期 不超过到期日期 3年)格式为(yyyy-mm-dd)(无闰年平年判断，30/31判断)

    ui->lineDate->setValidator(new QRegExpValidator(QRegExp("((^1[9][0-9][0-9])|(^2[0][0-1][0-9])|(^2[0][2][0-1]))-([0-1][0-9])-([0-2][0-9]|[3][0-1])")));



    connect(ui->getButton,&QToolButton::clicked,[&]()
    {
        savings temp(listSavings[0]);
        if(ui->lineAccount->text() != "")
        {
            for(int i = 0;i < listSavings.size();i++)
            {
                if(listSavings[i].getAccount() == ui->lineAccount->text())
                {
                    temp = listSavings[i];
                    break;
                }
            }
        }
        ui->lineAccount->setText(temp.getAccount());
        ui->lineName->setText(temp.getName());
        ui->lineType->setText(temp.getType());
        ui->lineCapital->setValue(temp.getCapital().toDouble());
        ui->lineDate->setText(temp.getProfitDate());
        ui->linePassword->setText(temp.getPassword());
    });
    connect(ui->okButton,&QToolButton::clicked,[&]( ){
        //& 才可修改 = 会传进来const不可修改
        isLost = false;
        int indexTarget = -1;
        for(int i = listSavings.size() - 1;i >= 0;i--)
        {
            if(listSavings[i].getAccount() == ui->lineAccount->text())
            {
                if(listSavings[i].getName() == ui->lineName->text())
                   {
                    if(listSavings[i].getType() == ui->lineType->text())
                    {

                        if(listSavings[i].getCapital() == ui->lineCapital->text())
                        {

                            if(listSavings[i].isLost())
                                isLost = true;
                            indexTarget = i;
                            break;
                        }
                    }
                    }
             }
        }

        if(indexTarget == -1)
        {
            QSound::play(":/res/inform.wav");
            QMessageBox::critical(this,"错误","不存在目标存款");
        }

       else if(ui->linePassword->text() != listSavings.at(indexTarget).getPassword())
        {
            QSound::play(":/res/inform.wav");
            QMessageBox::information(this,"请重新输入","密码输入不正确!");
        }
        else
        {
           if(isLost)
           {
               QSound::play(":/res/inform.wav");
               QMessageBox message(QMessageBox::NoIcon,"提示","目标存款已经丢失");
               message.setIconPixmap(QPixmap(":/res/Layers.png"));
               message.setButtonText(QMessageBox::Ok,"我已知晓");
               message.exec();
               return;
           }

           //判断日期合法会修改类变量(dist表示距离满息日期时间)
           else if(!isValidDate(ui->lineDate->text(),listSavings[indexTarget]))
           {
               QSound::play(":/res/inform.wav");
               QMessageBox message(QMessageBox::NoIcon,"提示","日期非法 需晚于起始日期且不超过满息日期三年");
               message.setIconPixmap(QPixmap(":/res/Layers.png"));
               message.setButtonText(QMessageBox::Ok,"我已知晓");
               message.exec();
               return;
           }
            else
            {
                Withdrawls* temp = new Withdrawls(withdrwalMaker(listSavings.at(indexTarget),ui->lineDate->text()));
                listWithdrawls << *temp;
                listSavings.removeAt(indexTarget);
                indexWithdrawl = indexTarget;
                this->close();
            }
        }
    });
}


DialogWithdrawls::~DialogWithdrawls()
{

    delete ui;
}

Withdrawls DialogWithdrawls::withdrwalMaker(savings save, QString Date)
{
    double capital = save.getCapital().toDouble();
    double take = capital;
    double profit;
    QStringList tempS = save.getStartDate().split("-");
    QStringList tempC = Date.split("-");
    if(distPassProfit >= 0)
    {
       if(save.getType() == "1")
       {
           take *= (1.98 * 0.01 + 1);
           distPassProfit -= QDate(tempS[0].toInt(),tempS[1].toInt(),tempS[2].toInt()).daysTo(QDate(tempC[0].toInt(),tempC[1].toInt(),tempC[2].toInt()));
       }
       else if(save.getType() == "3")
       {
           for(int i = 0;i < 3;i++)
                take *= (2.25 * 0.01 + 1);
           distPassProfit -= QDate(tempS[0].toInt(),tempS[1].toInt(),tempS[2].toInt()).daysTo(QDate(tempC[0].toInt(),tempC[1].toInt(),tempC[2].toInt()));
       }
       else
       {
           for(int i = 0;i < 5;i++)
                take *= (3.5 * 0.01 + 1);
           distPassProfit -= QDate(tempS[0].toInt(),tempS[1].toInt(),tempS[2].toInt()).daysTo(QDate(tempC[0].toInt(),tempC[1].toInt(),tempC[2].toInt()));
       }
       for(;distPassProfit > 0;distPassProfit--)
           take = take * (0.05 * 0.01 + 1);
       profit = take - capital;
    }
    else
    {
        for(;distPassStart > 0;distPassStart--)
            take = take * (0.05 * 0.01 + 1);
        profit = take - capital;
        profit *= 0.8;
        take = capital + profit;
    }
    return Withdrawls(save,Date,QString::number(profit),QString::number(take));
}

//*2021 7 16 8 06取款日期合法化
//modify required
//*2021 7 16 9 07采用QDate取代原本手动计算，考虑进闰年情况，更适宜使用
bool DialogWithdrawls::isValidDate(QString Date, const savings &target)
{
    QStringList temp = Date.split("-");
    QStringList temp2 = target.getStartDate().split("-");
    QStringList temp3 = target.getProfitDate().split("-");
    int distOver = QDate(temp3[0].toInt(),temp3[1].toInt(),temp3[2].toInt()).daysTo(QDate(temp[0].toInt(),temp[1].toInt(),temp[2].toInt()));
    int distLess = QDate(temp2[0].toInt(),temp2[1].toInt(),temp2[2].toInt()).daysTo(QDate(temp[0].toInt(),temp[1].toInt(),temp[2].toInt()));
    int year1 = temp3[0].toInt();
    int year2 = year1 + 1;
    int year3 = year2 + 1;
    year1 = QDate(year1,10,1).daysInYear();
     year2 = QDate(year2,10,1).daysInYear();
      year3 = QDate(year3,10,1).daysInYear();

    if(distLess >= 0 && distOver <= (year1 + year2 + year3))
    {
        distPassStart = distLess;
        distPassProfit = distOver;
        yearFirst = year1;
        yearSecond = year2;
        yearThird = year3;
        yearLessFirst = temp2[0].toInt();
        yearLessSecond = yearLessFirst + 1;
        yearLessThird = yearLessSecond + 1;
        yearLessFourth = yearLessThird + 1;
        yearLessFirst = yearLessFourth + 1;
        return true;
    }
    else return false;
}

