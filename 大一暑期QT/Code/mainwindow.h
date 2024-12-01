#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QListWidgetItem>
#include <QList>
#include <QLabel>
#include <QStringList>
#include <QString>
#include <QRandomGenerator>
#include <clerkinfo.h>
#include <savings.h>
#include <QMenu>
#include <QFileDialog>
#include <QFile>
#include <dialog.h>
#include <QList>
#include <dialoglosthandler.h>
#include <dialogwithdrawls.h>
#include <dialoglist.h>
#include <QTableWidget>
#include <dialogwithdrawltotake.h>
#include <qalgorithms.h>
#include <QCloseEvent>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QMediaContent>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QList<savings> listSavings;
//    QStringList* listSavings = new QStringList;
    QList<Withdrawls> listWithdrawls;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void updateFunctions(QList<savings>& listSavings,QList<Withdrawls>& listWithdrawls);
    void saveAll(const QList<savings>&,QList<Withdrawls>&,QString = ":/saveFile/Savingss.txt",QString = ":/saveFile/Withdrawls.txt");
    void saveStaff(const clerkInfo*);
    void saveSavings(const QList<savings>&);
    void saveSavings(const QList<savings>&,QString);
    void readSavings();
    void saveWithdrawls(QList<Withdrawls>&);
    void saveWithdrawls(QList<Withdrawls>&,QString);
    void readWithdrawls();
    static void sortByName(QList<savings>&);
    static void sortByName(QList<Withdrawls>&);
    static void sortByCapital(QList<savings>&);
    static void sortByCapital(QList<Withdrawls>&);
    static void sortByType(QList<savings>&);
    static void sortByType(QList<Withdrawls>&);
    static void sortByLost(QList<savings>&);
    static void sortByLost(QList<Withdrawls>&);
    static void sortByDate(QList<savings>&);
    static void sortByDate(QList<Withdrawls>&);
signals:
    void quitSave();
private:
    clerkInfo* clerkStaff = new clerkInfo;
    int indexStaff;
    void closeEvent(QCloseEvent* event);
    QList<savings> listSavingCopy;
    QList<Withdrawls> listWithdrawlsCopy;
    enum order {PROFITDATE,NAME,TYPE,LOST,CAPITAL};
    Ui::MainWindow *ui;
    QString lastSavePathS = "./Savings.txt";
    QString lastSavePathW = "./Withdrawls.txt";
};
#endif // MAINWINDOW_H
