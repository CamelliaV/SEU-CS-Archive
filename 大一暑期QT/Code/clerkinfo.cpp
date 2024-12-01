#include "clerkinfo.h"

clerkInfo::clerkInfo()
{
    staff = new QStringList;
}

void clerkInfo::addClerk(const clerk &target)
{
    *staff << QString(target.m_name + " " + target.m_id);
}

void clerkInfo::deleteClerk(const clerk &target)
{
    staff->removeOne(target.m_name + " " + target.m_id);
}

QString clerkInfo::getClerkName(int index) const
{
    QRegularExpression re("\\S+");
    QRegularExpressionMatch matchs=re.match(staff->at(index));
    QString matched = matchs.captured(0);
    return matched;
}

QString clerkInfo::getClerkID(int index) const
{
    QRegularExpression re("\\d+");
    QRegularExpressionMatch matchs=re.match(staff->at(index));
    QString matched = matchs.captured(0);
    return matched;
}

clerk clerkInfo::getClerk(int index) const
{
    return clerk(getClerkName(index),getClerkID(index));
}

QStringList* clerkInfo::getStaff() const
{
    return this->staff;
}

int clerkInfo::createStaff(QString name, QString id)
{
    QString target(name + " " + id);
    if(this->staff->contains(target))
    {
        QMessageBox message(QMessageBox::NoIcon,"提示","已包含此营业员");
        message.setIconPixmap(QPixmap(":/res/Layers.png"));
        message.setButtonText(QMessageBox::Ok,"我已知晓");
        message.exec();
        return -1;
    }
    else
    {
        *(this->staff) << target;
        return this->lastIndex();
    }

}

int clerkInfo::lastIndex() const
{
    return this->staff->size() - 1;
}


void clerkInfo::generate()
{
    *staff << QString(QString("Abel") + " " + "00");
    *staff << QString(QString("Bell") + " " + "01");
    *staff << QString(QString("Cauthy") + " " + "02");
    *staff << QString(QString("D'lembert") + " " + "03");
    *staff << QString(QString("Emily") + " " + "04");
    *staff << QString(QString("Francils") + " " + "05");
    *staff << QString(QString("Gus") + " " + "06");
    *staff << QString(QString("Herlen") + " " + "07");
    *staff << QString(QString("Iva") + " " + "08");
    *staff << QString(QString("Jaccobi") + " " + "09");
}

