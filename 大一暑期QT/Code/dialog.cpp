#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
int Dialog::count = 0;
Dialog::Dialog(QWidget *parent,int indexStaff,clerkInfo* clerkStaff,depositor** saver,QList<savings> & listSavings,QList<Withdrawls>& listWithdrawls,bool& isEasy) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
   // this->setWindowIcon();
    this->setWindowTitle("新建存款");
    isEasy = false;
    defaultColl.append(depositor("ZeroTwo","Lagrange","2101","SEU", "1", "2000.00", "1911-01-01"));
    defaultColl.append(depositor("Sakura","Newton","1999","THU","3","3000.00","1931-10-10"));
    defaultColl.append(depositor("TwoA","Cauthy","20f4","PKU","5","5700.00","1912-11-07"));
    defaultColl.append(depositor("Stein","Descartes","1919","NKU","1","998.00","2001-01-09"));
    defaultColl.append(depositor("Chaos","Shannon","sasw","ZJU","3","996.08","2005-05-31"));
    defaultColl.append(depositor("JOJO","Leibniz","2077","NJU","5","6.07","2011-02-02"));
    connect(ui->importButton,&QToolButton::clicked,[=](){
        ui->lineAccount->setText(defaultColl[count].getAccount());
        ui->lineName->setText(defaultColl[count].getName());
        ui->linePassword->setText(defaultColl[count].getPassword());
        ui->lineAddress->setText(defaultColl[count].getAddress());
        ui->lineType->setText(defaultColl[count].getSaveTypeS());
        ui->lineCapital->setValue(defaultColl[count].getCapital().toDouble());
        ui->lineDate->setText(defaultColl[count].getStartDate());
        count++;
        if(count == 6)
            count = 0;
    });
    connect(ui->easyImport,&QToolButton::clicked,[&](){
        bool isAdd = true;
        for(int i = 0;i < 6;i++)
        {
            isAdd = true;
            for(int j = 0;j < listSavings.size();j++)
            {
                if(defaultColl[i].getAccount() == listSavings[j].getAccount())
                {
                    isAdd = false;
                    break;
                }
            }
            for(int k = 0;k < listWithdrawls.size();k++)
            {
                if(defaultColl[i].getAccount() == listWithdrawls[k].getAccount())
                {
                    isAdd =false;
                    break;
                }
            }
            if(isAdd)
                listSavings.append(savings(defaultColl[i],clerk(clerkStaff->getClerkName(indexStaff),clerkStaff->getClerkID(indexStaff))));
        }
        isEasy = true;
        this->close();
    });
    connect(ui->okButton,&QToolButton::clicked,[&](){
        QString readInfo[7];
        for(int i = 0;i <listSavings.size();++i)
        {
            if(ui->lineAccount->text() == listSavings[i].getAccount())
            {
                QSound::play(":/res/inform.wav");
                QMessageBox message(QMessageBox::NoIcon,"提示","已有相同存款！");
                message.setIconPixmap(QPixmap(":/res/Layers.png"));
                message.setButtonText(QMessageBox::Ok,"我已知晓");
                message.exec();
                return;
            }
        }
        for(int i = 0;i < listWithdrawls.size();++i)
        {
            if(ui->lineAccount->text() == listWithdrawls[i].getAccount())
            {
                QSound::play(":/res/inform.wav");
                QMessageBox message(QMessageBox::NoIcon,"提示","已有此取款");
                message.setIconPixmap(QPixmap(":/res/Layers.png"));
                message.setButtonText(QMessageBox::Ok,"我已知晓");
                message.exec();
                return;
            }
        }
        readInfo[0] = ui->lineAccount->text();
        readInfo[1] = ui->lineName->text();
        readInfo[2] = ui->linePassword->text();
        readInfo[3] = ui->lineAddress->text();
        readInfo[4] = ui->lineType->text();
        readInfo[5] = ui->lineCapital->text();
        readInfo[6] = ui->lineDate->text();
        for(int i = 0;i < 7;++i)
            if(readInfo[i].isEmpty())
            {
                QSound::play(":/res/inform.wav");
                QMessageBox message(QMessageBox::NoIcon,"提示","不允许空白输入!");
                message.setIconPixmap(QPixmap(":/res/Layers.png"));
                message.setButtonText(QMessageBox::Ok,"我已知晓");
                message.exec();
                return;
            }
        *saver = new depositor(readInfo[0],readInfo[1],readInfo[2],readInfo[3],readInfo[4],readInfo[5],readInfo[6]);
        this->close();
    });


    ui->lineStaffName->setText(clerkStaff->getClerkName(indexStaff));
    ui->lineStaffID->setText(clerkStaff->getClerkID(indexStaff));

    ui->lineAccount->setValidator(new QRegExpValidator(QRegExp("^[a-zA-Z0-9]{4,10}")));
    //4-10位，仅允许字母（大小写）数字
    ui->lineName->setValidator(new QRegExpValidator(QRegExp("^[a-zA-Z]{2,15}")));
    ui->linePassword->setValidator(new QRegExpValidator(QRegExp("^[a-zA-Z0-9]{4,10}")));
    ui->lineAddress->setValidator(new QRegExpValidator(QRegExp("^[A-Z][a-zA-Z0-9]{0,15}")));
    ui->lineType->setValidator(new QRegExpValidator(QRegExp("(1|3|5){1}")));

    //年份做了一个最简单的正则(年份>=1900 <= 2021)格式为(yyyy-mm-dd)(无闰年平年判断，30/31判断)
    ui->lineDate->setValidator(new QRegExpValidator(QRegExp("((^1[9][0-9][0-9])|(^2[0][0-1][0-9])|(^2[0][2][0-1]))-([0-1][0-9])-([0-2][0-9]|[3][0-1])")));
}

Dialog::~Dialog()
{

    delete ui;
}
