#include "dialogwithdrawltotake.h"
#include "ui_dialogwithdrawltotake.h"
#include <QDebug>
DialogWithdrawlToTake::DialogWithdrawlToTake(QWidget *parent, QList<savings> &listSavings) :
    QDialog(parent),
    ui(new Ui::DialogWithdrawlToTake)
{
    ui->setupUi(this);
    //this->setWindowTitle();
    //this->setWindowIcon();

    connect(ui->CheckButton,&QToolButton::clicked,[&](){
       ui->listWidget->clear();
       QList<int> indexLightUp;
       QDate* dueDate;
       QDate* curDate;
       QString temp;
       QString year,month,day;
       year = ui->yearBox->text();
       month = ui->monthBox->text();
       day = ui->dayBox->text();
       int dist = 0;
       int count = 0;
       double sum = 0;
       if(!QDate(year.toInt(),month.toInt(),day.toInt()).isValid())
       {
           QSound::play(":/res/inform.wav");
           QMessageBox message(QMessageBox::NoIcon,"提示","输入日期不合法！");
           message.setIconPixmap(QPixmap(":/res/Layers.png"));
           message.setButtonText(QMessageBox::Ok,"我已知晓");
           message.exec();
           return;
       }
       for(int i = 0;i < listSavings.size();i++)
       {
           if(listSavings[i].isLost()) continue;
           else
           {
               temp = listSavings[i].getProfitDate();
               //qDebug() << temp;
               dueDate = new QDate(temp.mid(0,4).toInt(),temp.mid(5,2).toInt(),temp.mid(8,2).toInt());
               curDate = new QDate(year.toInt(),month.toInt(),day.toInt());
               dist = curDate->daysTo(*dueDate);
//               qDebug() << dist;
//               qDebug() << dueDate->year();
//               qDebug() << dueDate->month();
//               qDebug() << dueDate->day();
//               qDebug() << curDate->year();
//               qDebug() << curDate->month();
//               qDebug() << curDate->day();

               //system("pause");
               if(dist < 0) continue;
               else if(dist >= 0 && dist <= 2) //今明后三天
               {
                   QListWidgetItem* item = new QListWidgetItem(QString(listSavings[i].getSavings() + " 距今天数：" + QString::number(dist)));
                   ui->listWidget->addItem(item);
                   indexLightUp.append(i);
                   count++;
                   sum += countProfit(listSavings[i]);
               }
               delete dueDate;
               delete curDate;
           }
       }
       emit LightUp(indexLightUp);
       QListWidgetItem* item = new QListWidgetItem(QString("总计到期储金数：") + QString::number(count) + " " + QString("应储备金：") + QString::number(sum));
       ui->listWidget->addItem(item);
    });


}

DialogWithdrawlToTake::~DialogWithdrawlToTake()
{
    delete ui;
}

double DialogWithdrawlToTake::countProfit(const savings &target)
{
    QString temp = target.getType();
    double take = target.getCapital().toDouble();
    if(temp == "1")
        take *= (1.98 * 0.01 + 1);
    else if(temp == "3")
        for(int i = 0;i < 3;i++)
             take *= (2.25 * 0.01 + 1);
    else
        for(int i = 0;i < 5;i++)
             take *= (3.5 * 0.01 + 1);
    return take;
}
