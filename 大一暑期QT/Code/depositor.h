#ifndef DEPOSITOR_H
#define DEPOSITOR_H
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QDateTime>
#define oneYear 0
#define threeYear 1
#define fiveYear 2

class depositor
{
    friend class savings;
    QString m_account;
    QString m_name;
    QString m_password;
    QString m_address;
    QString m_saveTypeS;
    QString m_capital;
    QString m_profitDate;
    QString m_isLostS = "否";
    QString m_lostDate = "";
    QString m_startDate = "";
public:
    depositor();
    //depositor(QString account,QString name,QString password,QString address,QString saveTypeS,QString capital,QString profitDate,QString isLostS,QString lostDate = "");
    depositor(QString account,QString name,QString password,QString address,QString saveTypes,QString capital,QString startDate);
    depositor(QString account,QString name,QString password,QString address,QString saveTypes,QString capital,QString profitDate,QString isLostS,QString lostDate);
    QString getDepositor() const;
    QString getDisplay() const;
    QString getAccount() const;
    QString getName() const;
    QString getPassword() const;
    QString getAddress() const;
    QString getSaveTypeS() const;
    QString getCapital() const;
    QString getProfitDate() const;
    QString getIsLostS() const;
    QString getLostDate() const;
    QString getStartDate() const;
};

#endif // DEPOSITOR_H
