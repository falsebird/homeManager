#ifndef MYNETWORK_H
#define MYNETWORK_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QTextCodec>
//该类负责发送和接受网络请求
class MyNetwork : public QObject
{
    Q_OBJECT
public:
    explicit MyNetwork(QObject *parent = nullptr);
    ~MyNetwork();
    void data_utf8_encode(QString &data);

signals:
    void weathreInfo(const QString& info);
public slots:
    void requestNetwork(const QString& city);
    void parseReplyMsg();
private:
    QNetworkAccessManager *manager; //定义网络操作对象类
    QNetworkReply *reply;
    QString city;
};

#endif // MYNETWORK_H
