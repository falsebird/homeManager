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
//    musicPlayerPanel->hide();
}

void Widget::setDeviceContPanle()
{
    deviceContPanle = new  DeviceControlPanle(this);
    connect(deviceContPanle,&DeviceControlPanle::backOff,this,&Widget::secondPageBackOff);
//    deviceContPanle->hide();
}

void Widget::setWeatherPanle()
{
    weatherPanle = new WeatherPanle(this);
    connect(weatherPanle,&WeatherPanle::backOff,this,&Widget::secondPageBackOff);
//    weatherPanle->hide();
}

void Widget::setMainWindos()
{


    connect(loginDialog,&LoginDialog::userlogInsuccess,this,&Widget::userLoginSuccess);
    this->setWindowFlags(Qt::FramelessWindowHint);      //设置为无边框窗口
    this->setMinimumSize(45,45);                        //设置最小尺寸

    setLayout(ui->verticalLayout);
    ui->titlebar->setNoVisBack();
    loadStyleSheet(tr("main"));
    ui->titlebar->setTitle(tr("智能家居"));
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
//    this->close();
    this->hide();
    weatherPanle->show();
    //this->hide();
}

void Widget::on_music_Btn_clicked()
{
//    this->close();
    this->hide();
    musicPlayerPanel->show();
//    this->hide();
}

void Widget::on_control_Btn_clicked()
{
//    this->close();
    this->hide();
    deviceContPanle->show();
//    this->hide();
}
