#ifndef PARSECSV_H
#define PARSECSV_H

#include <QObject>

class ParseCSV : public QObject
{
    Q_OBJECT
    Q_PROPERTY( QString volume READ volume NOTIFY volumeChanged)

    Q_PROPERTY(int lenght READ lenght WRITE setLenght NOTIFY lenghtChanged)

    int m_lenght;
    double m_width;
    double m_height;

//    QString m_volume;


public:
    explicit ParseCSV(QObject *parent = 0);



    Q_INVOKABLE void set_values(double inLenght, double inWidth, double inHeight);
//    void set_values(QString bla);
    QString volume();
    double lenght(){return m_lenght;}
    void setLenght(int len){m_lenght = len; Q_EMIT volumeChanged();Q_EMIT lenghtChanged();}

Q_SIGNALS:
    void volumeChanged();
    void lenghtChanged();

signals:

public slots:


};

#endif // PARSECSV_H
