#ifndef DIALOGLOSTHANDLER_H
#define DIALOGLOSTHANDLER_H

#include <QDialog>
//#include <depositor.h>
#include <QList>
//#include <savings.h>
#include <withdrawls.h>
#include <QSound>
namespace Ui {
class DialogLostHandler;
}

class DialogLostHandler : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLostHandler(QWidget *parent, QList<savings>&listSavings,QList<Withdrawls>&listWithdrawls,int& index);
    ~DialogLostHandler();

private:
    Ui::DialogLostHandler *ui;
};

#endif // DIALOGLOSTHANDLER_H
