#include "withdrawls.h"

Withdrawls::Withdrawls(savings copy, QString withdrawDate, QString profit, QString take):
  m_save(copy),m_withdrawDate(withdrawDate),m_profit(profit),m_take(take)
{

}

Withdrawls::Withdrawls(QString account, QString name, QString password, QString address, QString type, QString capital, QString profitDate, QString isLost, QString clerkName, QString clerkID, QString withdrawlDate, QString profit, QString take):
    m_save(depositor(account,name,password,address,type,capital,profitDate,isLost,""),clerk(clerkName,clerkID)),m_withdrawDate(withdrawlDate),m_profit(profit),m_take(take)
{

}

QString Withdrawls::getWithdrawl()
{
    return QString(m_save.getSavings() + " " + m_withdrawDate);
}


QString Withdrawls::getWholeWithdrawl()
{
    return QString(m_save.getSavings() + " " + m_withdrawDate + " " + m_profit + " " + m_take);
}

QString Withdrawls::getAccount() const
{
    return this->m_save.getAccount();
}


QString Withdrawls::getStartDate() const
{
    return this->m_save.getStartDate();
}

QString Withdrawls::getName() const
{
    return this->m_save.getName();
}

QString Withdrawls::getType() const
{
    return this->m_save.getType();
}

QString Withdrawls::getCapital() const
{
    return this->m_save.getCapital();
}

QString Withdrawls::getProfitDate() const
{
    return this->m_save.getProfitDate();
}

QString Withdrawls::getLostS() const
{
    return this->m_save.getLostS();
}

QString Withdrawls::getTake() const
{
    return this->m_take;
}

QString Withdrawls::getProfit() const
{
    return this->m_profit;
}

QString Withdrawls::getWithdrawDate() const
{
    return this->m_withdrawDate;
}


