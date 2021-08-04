#include "weatherinfo.h"
#include<QDataStream>
WeatherInfo::WeatherInfo(QObject *parent) : QObject(parent)
{

}

WeatherInfo::WeatherInfo(const QJsonObject &json, QObject *parent): QObject(parent)
{

    m_date = json["date"].toString();

    if(json.contains("fengli"))
        m_WindClass = json["fengli"].toString();//需要另外解析
    else
        m_WindClass = json["fl"].toString();//需要另外解析

    if(json.contains("fengxiang"))
        m_WindDirction = json["fengxiang"].toString();
    else
        m_WindDirction = json["fx"].toString();

    m_low = json["low"].toString();
    m_hight = json["high"].toString();
    m_type = json["type"].toString();
}

QString WeatherInfo::getWindDirction() const
{
    return m_WindDirction;
}

QString WeatherInfo::getType() const
{
    return m_type;
}

QString WeatherInfo::getWindClass() const
{
    return m_WindClass;
}

QString WeatherInfo::getLow() const
{
    return m_low;
}

QString WeatherInfo::getHigh() const
{
    return m_hight;
}

QString WeatherInfo::getDate() const
{
    return m_date;
}

QString WeatherInfo::toString() const
{
    //QDataStream temp{};
    QString temp;
    temp.append("天气:");
    temp.append(m_type);
    temp.append("\n");
    temp.append("最低温度:");
    temp.append(m_low);
    temp.append("\n");
    temp.append("最高温度:");
    temp.append(m_hight);
    temp.append("\n");
    temp.append("风力:");
    temp.append(m_WindClass);
    temp.append("\n");
    temp.append("风向:");
    temp.append(m_WindDirction);
    temp.append("\n");
    temp.append("日期:");
    temp.append(m_date);
    temp.append("\n");
//    temp<<QString("天气:")<<m_type<<"\n";
//    temp<<QString("风力:")<<m_WindClass<<"\n";
//    temp<<QString("风向:")<<m_WindDirction<<"\n";
//    temp<<QString("最高温度:")<<m_hight<<"\n";
//    temp<<QString("最低温度:")<<m_low<<"\n";
//    temp<<QString("日期:")<<m_date<<"\n";
//    QString ss;
//    temp>>ss;
    return temp;
}
