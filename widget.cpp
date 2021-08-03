#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setLoginDialog();
    setMainWindos();
    setMusicPanle();
    setWeatherPanle();
    setDeviceContPanle();

}

Widget::~Widget()
{
    delete ui;
    delete deviceContPanle;
    delete musicPlayerPanel;
    delete weatherPanle;
    delete loginDialog;
}

void Widget::loadStyleSheet(const QString& sheetName)
{
    QFile file(":/res/" + sheetName.toLower() + ".qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QString::fromLatin1(file.readAll());
    qApp->setStyleSheet(styleSheet);
}

void Widget::setMusicPanle()
{
    musicPlayerPanel = new MusicPlayerPanel(this);
    connect(musicPlayerPanel,&MusicPlayerPanel::backOff,this,&Widget::secondPageBackOff);

}

void Widget::setDeviceContPanle()
{
    deviceContPanle = new  DeviceControlPanle(this);
}

void Widget::setWeatherPanle()
{
    weatherPanle = new WeatherPanle(this);
}

void Widget::setMainWindos()
{


    connect(loginDialog,&LoginDialog::userlogInsuccess,this,&Widget::userLoginSuccess);
    this->setWindowFlags(Qt::FramelessWindowHint);      //设置为无边框窗口
    this->setMinimumSize(45,45);                        //设置最小尺寸
    this->setStyleSheet("background:#a9d3ff");
    setLayout(ui->verticalLayout);
    ui->titleBar->setNoVisBack();
    //loadStyleSheet(tr("main"));
}

void Widget::setLoginDialog()
{
    loginDialog = new LoginDialog(this);
    loginDialog->show();
}

void Widget::userLoginSuccess(const QString& username)
{
    this->show();
    qDebug()<<"user login success"<<endl;
}

void Widget::secondPageBackOff()
{
    this->show();
}


void Widget::on_weatherRequest_Btn_clicked()
{
    weatherPanle->show();
    this->hide();
}

void Widget::on_music_Btn_clicked()
{
    musicPlayerPanel->show();
    this->hide();
}

void Widget::on_control_Btn_clicked()
{
    deviceContPanle->show();
    this->hide();
}
