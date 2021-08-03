#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    loginControlor = LoginControlor::getInstance();
    setLayout(ui->verticalLayout);
    connect(this,&LoginDialog::userLogin,loginControlor,&LoginControlor::loginRequest);
    connect(loginControlor,&LoginControlor::logInScuess,this,&LoginDialog::logInsuccess);
    //setStyle();
}

LoginDialog::~LoginDialog()
{
    delete ui;
    delete loginControlor;
}

void LoginDialog::setStyle()
{
    this->setWindowFlags(Qt::FramelessWindowHint);      //设置为无边框窗口
    this->setMinimumSize(45,45);                        //设置最小尺寸
    this->setStyleSheet("background:#D1EEEE");          //设置背景颜色
}

void LoginDialog::on_logInBtn_clicked()//登录槽函数
{
    QString userName = ui->userNameLiEd->text();
    QString passWord = ui->passWdLiEd->text();
    emit userLogin(userName,passWord);
}

void LoginDialog::logInsuccess(const QString &username)
{
    qDebug()<<"login success"<<endl;
    //开启后边的界面
    emit userlogInsuccess(username);
    //隐藏登录界面
    hide();
}
