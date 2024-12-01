#ifndef DIALOGLIST_H
#define DIALOGLIST_H

#include <QDialog>
#include <withdrawls.h>
#include <QStringList>
namespace Ui {
class DialogList;
}

class DialogList : public QDialog
{
    Q_OBJECT

public:
    explicit DialogList(QWidget *parent,QList<Withdrawls>& listWithdrawls,bool isFree = 0);
    ~DialogList();

private:
    Ui::DialogList *ui;
};

#endif // DIALOGLIST_H
