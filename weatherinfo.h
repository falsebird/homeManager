#ifndef WEATHERINFO_H
#define WEATHERINFO_H

#include <QObject>
#include<QJsonObject>
class WeatherInfo : public QObject
{
    Q_OBJECT
public:
    explicit WeatherInfo(QObject *parent = nullptr);
    WeatherInfo(const QJsonObject& json,QObject *parent = nullptr);
    QString getWindDirction()const;
    QString getType()const;
    QString getWindClass()const;
    QString getLow()const;
    QString getHigh()const;
    QString getDate()const;
    QString toString()const;
signals:

public slots:
private:
    QString m_WindDirction;
    QString m_WindClass;
    QString m_low;
    QString m_hight;
    QString m_type;
    QString m_date;
};

#endif // WEATHERINFO_H
