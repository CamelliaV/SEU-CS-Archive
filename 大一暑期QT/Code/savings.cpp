#include "savings.h"

#include<QDebug>
savings::savings( depositor  depo,  clerk  cl):saver(depo),staff(cl)
{

}

QString savings::getSavings() const
{
    return QString(saver.getDepositor() + " " + staff.getClerk());
}

bool savings::isLost() const
{
    return (this->saver.m_isLostS == "是");
}

void savings::lostChange(QString lostDate)
{

    saver.m_isLostS = "是";
    saver.m_lostDate = lostDate;
}

QString savings::getName() const
{
    return this->saver.m_name;
}

QString savings::getAccount() const
{
    return this->saver.m_account;
}

QString savings::getPassword() const
{
    return this->saver.m_password;
}

QString savings::getAddress() const
{
    return this->saver.m_address;
}

QString savings::getType() const
{
    return this->saver.m_saveTypeS;
}

QString savings::getCapital() const
{
    return this->saver.m_capital;
}

QString savings::getStartDate() const
{
    return this->saver.m_startDate;
}

QString savings::getProfitDate() const
{
    return this->saver.m_profitDate;
}

QString savings::getLostS() const
{
    return this->saver.m_isLostS;
}

QString savings::getLostDate() const
{
    return this->saver.m_lostDate;
}

QString savings::getClerkName() const
{
    return this->staff.m_name;
}

QString savings::getClerkID() const
{
    return this->staff.m_id;
}
