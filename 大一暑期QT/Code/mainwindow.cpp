#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QIcon>

//挂失时间限制问题
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMediaPlaylist* musicList = new QMediaPlaylist;
    musicList->addMedia(QUrl("qrc:/res/peach lady.mp3"));//bgm1
    musicList->addMedia(QUrl("qrc:/res/Mozart.mp3"));//过场1

    QMediaPlayer* bgm = new QMediaPlayer;
    //playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    bgm->setPlaylist(musicList);
    //connect(bgm, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    //bgm->setMedia(QUrl::fromLocalFile("D:\\QT\\My_Practice\\Nier_Replicant\\images\\G.mp3"));

    connect(ui->musicButton,&QToolButton::clicked,[=](){
        static int count = 0;
        count++;
        if(count == 1)
            bgm->play();
        else if(count == 2)
        {bgm->pause();count = 0;}
    });

    this->setWindowIcon(QIcon(":/res/ARIMA.png"));
    this->setWindowTitle("系统主页面");
    QLabel* widgetID = new QLabel("储蓄管理系统");
    ui->statusbar->addWidget(widgetID);
    QLabel* widgetPage0 = new QLabel("主页面");
    ui->statusbar->addWidget(widgetPage0);

    clerkStaff->generate();
    indexStaff = QRandomGenerator::global()->bounded(clerkStaff->lastIndex() + 1);
    ui->staffLineName->setText(clerkStaff->getClerkName(indexStaff));
    ui->staffLineID->setText(clerkStaff->getClerkID(indexStaff));
    connect(ui->changeStaff,&QToolButton::clicked,[&](){
        int indexNew = QRandomGenerator::global()->bounded(clerkStaff->lastIndex() + 1);
        ui->staffLineName->setText(clerkStaff->getClerkName(indexNew));
        ui->staffLineID->setText(clerkStaff->getClerkID(indexNew));
        indexStaff = indexNew;
    });
    connect(ui->designateStaff,&QToolButton::clicked,[&](){
        static int count = 0;
        count++;
        if(count == 1)
        {
            ui->staffLineName->setEnabled(true);
            ui->staffLineID->setEnabled(true);

            ui->staffLineID->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}"),this));
        }
        else if(count == 2)
        {
            QString name = ui->staffLineName->text();
            QString id = ui->staffLineID->text();
            int indexNew = clerkStaff->createStaff(name,id);
            if(indexNew != -1)
            {
                ui->staffLineName->setText(clerkStaff->getClerkName(indexNew));
                ui->staffLineID->setText(clerkStaff->getClerkID(indexNew));
                indexStaff = indexNew;
            }
            else
            {
                ui->staffLineName->setText(clerkStaff->getClerkName(indexStaff));
                ui->staffLineID->setText(clerkStaff->getClerkID(indexStaff));
            }
            ui->staffLineName->setEnabled(false);
            ui->staffLineID->setEnabled(false);
        }
        if(count == 2) count = 0;
    });

//    connect(ui->sortCapital,&QToolButton::clicked,[=](){



//    });
//    connect(ui->sort)

    connect(ui->listSavings,&QListWidget::itemDoubleClicked,[=](QListWidgetItem* item){

        item->setBackgroundColor(Qt::red);
        QStringList a = item->text().split(" ");
        QSound::play(":/res/inform.wav");
        QMessageBox message(QMessageBox::NoIcon,"详情","账号：" + a[0] + "\n" + "姓名：" + a[1] + "\n" + "密码：" + a[2] + "\n" + "地址：" + a[3] + "\n" + "储种：" + a[4] + "\n" + "本金：" + a[5] + "\n" + "到息日期：" + a[6] + "\n" + "是否挂失：" + a[7] + "\n" + "挂失日期：" + a[8] + "\n" + "营业员姓名：" + a[9] + "\n" + "营业员工号：" + a[10] + "\n");
        message.setIconPixmap(QPixmap(":/res/Layers.png"));
        QPushButton* ok = new QPushButton("我已知晓");
        QPushButton* del = new QPushButton("删除");
        message.addButton(ok,QMessageBox::NoRole);
        message.addButton(del,QMessageBox::YesRole);
        message.exec();
        if(message.clickedButton() == ok)
        {
            item->setBackgroundColor(Qt::white);
            return;
        }

        else if(message.clickedButton() == del)
        {
            int row = item->listWidget()->currentRow();
            listSavings.removeAt(row);
            ui->listSavings->item(row)->setHidden(true);
        }
        else
        {
            item->setBackgroundColor(Qt::white);
            return;
        }

    });
    connect(ui->listWithdrawls,&QListWidget::itemDoubleClicked,[=](QListWidgetItem* item){
        item->setBackgroundColor(Qt::red);
        QStringList a = item->text().split(" ");
        QSound::play(":/res/inform.wav");
        QMessageBox message(QMessageBox::NoIcon,"详情","账号：" + a[0] + "\n" + "姓名：" + a[1] + "\n" + "密码：" + a[2] + "\n" + "地址：" + a[3] + "\n" + "储种：" + a[4] + "\n" + "本金：" + a[5] + "\n" + "到息日期：" + a[6] + "\n" + "是否挂失：" + a[7] + "\n" + "营业员姓名：" + a[9] + "\n" + "营业员工号：" + a[10] + "\n" + "取款日期：" + a[11] + "\n");
        message.setIconPixmap(QPixmap(":/res/Layers.png"));
        QPushButton* ok = new QPushButton("我已知晓");
        QPushButton* del = new QPushButton("删除");
        message.addButton(ok,QMessageBox::NoRole);
        message.addButton(del,QMessageBox::YesRole);
        message.exec();
        if(message.clickedButton() == ok)
        {
            item->setBackgroundColor(Qt::white);
            return;
        }

        else if(message.clickedButton() == del)
        {
            int row = item->listWidget()->currentRow();
            listWithdrawls.removeAt(row);
            ui->listWithdrawls->item(row)->setHidden(true);
        }
        else
        {
            item->setBackgroundColor(Qt::white);
            return;
        }
    });




    connect(ui->actionAddSaving,&QAction::triggered,[=](){
       bool isEasy = false;
       depositor* tempSaver = nullptr;
       QSound::play(":/res/waterDrop.wav");
       Dialog* dialogCreate = new Dialog(this,indexStaff,clerkStaff,&tempSaver,listSavings,listWithdrawls,isEasy);
       dialogCreate->exec();
       if(!isEasy)
       {
           if(tempSaver)
           {
               savings tempSaving(*tempSaver,clerkStaff->getClerk(indexStaff));
               listSavings << tempSaving;
               //QString display(tempSaver->getDisplay() + " " + clerkStaff->getClerkName(indexStaff) + " " + clerkStaff->getClerkID(indexStaff));
               QListWidgetItem* item = new QListWidgetItem(QIcon(":\\res\\huaji_soviet.jpg"),listSavings.last().getSavings());
               ui->listSavings->addItem(item);
               this->updateFunctions(listSavings,listWithdrawls);
               saveSavings(listSavings,"./Savings.txt");
           }
       }
       else
       {
           ui->listSavings->clear();
           for(int i = 0;i < listSavings.size();i++)
           {
               QListWidgetItem* item = new QListWidgetItem(QIcon(":\\res\\huaji_soviet.jpg"),listSavings[i].getSavings());
               ui->listSavings->addItem(item);
           }
           saveSavings(listSavings,"./Savings.txt");
           this->updateFunctions(listSavings,listWithdrawls);
       }
    });
    connect(ui->actionLostHandler,&QAction::triggered,[=](){
        int indexUpdate = -1;
        QSound::play(":/res/waterDrop.wav");
        DialogLostHandler* dialogLostHandler = new DialogLostHandler(this,listSavings,listWithdrawls,indexUpdate);
        dialogLostHandler->exec();
        if(indexUpdate != -1)
        {
            QListWidgetItem* item = ui->listSavings->takeItem(indexUpdate);//实现更新
            delete item;
            item = new QListWidgetItem(QIcon(":\\res\\huaji_soviet.jpg"),listSavings.at(indexUpdate).getSavings());
            ui->listSavings->insertItem(indexUpdate,item);
            this->updateFunctions(listSavings,listWithdrawls);
        }
    });
    connect(ui->actionWithdrawlHandler,&QAction::triggered,[=](){
        int indexWithdrawl = -1;
        QSound::play(":/res/waterDrop.wav");
        DialogWithdrawls* dialogWithdrawls = new DialogWithdrawls(this,listWithdrawls,listSavings,indexWithdrawl);
        dialogWithdrawls->exec();
        if(indexWithdrawl != -1)
        {
            delete ui->listSavings->takeItem(indexWithdrawl);
            QListWidgetItem* item = new QListWidgetItem(QIcon(":\\res\\huaji_soviet.jpg"),listWithdrawls.last().getWithdrawl());
            ui->listWithdrawls->addItem(item);
            ui->actionPrint->setEnabled(true);
            this->updateFunctions(listSavings,listWithdrawls);
            DialogList* printTarget = new DialogList(this,listWithdrawls,false);
            printTarget->exec();
            if(listWithdrawls.size() == 1)
                saveWithdrawls(listWithdrawls,"./Withdrawls.txt");
        }
    });
    connect(ui->actionPrint,&QAction::triggered,[=](){
        this->updateFunctions(listSavings,listWithdrawls);
        QSound::play(":/res/waterDrop.wav");
        DialogList* dialoglist = new DialogList(this,listWithdrawls,true);
        dialoglist->exec();
    });

    connect(this,&MainWindow::quitSave,ui->AllSave,[=](){
        emit ui->AllSave->triggered();
    });

    connect(ui->AllSave,&QAction::triggered,[=](){
        QSound::play(":/res/waterDrop.wav");
        saveAll(listSavings,listWithdrawls,"默认","默认");
        this->updateFunctions(listSavings,listWithdrawls);

    });
    connect(ui->AllSaveByUser,&QAction::triggered,[=](){
        QSound::play(":/res/waterDrop.wav");
        saveAll(listSavings,listWithdrawls,"用户","用户");
    });
    connect(ui->AllSaveLast,&QAction::triggered,[=](){
        QSound::play(":/res/waterDrop.wav");
       saveAll(listSavings,listWithdrawls,lastSavePathS,lastSavePathW);

    });
    connect(ui->SavingsSave,&QToolButton::clicked,[=](){

        saveSavings(listSavings);
    });
    connect(ui->SavingsRead,&QToolButton::clicked,[=](){
        QSound::play(":/res/waterDrop.wav");
        readSavings();
        this->updateFunctions(listSavings,listWithdrawls);

    });

    connect(ui->WithdrawlRead,&QToolButton::clicked,[=](){
        QSound::play(":/res/waterDrop.wav");
        readWithdrawls();
        this->updateFunctions(listSavings,listWithdrawls);

    });
    connect(ui->actionFind,&QAction::triggered,[=](){
        QSound::play(":/res/waterDrop.wav");
        DialogWithdrawlToTake* dialogToTake = new DialogWithdrawlToTake(this,listSavings);
        connect(dialogToTake,&DialogWithdrawlToTake::LightUp,this,[=](QList<int> indexLightUp){
            static QList<int> indexLightUpLast;
            static bool isFirst = true;
            if(isFirst)
            {
                if(indexLightUp.isEmpty())
                {
                    return;
                }
                else
                    for(int i = 0;i < indexLightUp.size();i++)
                    {
                        ui->listSavings->item(indexLightUp[i])->setBackgroundColor(Qt::red);
                    }
                isFirst = false;
                indexLightUpLast = indexLightUp;
            }
            else
            {
                if(indexLightUp.isEmpty())
                {
                    if(indexLightUpLast.isEmpty())
                        return;
                    else
                    {
                        for(int i = 0;i < indexLightUpLast.size();i++)
                        {
                            ui->listSavings->item(indexLightUpLast[i])->setBackgroundColor(Qt::white);
                        }

                    }
                }
                else
                {
                     if(indexLightUpLast.isEmpty())
                     {
                         for(int i = 0;i < indexLightUp.size();i++)
                         {
                             ui->listSavings->item(indexLightUp[i])->setBackgroundColor(Qt::red);
                         }

                     }
                     else
                     {
                         for(int i = 0;i < indexLightUpLast.size();i++)
                         {
                             ui->listSavings->item(indexLightUpLast[i])->setBackgroundColor(Qt::white);
                         }
                         for(int i = 0;i < indexLightUp.size();i++)
                         {
                             ui->listSavings->item(indexLightUp[i])->setBackgroundColor(Qt::red);
                         }
                     }
                }
            }
            indexLightUpLast = indexLightUp;
        });
        dialogToTake->exec();//show使得后面的内容可以继续执行exec不行
    });
    connect(ui->sortName,&QToolButton::clicked,[=](){
        //ui->listSavings->sortItems() 疑惑这个函数为什么不接受自定义谓词进行比较
         static int sortNameCount = 0;
         QSound::play(":/res/waterDrop.wav");
         sortNameCount++;
         if(sortNameCount == 1)
            sortByName(listSavings);
         else if(sortNameCount == 2)
            {std::reverse(listSavings.begin(),listSavings.end());sortNameCount = 0;}
         ui->listSavings->clear();
         for(int i = 0;i < listSavings.size();i++)
         {
             QListWidgetItem* item = new QListWidgetItem(listSavings[i].getSavings());
             ui->listSavings->addItem(item);
         }

    });
    connect(ui->sortCapital,&QToolButton::clicked,[=](){
        static int sortCapitalCount = 0;
        QSound::play(":/res/waterDrop.wav");
        sortCapitalCount++;
        if(sortCapitalCount == 1)
            sortByCapital(listSavings);
        else if(sortCapitalCount == 2)
        {std::reverse(listSavings.begin(),listSavings.end());sortCapitalCount = 0;}
        ui->listSavings->clear();
        for(int i = 0;i < listSavings.size();i++)
        {
            QListWidgetItem* item = new QListWidgetItem(listSavings[i].getSavings());
            ui->listSavings->addItem(item);
        }
    });
    connect(ui->sortDate,&QToolButton::clicked,[=](){

        static int sortDateCount = 0;
        QSound::play(":/res/waterDrop.wav");
        sortDateCount++;
        if(sortDateCount == 1)
            sortByDate(listSavings);
        else if(sortDateCount == 2)
        {std::reverse(listSavings.begin(),listSavings.end());sortDateCount = 0;}
        ui->listSavings->clear();
        for(int i = 0;i < listSavings.size();i++)
        {
            QListWidgetItem* item = new QListWidgetItem(listSavings[i].getSavings());
            ui->listSavings->addItem(item);
        }
    });
    connect(ui->sortLost,&QToolButton::clicked,[=](){

        static int sortLostCount = 0;
        QSound::play(":/res/waterDrop.wav");
        sortLostCount++;
        if(sortLostCount == 1)
            sortByLost(listSavings);
        else if(sortLostCount == 2)
        {std::reverse(listSavings.begin(),listSavings.end());sortLostCount = 0;}

        ui->listSavings->clear();
        for(int i = 0;i < listSavings.size();i++)
        {
            QListWidgetItem* item = new QListWidgetItem(listSavings[i].getSavings());
            ui->listSavings->addItem(item);
        }
    });
    connect(ui->sortType,&QToolButton::clicked,[=](){

        static int sortTypeCount = 0;
        QSound::play(":/res/waterDrop.wav");
        sortTypeCount++;
        if(sortTypeCount == 1)
            sortByType(listSavings);
        else if(sortTypeCount == 2)
        {std::reverse(listSavings.begin(),listSavings.end());sortTypeCount = 0;}

        ui->listSavings->clear();
        for(int i = 0;i < listSavings.size();i++)
        {
            QListWidgetItem* item = new QListWidgetItem(listSavings[i].getSavings());
            ui->listSavings->addItem(item);
        }
    });

    connect(ui->sortName_2,&QToolButton::clicked,[=](){

         static int sortNameCount2 = 0;
         QSound::play(":/res/waterDrop.wav");
         sortNameCount2++;
         if(sortNameCount2 == 1)
            sortByName(listWithdrawls);
         else if(sortNameCount2 == 2)
            {std::reverse(listWithdrawls.begin(),listWithdrawls.end());sortNameCount2 = 0;}
         ui->listWithdrawls->clear();
         for(int i = 0;i < listWithdrawls.size();i++)
         {
             QListWidgetItem* item = new QListWidgetItem(listWithdrawls[i].getWithdrawl());
             ui->listWithdrawls->addItem(item);
         }

    });
    connect(ui->sortCapital_2,&QToolButton::clicked,[=](){
        static int sortCapitalCount2 = 0;
        QSound::play(":/res/waterDrop.wav");
        sortCapitalCount2++;
        if(sortCapitalCount2 == 1)
            sortByCapital(listWithdrawls);
        else if(sortCapitalCount2 == 2)
        {std::reverse(listWithdrawls.begin(),listWithdrawls.end());sortCapitalCount2 = 0;}
        ui->listWithdrawls->clear();
        for(int i = 0;i < listWithdrawls.size();i++)
        {
            QListWidgetItem* item = new QListWidgetItem(listWithdrawls[i].getWithdrawl());
            ui->listWithdrawls->addItem(item);
        }
    });
    connect(ui->sortDate_2,&QToolButton::clicked,[=](){

        static int sortDateCount2 = 0;
        QSound::play(":/res/waterDrop.wav");
        sortDateCount2++;
        if(sortDateCount2 == 1)
            sortByDate(listWithdrawls);
        else if(sortDateCount2 == 2)
        {std::reverse(listWithdrawls.begin(),listWithdrawls.end());sortDateCount2 = 0;}
        ui->listWithdrawls->clear();
        for(int i = 0;i < listWithdrawls.size();i++)
        {
            QListWidgetItem* item = new QListWidgetItem(listWithdrawls[i].getWithdrawl());
            ui->listWithdrawls->addItem(item);
        }
    });
    connect(ui->sortType_2,&QToolButton::clicked,[=](){

        static int sortTypeCount2 = 0;
        QSound::play(":/res/waterDrop.wav");
        sortTypeCount2++;
        if(sortTypeCount2 == 1)
            sortByType(listWithdrawls);
        else if(sortTypeCount2 == 2)
        {std::reverse(listWithdrawls.begin(),listWithdrawls.end());sortTypeCount2 = 0;}

        ui->listWithdrawls->clear();
        for(int i = 0;i < listWithdrawls.size();i++)
        {
            QListWidgetItem* item = new QListWidgetItem(listWithdrawls[i].getWithdrawl());
            ui->listWithdrawls->addItem(item);
        }
    });
    connect(ui->recordButton,&QToolButton::clicked,[=](){
        QSound::play(":/res/waterDrop.wav");
       listSavingCopy = listSavings;
       ui->backButton->setEnabled(true);
    });
    connect(ui->backButton,&QToolButton::clicked,[=](){
        QSound::play(":/res/waterDrop.wav");
       listSavings = listSavingCopy;
       ui->listSavings->clear();
       for(int i = 0;i < listSavings.size();i++)
           ui->listSavings->addItem(new QListWidgetItem(listSavings[i].getSavings()));
       this->updateFunctions(listSavings,listWithdrawls);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateFunctions(QList<savings> &listSavings, QList<Withdrawls> &listWithdrawls)
{
    if(listSavings.isEmpty() && listWithdrawls.isEmpty())
    {
        ui->actionLostHandler->setEnabled(false);
        ui->actionWithdrawlHandler->setEnabled(false);
        ui->AllSave->setEnabled(false);
        ui->AllSaveByUser->setEnabled(false);
        ui->AllSaveLast->setEnabled(false);
        ui->actionFind->setEnabled(false);
    }
    else if(!listSavings.isEmpty())
    {
        ui->actionLostHandler->setEnabled(true);
        ui->actionWithdrawlHandler->setEnabled(true);
        ui->AllSave->setEnabled(true);
        ui->AllSaveByUser->setEnabled(true);
        ui->AllSaveLast->setEnabled(true);
        if(!listWithdrawls.isEmpty())
        {
            ui->actionPrint->setEnabled(true);
        }
        ui->actionFind->setEnabled(true);
    }
    else if(!listWithdrawls.isEmpty())
    {
        ui->actionLostHandler->setEnabled(false);
        ui->actionWithdrawlHandler->setEnabled(true);
        ui->AllSave->setEnabled(true);
        ui->AllSaveByUser->setEnabled(true);
        ui->AllSaveLast->setEnabled(true);
        ui->actionPrint->setEnabled(true);
    }

}

void MainWindow::saveAll(const QList<savings> & targetSavings, QList<Withdrawls> &targetWithdrawls, QString SavingsPath, QString WithdrawlsPath)
{
    //* 7 16 10 21
    //分开保存可能出现存款取款中同时拥有同一对象，并不打算通过警告拒绝操作解决
    //具体方案如下：
    /*
     * 保存取款时同时保存存款
     * 但因为保存文件理应为用户选取
     * 此操作并不经过用户同意
     * 所以应该提供其他接口操作
     * *7 16 10 47考虑到非法操作情况太多，仅提供保存全部与读取全部功能
     * 如回退(此举需要修改一下功能代码逻辑)
     * 1.一键填入(对象选取)
     * 2.打印单(Enable设置)
     * 3.存取款联动
    */
    if(SavingsPath == "用户" && WithdrawlsPath == "用户")
    {
        saveSavings(targetSavings);

        saveWithdrawls(targetWithdrawls);
    }
    else if(SavingsPath == "默认" && WithdrawlsPath == "默认")
    {
        saveSavings(targetSavings,"./Savings.txt");

        saveWithdrawls(targetWithdrawls,"./Withdrawls.txt");
    }
    else
    {
        saveSavings(targetSavings,SavingsPath);

        saveWithdrawls(targetWithdrawls,WithdrawlsPath);

    }
}

void MainWindow::saveStaff(const clerkInfo*target)
{
    QString pathStaff = QFileDialog::getSaveFileName(this,"保存工作人员名单",QDir::currentPath(),"(*.txt)");
    QFile fileStaff(pathStaff);
    fileStaff.open(QIODevice::WriteOnly);
    for(QString& i : *target->getStaff())
        fileStaff.write(i.toUtf8() + "\n");
}

void MainWindow::saveSavings(const QList<savings> &target)
{
    if(target.empty()) return;
    QString pathSavings = QFileDialog::getSaveFileName(this,"保存存款",QDir::currentPath(),"(*.txt)");
    lastSavePathS = pathSavings;
    QFile fileSavings(pathSavings);
    fileSavings.open(QIODevice::WriteOnly);
    for(int i = 0;i < target.size();++i)
        fileSavings.write(target[i].getSavings().toUtf8() + "\n");
}

void MainWindow::saveSavings(const QList<savings>& target, QString lastPath)
{
    if(target.empty()) return;
    QFile fileSavings(lastPath);
    fileSavings.open(QIODevice::WriteOnly);
    for(int i = 0;i < target.size();++i)
        fileSavings.write(target[i].getSavings().toUtf8() + "\n");
}

void MainWindow::readSavings()
{
    QString pathSavings = QFileDialog::getOpenFileName(this,"打开存款",QDir::currentPath(),"(*.txt)");
    QFile fileSavings(pathSavings);
    fileSavings.open(QIODevice::ReadOnly);
    if(pathSavings != "")listSavings.clear();//temp
    while(!fileSavings.atEnd())
    {
        QByteArray line = fileSavings.readLine();
        QString str(line);
        QString temp[11];
        for(int i = 0;i <11;i++)
            temp[i] = "";
        QStringList tempS = str.split(" ",QString::SkipEmptyParts);

        for(int i = 0;i < tempS.size() - 2;++i)
           { temp[i] = tempS[i];}
        temp[9] = tempS[tempS.size()-2];
        temp[10] = tempS[tempS.size()-1].mid(tempS[tempS.size()-1].size() - 3,2);
        listSavings.append(savings(depositor(temp[0],temp[1],temp[2],temp[3],temp[4],temp[5],temp[6],temp[7],temp[8]),clerk(temp[9],temp[10])));
    }
    ui->listSavings->clear();
    for(int i = 0;i < listSavings.size();i++)
    {
        ui->listSavings->addItem(new QListWidgetItem(listSavings[i].getSavings()));
//        QListWidgetItem* temp = new QListWidgetItem(listSavings[i].getSavings());
//        ui->listSavings->addItem(temp);
//        temp->setBackgroundColor(QColor(Qt::yellow));
    }
}
//*7 16 9 51保存取款
//测试出 空白存档时建立取款操作-非法操作未关闭
void MainWindow::saveWithdrawls(QList<Withdrawls>& target)
{
    if(target.empty()) return;
    QString pathWithdrawls = QFileDialog::getSaveFileName(this,"保存取款",QDir::currentPath(),"(*.txt)");
    lastSavePathW = pathWithdrawls;
    QFile fileWithdrawls(pathWithdrawls);
    fileWithdrawls.open(QIODevice::WriteOnly);
    for(int i = 0;i < target.size();++i)
        fileWithdrawls.write(target[i].getWholeWithdrawl().toUtf8() + "\n");

}

void MainWindow::saveWithdrawls(QList<Withdrawls> & target, QString lastPath)
{
    if(target.empty()) return;
    QFile fileWithdrawls(lastPath);
    fileWithdrawls.open(QIODevice::WriteOnly);
    for(int i = 0;i < target.size();++i)
        fileWithdrawls.write(target[i].getWholeWithdrawl().toUtf8() + "\n");
}

void MainWindow::readWithdrawls()
{
    QString pathWithdrawls = QFileDialog::getOpenFileName(this,"打开取款",QDir::currentPath(),"(*.txt)");
    QFile fileWithdrawls(pathWithdrawls);
    fileWithdrawls.open(QIODevice::ReadOnly);
    if(pathWithdrawls != "")listWithdrawls.clear();//未设置取消按钮情况下误触造成意外清空
    while(!fileWithdrawls.atEnd())
    {
        QByteArray line = fileWithdrawls.readLine();
        QString str(line);
        QString temp[13]; // number of properties
        for(int i = 0;i <13;i++)
            temp[i] = "";
        QStringList tempS = str.split(" ",QString::SkipEmptyParts);
        //单独处理\n字符
        for(int i = 0;i < tempS.size() - 1;++i)
           { temp[i] = tempS[i];}
        temp[12] = tempS[12].mid(0,tempS[12].size() - 1);
        listWithdrawls.append(Withdrawls(temp[0],temp[1],temp[2],temp[3],temp[4],temp[5],temp[6],temp[7],temp[8],temp[9],temp[10],temp[11],temp[12]));
    }
    ui->listWithdrawls->clear();
    for(int i = 0;i < listWithdrawls.size();i++)
    {
        ui->listWithdrawls->addItem(new QListWidgetItem(listWithdrawls[i].getWithdrawl()));
    }
}

void MainWindow::sortByName(QList<savings> & target)
{
    qSort(target.begin(),target.end(),[=](savings left,savings right)
    {
        return left.getName() < right.getName();
    });
}

void MainWindow::sortByName(QList<Withdrawls> &target)
{
    qSort(target.begin(),target.end(),[=](Withdrawls left,Withdrawls right)
    {
        return left.getName() < right.getName();
    });
}

void MainWindow::sortByCapital(QList<savings> &target)
{
    qSort(target.begin(),target.end(),[=](savings left,savings right)
    {
        return left.getCapital().toDouble() < right.getCapital().toDouble();
    });
}

void MainWindow::sortByCapital(QList<Withdrawls> &target)
{
    qSort(target.begin(),target.end(),[=](Withdrawls left,Withdrawls right)
    {
        return left.getCapital() < right.getCapital();
    });
}

void MainWindow::sortByType(QList<savings> &target)
{
    qSort(target.begin(),target.end(),[=](savings left,savings right)
    {
        return left.getType() < right.getType();
    });
}

void MainWindow::sortByType(QList<Withdrawls> &target)
{
    qSort(target.begin(),target.end(),[=](Withdrawls left,Withdrawls right)
    {
        return left.getType() < right.getType();
    });
}

void MainWindow::sortByLost(QList<savings> &target)
{
    qSort(target.begin(),target.end(),[=](savings left,savings right)
    {
        if(left.getLostS() == "是" && right.getLostS() == "否")
            return true;
        else return false;
    });
}

void MainWindow::sortByLost(QList<Withdrawls> &target)
{
    qSort(target.begin(),target.end(),[=](Withdrawls left,Withdrawls right)
    {
        if(left.getLostS() == "是" && right.getLostS() == "否")
            return true;
        else return false;
    });
}

void MainWindow::sortByDate(QList<savings> &target)
{
    qSort(target.begin(),target.end(),[=](savings left,savings right)
    {
        return left.getProfitDate() < right.getProfitDate();
    });
}

void MainWindow::sortByDate(QList<Withdrawls> &target)
{
    qSort(target.begin(),target.end(),[=](Withdrawls left,Withdrawls right)
    {
        return left.getProfitDate() < right.getProfitDate();
    });
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox message(QMessageBox::NoIcon,"询问","是否退出");
    message.setIconPixmap(QPixmap(":/res/Layers.png"));
    QPushButton* quit = new QPushButton("仅退出");
    QPushButton* quitSaveB = new QPushButton("退出并保存");
    QPushButton* cancel = new QPushButton("取消");
    message.addButton(quit,QMessageBox::YesRole);
    message.addButton(quitSaveB,QMessageBox::AcceptRole);
    message.addButton(cancel,QMessageBox::RejectRole);
    QSound::play(":/res/inform.wav");
    message.exec();
    if(message.clickedButton() == quit)
    {
        event->accept();
    }
    else if(message.clickedButton() == quitSaveB)
    {
        emit quitSave();
        event->accept();
    }
    else
    {
        event->ignore();
        message.close();
    }
}

