#include "logincontrolor.h"

LoginControlor::LoginControlor(QObject *parent) : QObject(parent)
{

    m_userMaps.insert("jiashihai","123123");
}

LoginControlor* LoginControlor::loginControlor = NULL;
pthread_mutex_t LoginControlor::lock= PTHREAD_MUTEX_INITIALIZER;
LoginControlor *LoginControlor::getInstance()
{

    if(loginControlor==NULL){

        pthread_mutex_lock(&lock);

        if(loginControlor == NULL){
           loginControlor = new LoginControlor;
        }

        pthread_mutex_unlock(&lock);
    }

    return loginControlor;
}



LoginControlor::DeleteSpace LoginControlor::ds;  //初始化释放空间的静态类

LoginControlor::DeleteSpace::DeleteSpace() {;}  //初始化构造函数为空

LoginControlor::DeleteSpace::~DeleteSpace() {
    qDebug() << "~DeleteSpace()" << endl;
    if(loginControlor != NULL)
        delete loginControlor;
}


void LoginControlor::loginRequest(const QString &username, const QString &passwd)
{
    auto iter =  m_userMaps.find(username);
    qDebug() << "username:" <<username<< endl;
    qDebug() << "passwd:" <<passwd<< endl;
    if(iter!=m_userMaps.end()){
        if(iter.value()==passwd){
            emit logInScuess(iter.key());
        }
    }
}
