#include "dialoglosthandler.h"
#include "ui_dialoglosthandler.h"
#include <QRegularExpression>
#include <QDebug>
#include <QRegExpValidator>
DialogLostHandler::DialogLostHandler(QWidget *parent, QList<savings>& listSavings, QList<Withdrawls> &listWithdrawls, int& index) :
    QDialog(parent),
    ui(new Ui::DialogLostHandler)
{
    ui->setupUi(this);
    this->setWindowTitle("挂失处理");
    this->setWindowIcon(QIcon(":/res/KProperty.png"));


    ui->lineAccount->setValidator(new QRegExpValidator(QRegExp("^[a-zA-Z0-9]{4,10}")));
    //4-10位，仅允许字母（大小写）数字
    ui->lineName->setValidator(new QRegExpValidator(QRegExp("^[a-zA-Z]{2,15}")));
    ui->linePassword->setValidator(new QRegExpValidator(QRegExp("^[a-zA-Z0-9]{4,10}")));
    ui->lineAddress->setValidator(new QRegExpValidator(QRegExp("^[A-Z][a-zA-Z0-9]{0,15}")));
    ui->lineType->setValidator(new QRegExpValidator(QRegExp("(1|3|5){1}")));

    connect(ui->easyButton,&QToolButton::clicked,[=](){
        savings temp(listSavings[0]);
        if(ui->lineAccount->text()!="")
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
        ui->lineAddress->setText(temp.getAddress());
        ui->lineCapital->setValue(temp.getCapital().toDouble());
        ui->lineLost->setText(temp.getStartDate());
        ui->lineName->setText(temp.getName());
        ui->linePassword->setText(temp.getPassword());
        ui->lineType->setText(temp.getType());
    });
    connect(ui->okButton,&QToolButton::clicked,[&](){
        bool isWithdraw = false;
        bool isExist = false;
        bool isSave = false;
        QString readInfo[6];
        readInfo[0] = ui->lineAccount->text();
        readInfo[1] = ui->lineName->text();
        readInfo[2] = ui->linePassword->text();
        readInfo[3] = ui->lineAddress->text();
        readInfo[4] = ui->lineType->text();
        readInfo[5] = ui->lineCapital->text();
        if(listSavings.size() == 0)
        {
            QSound::play(":/res/inform.wav");
            QMessageBox message(QMessageBox::NoIcon,"提示","不存在已输入的存款信息");
            message.setIconPixmap(QPixmap(":/res/Layers.png"));
            message.setButtonText(QMessageBox::Ok,"我已知晓");
            message.exec();
            return;
        }
        for(int i = 0;i < listSavings.size();++i)
        {
            QStringList temp = listSavings.at(i).getSavings().split(" ");
            //采用QRegexExpression("\\S+")不知为何下方调试全是空
            //qDebug() << temp[0] <<" " <<  temp[1] << " " << temp[2] << " " << temp[3] << " " << temp[4] << " " << temp[5] << " ";
            for(int j = 0;j < 6;j++)
            {

                if(temp.at(j) == readInfo[j])
                {
                    if(j == 5)
                    {
                        isExist = true;
                        isSave = true;
                        listSavings[i].lostChange(ui->lineLost->text());
                        index = i;
                    }
                    else continue;
                }
                else break;
            }
        }
        if(!isSave)
        {
            for(int i = 0;i < listWithdrawls.size();++i)
            {
                QStringList temp = listWithdrawls[i].getWithdrawl().split(" ");
                for(int j = 0;j < 6;++j)
                {
                    if(temp.at(j) == readInfo[j])
                    {
                        if(j== 5)
                        {
                            isExist = true;
                            isWithdraw = true;
                        }
                    }
                }
            }
        }
        if(!isExist)
        {
            QSound::play(":/res/inform.wav");
            QMessageBox message(QMessageBox::NoIcon,"提示","不存在此笔存款");
            message.setIconPixmap(QPixmap(":/res/Layers.png"));
            message.setButtonText(QMessageBox::Ok,"我已知晓");
            message.exec();
            return;
        }
        if(isWithdraw)
        {
            QSound::play(":/res/inform.wav");
            QMessageBox message(QMessageBox::NoIcon,"提示","此存款已被领取");
            message.setIconPixmap(QPixmap(":/res/Layers.png"));
            message.setButtonText(QMessageBox::Ok,"我已知晓");
            message.exec();
            return;
        }
        this->close();
    });
}

DialogLostHandler::~DialogLostHandler()
{

    delete ui;
}
