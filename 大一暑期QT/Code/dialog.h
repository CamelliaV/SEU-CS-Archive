#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QToolButton>
#include <clerkinfo.h>
#include <depositor.h>
#include <QRegularExpression>
#include <QValidator>
#include <QRegExpValidator>
#include <QRegExp>
#include <QList>
#include <savings.h>
#include <withdrawls.h>
#include <QSound>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent,int indexStaff,clerkInfo* clerkStaff,depositor** saver,QList<savings>&,QList<Withdrawls>&,bool& isEasy);
    ~Dialog();
    QList<depositor> defaultColl;
    static int count;
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
