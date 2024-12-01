#ifndef DIALOGWITHDRAWLTOTAKE_H
#define DIALOGWITHDRAWLTOTAKE_H

#include <QDialog>
#include <QList>
#include <savings.h>
#include <QDate>
#include <QSound>
namespace Ui {
class DialogWithdrawlToTake;
}

class DialogWithdrawlToTake : public QDialog
{
    Q_OBJECT

public:
    explicit DialogWithdrawlToTake(QWidget *parent,QList<savings>& listSavings);
    ~DialogWithdrawlToTake();
signals:
    void LightUp(QList<int> indexLightUp);
private:
    Ui::DialogWithdrawlToTake *ui;
    double countProfit(const savings& target);
};

#endif // DIALOGWITHDRAWLTOTAKE_H
