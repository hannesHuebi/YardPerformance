#include "parsecsv.h"
#include <iostream>
#include <fstream>
#include <string>
#include "csv.h"
#include<algorithm>
#include<iterator>
#include <QProcess>
#include <QFile>

ParseCSV::ParseCSV(QObject *parent) :
    QObject(parent)/*,
                m_volume("")*/
{
}

void ParseCSV::set_values(double inLenght, double inWidth, double inHeight)
{
    m_lenght = inLenght;
    m_width = inWidth;
    m_height = inHeight;

    Q_EMIT volumeChanged();
    qDebug("setFunction");
}

QString ParseCSV::volume()
{
    double localVolume = this->m_lenght * this->m_width * this->m_height;

    qDebug("VolumeFunction");
    //    m_volume = QString::number(localVolume);

    //    std::ifstream myfile ("/home/hannes/Code/YardPerformanceApp/2015Jul19_0.csv");

    //    myfile.open ("/home/hannes/Code/YardPerformanceApp/2015Jul19_0.csv");

    //    std::string line;

    //    getline (myfile,line);

    //    myfile.close();

    //    return QString::fromStdString(line);;


    std::string fileName = ":/data.dat";
//    QFile aFile(":/data.dat");
    QProcess *m_process = new QProcess(this);
    m_process->start("echo {$PWD}");
    m_process->waitForFinished(-1);
    QByteArray bytes = m_process->readAllStandardOutput();
    QString output = QString::fromLocal8Bit(bytes);
    qDebug(output.toStdString().c_str());

    std::ifstream aFile (fileName);
    int lines_count=std::count(std::istreambuf_iterator<char>(aFile),
                               std::istreambuf_iterator<char>(), '\n');

    qDebug(QString::number(lines_count).toStdString().c_str());
    //    io::CSVReader<3, io::trim_chars<','>> in(fileName);
    //    in.read_header(io::ignore_extra_column, "Bsp", "Twa", "Tws");
    //    double VmgPercentSum = 0;
    //    double VmgPercent, Bsp, Twa, Tws;
    //    int counterLines = 0;
    //    int counterValidLines = 0;
    //    int offsetForCounter = lines_count - (m_lenght*60*2);

    //    while(in.read_row(Bsp,Twa,Tws)){
    //        if(counterLines > offsetForCounter)
    //        {
    //            VmgPercent = /*std::cos(Twa/57.3)**/Bsp;
    //            VmgPercentSum += VmgPercent;
    //            counterValidLines++;
    //        }

    //        counterLines ++;
    //    }

    //    double VmgPercentAverage = VmgPercentSum / counterValidLines;

    QString returnString = QString::number(/*VmgPercentAverage*/5);

    returnString.append(" %");

    return returnString;

    //    return localVolume;
}
