#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    loginDialog = new LoginDialog(this);
    loginDialog->show();
    connect(loginDialog,&LoginDialog::userlogInsuccess,this,&Widget::userLoginSuccess);

    this->setWindowFlags(Qt::FramelessWindowHint);      //设置为无边框窗口
    this->setMinimumSize(45,45);                        //设置最小尺寸
    this->setStyleSheet("background:#a9d3ff");
    setLayout(ui->verticalLayout);
    loadStyleSheet(tr("main"));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::loadStyleSheet(const QString& sheetName)
{
    QFile file(":/res/" + sheetName.toLower() + ".qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QString::fromLatin1(file.readAll());
    qApp->setStyleSheet(styleSheet);
}

void Widget::userLoginSuccess(const QString& username)
{
    this->show();
    qDebug()<<"user login success"<<endl;
}

