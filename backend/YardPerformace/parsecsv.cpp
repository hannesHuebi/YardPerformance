#include "parsecsv.h"
#include <QProcess>
#include "explog.h"
#include <iostream>

ParseCSV::ParseCSV(QObject *parent) :
    QObject(parent)/*,
                    m_volume("")*/
{
    myLog.start_daemon("5010");
    myLog.set_time_range(1);
    setlocale(LC_NUMERIC,"C");
}

void ParseCSV::ReReadValues()
{
    qDebug("RereadValues");

    m_Bsp = myLog.channel(1);
    std::cout << myLog.channel(1) << std::endl;
    qDebug(QString::number(m_Bsp,'f',3).toStdString().c_str());
    Q_EMIT BspStringChanged();

    m_Awa = myLog.channel(2);
    Q_EMIT AwaStringChanged();

    m_PVmg = myLog.channel(66);
    Q_EMIT PVmgStringChanged();

    m_Vmg = 5.5;
    Q_EMIT VmgStringChanged();

    m_AwaOpt = myLog.channel(2);
    Q_EMIT AwaOptStringChanged();

}
