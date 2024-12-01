#ifndef CLERKINFO_H
#define CLERKINFO_H

#include <QString>
#include <QStringList>
#include <clerk.h>
#include <QStringAlgorithms>
#include <QRegularExpression>
#include <QMessageBox>
class clerkInfo
{
    QStringList* staff;
public:
    clerkInfo();
    void addClerk(const clerk&);
    void deleteClerk(const clerk&);
    QString getClerkName(int index) const;
    QString getClerkID(int index) const;
    clerk getClerk(int index) const;
    QStringList* getStaff() const;
    int createStaff(QString name,QString id);
    int lastIndex() const;
    void generate(); //仅用于程序调试，生成默认职员
};

#endif // CLERKINFO_H
