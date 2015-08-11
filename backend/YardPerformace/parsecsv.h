#ifndef PARSECSV_H
#define PARSECSV_H

#include <QObject>
#include "explog.h"

class ParseCSV : public QObject
{
    Q_OBJECT
    Q_PROPERTY( QString BspString READ BspString NOTIFY BspStringChanged)
    Q_PROPERTY( QString AwaString READ AwaString NOTIFY AwaStringChanged)
    Q_PROPERTY( QString PVmgString READ PVmgString NOTIFY PVmgStringChanged)
    Q_PROPERTY( QString VmgString READ VmgString NOTIFY VmgStringChanged)
    Q_PROPERTY( QString AwaOptString READ AwaOptString NOTIFY AwaOptStringChanged)

private:
    double m_Bsp = 5.5;
    double m_Awa = 5.5;
    double m_PVmg= 5.5;
    double m_Vmg= 5.5;
    double m_AwaOpt= 5.5;
    ExpLog myLog;



public:
    explicit ParseCSV(QObject *parent = 0);

//    Q_INVOKABLE
    QString BspString(){return QString::number(m_Bsp);}
    QString AwaString(){return QString::number(m_Awa,'f',0);}
    QString PVmgString(){return QString::number(m_PVmg);}
    QString VmgString(){return QString::number(m_Vmg);}
    QString AwaOptString(){return QString::number(m_AwaOpt);}

Q_SIGNALS:
    void BspStringChanged();
    void AwaStringChanged();
    void PVmgStringChanged();
    void VmgStringChanged();
    void AwaOptStringChanged();

signals:

public slots:
    void ReReadValues();


};

#endif // PARSECSV_H
