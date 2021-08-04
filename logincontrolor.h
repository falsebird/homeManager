#ifndef LOGINCONTROLOR_H
#define LOGINCONTROLOR_H

#include <QObject>
#include<QMap>
#include<QDebug>
class LoginControlor : public QObject//使用单例模式，因为登录控制类只能有一个，后期需要连接数据库数据库的连接必然是只有一个的
{
    Q_OBJECT

public:

    static LoginControlor* getInstance();
    ~LoginControlor(){;}

signals:
    void logInScuess(const QString& username);
public slots:
    void loginRequest(const QString& username, const QString& passwd);
private:
    QMap<QString,QString> m_userMaps;//后期可以将从数据库获取的用户信息替换掉这个数据
    static LoginControlor* loginControlor;


    explicit LoginControlor(QObject *parent = nullptr);
    class DeleteSpace{
        public:
           DeleteSpace();
           ~DeleteSpace();
    };

    static DeleteSpace ds;
    static pthread_mutex_t lock ;
};

#endif // LOGINCONTROLOR_H
