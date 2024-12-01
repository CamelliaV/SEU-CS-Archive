#ifndef CLERK_H
#define CLERK_H


#include <QString>

class clerk
{
    friend class savings;
    friend class clerkInfo;
    QString m_name;
    QString m_id;
public:
    clerk(QString name,QString id);
    QString getClerk() const;
};


#endif // CLERK_H
