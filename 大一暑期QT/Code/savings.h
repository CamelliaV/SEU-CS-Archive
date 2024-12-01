#ifndef SAVINGS_H
#define SAVINGS_H

#include <depositor.h>
#include <clerk.h>
#include <QStringList>
#include <QDate>
class savings
{
    friend class Withdrawls;
    depositor saver;
    clerk staff;
public:

    savings(depositor, clerk);
    QString getSavings() const;
    bool isLost() const;
    //bool isDue(QString testDate) const;
    int countDue(QString Date) const;
    int countUndue(QString Date)const;
    void lostChange(QString lostDate);
    QString getName() const;
    QString getAccount() const;
    QString getPassword() const;
    QString getAddress() const;
    QString getType() const;
    QString getCapital() const;
    QString getStartDate() const;
    QString getProfitDate() const;
    QString getLostS() const;
    QString getLostDate() const;
    QString getClerkName() const;
    QString getClerkID() const;

};

#endif // SAVINGS_H
