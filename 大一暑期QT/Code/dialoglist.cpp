#include "dialoglist.h"
#include "ui_dialoglist.h"
#include <QDebug>
DialogList::DialogList(QWidget *parent, QList<Withdrawls> &listWithdrawls,bool isFree) :
    QDialog(parent),
    ui(new Ui::DialogList)
{
    ui->setupUi(this);
    this->setWindowTitle("取款单");
    this->setWindowIcon(QIcon(":/res/Variance.png"));
    QStringList temp = listWithdrawls.last().getWholeWithdrawl().split(" ");
    if(isFree == 0)
    {
        ui->printButton->setEnabled(false);
        ui->lineAccount->setEnabled(false);
    }

    //发现C++并没有-1 -2 索引的语法糖 编译还不报错
    ui->lineTake->setText(temp[temp.size()-1]);
    ui->lineProfit->setText(temp[temp.size()-2]);
    ui->lineWithdraw->setText(temp[temp.size()-3]);
    ui->lineAccount->setText(temp[0]);
    ui->lineName->setText(temp[1]);
    ui->lineType->setText(temp[4]);
    ui->lineStart->setText(listWithdrawls.last().getStartDate());
    ui->lineCapital->setValue(temp[5].toDouble());
    connect(ui->printButton,&QToolButton::clicked,[=](){
        for(int i = 0;i <listWithdrawls.size();++i)
        {
            if(listWithdrawls[i].getAccount() == ui->lineAccount->text())
            {
                ui->lineTake->setText(listWithdrawls[i].getTake());
                ui->lineProfit->setText(listWithdrawls[i].getProfit());
                ui->lineWithdraw->setText(listWithdrawls[i].getWithdrawDate());
                ui->lineAccount->setText(listWithdrawls[i].getAccount());
                ui->lineName->setText(listWithdrawls[i].getName());
                ui->lineType->setText(listWithdrawls[i].getType());
                ui->lineStart->setText(listWithdrawls[i].getStartDate());
                ui->lineCapital->setValue(listWithdrawls[i].getCapital().toDouble());


            }
        }
    });
    connect(ui->okButton,&QToolButton::clicked,[=](){

        this->close();
    });
}



DialogList::~DialogList()
{

    delete ui;
}
