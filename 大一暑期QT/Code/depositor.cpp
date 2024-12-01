#include "depositor.h"



QString depositor::getName() const
{
    return m_name;
}

QString depositor::getPassword() const
{
    return m_password;
}

QString depositor::getAddress() const
{
    return m_address;
}

QString depositor::getSaveTypeS() const
{
    return m_saveTypeS;
}

QString depositor::getCapital() const
{
    return m_capital;
}

QString depositor::getProfitDate() const
{
    return m_profitDate;
}

QString depositor::getIsLostS() const
{
    return m_isLostS;
}

QString depositor::getLostDate() const
{
    return m_lostDate;
}

QString depositor::getStartDate() const
{
    return m_startDate;
}

depositor::depositor()
{

}

depositor::depositor(QString account, QString name, QString password, QString address, QString saveTypes, QString capital,QString startDate):
    m_account(account),m_name(name),m_password(password),m_address(address),m_saveTypeS(saveTypes),m_capital(capital),m_startDate(startDate)
{
//    QDateTime currentDT = QDateTime::currentDateTime();
//    QString currentDTS = currentDT.toString("yyyy MM dd hh:mm:ss");
//    int year = (currentDTS.mid(0,4)).toInt();
    int year = startDate.mid(0,4).toInt();
    if(m_saveTypeS == "1")
        year += 1;
    else if(m_saveTypeS == "3")
        year += 3;
    else year += 5;
    //m_profitDate =  QString::number(year) + currentDTS.mid(4,currentDTS.size() - 4 - 1);
    m_profitDate = QString::number(year) + startDate.mid(4,startDate.size() - 4);
}

depositor::depositor(QString account, QString name, QString password, QString address, QString saveTypes, QString capital, QString profitDate, QString isLostS, QString lostDate):
    m_account(account),m_name(name),m_password(password),m_address(address),m_saveTypeS(saveTypes),m_capital(capital),m_profitDate(profitDate),m_isLostS(isLostS),m_lostDate(lostDate)
{
    int year = m_profitDate.mid(0,4).toInt();
    if(m_saveTypeS == "1")
        year -= 1;
    else if(m_saveTypeS == "3")
        year -= 3;
    else year -= 5;
    m_startDate = QString::number(year) + m_profitDate.mid(4,m_profitDate.size() - 4);
}

//depositor::depositor(QString account, QString name, QString password, QString address, QString saveTypeS, QString capital, QString profitDate, QString isLostS, QString lostDate)
//    :m_account(account),m_name(name),m_password(password),m_address(address),m_saveTypeS(saveTypeS),m_capital(capital),m_profitDate(profitDate),m_isLostS(isLostS)
//    ,m_isLostS(),m_lostDate(lostDate)
//{
//   if(saveType == oneYear)
//       m_saveTypeS = "oneYear";
//   else if(saveType == threeYear)
//       m_saveTypeS = "threeYear";
//   else
//       m_saveTypeS = "fiveYear";
//}

QString depositor::getDepositor() const
{
    return QString(m_account + " " + m_name + " " + m_password + " " + m_address + " " +m_saveTypeS + " " + m_capital + " " + m_profitDate +  " " + m_isLostS.toUtf8() + " " + m_lostDate );
}

QString depositor::getDisplay() const
{
    return QString(m_account + " " + m_name);
}

QString depositor::getAccount() const
{
    return this->m_account;
}


