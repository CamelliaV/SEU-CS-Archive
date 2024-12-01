#include "clerk.h"

clerk::clerk(QString name, QString id):m_name(name),m_id(id)
{

}

QString clerk::getClerk() const
{
    return QString(m_name + " " + m_id);
}
