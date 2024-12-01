#ifndef WITHDRAWLS_H
#define WITHDRAWLS_H

#include <savings.h>
class Withdrawls
{
    savings m_save;
    QString m_withdrawDate;
    QString m_profit;
    QString m_take;
public:
    Withdrawls(savings copy,QString withdrawDate,QString profit,QString take);
    //Withdrawls() = default;
    //* 7 16 10 11 为readWithdrawl专门写的构造 方便传参
    Withdrawls(QString account,QString name,QString password,QString address,QString type,QString capital,QString profitDate,QString isLost,QString clerkName,QString clerkID,QString withdrawlDate,QString profit,QString take);
    QString getWithdrawl() ;
    QString getWholeWithdrawl() ;
    QString getAccount() const;
    QString getStartDate() const;
    QString getName() const;
    QString getType() const;
    QString getCapital() const;
    QString getProfitDate() const;
    QString getLostS() const;
    QString getTake() const;
    QString getProfit() const;
    QString getWithdrawDate() const;
};

#endif // WITHDRAWLS_H
