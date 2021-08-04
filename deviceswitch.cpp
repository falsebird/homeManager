#include "deviceswitch.h"
#include "ui_deviceswitch.h"

DeviceSwitch::DeviceSwitch(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::DeviceSwitch)
{
    ui->setupUi(this);
    switchFlag = false;//因为没有实际设备所以默认初始化都为false
    curretnVolum = 0;
    connect(ui->deviceSwitchBtn,&QPushButton::clicked,this,&DeviceSwitch::deviceSwitch);
    connect(ui->vloumSlider,&QSlider::valueChanged,this,&DeviceSwitch::setVoulum);
//    setFixedSize(200,100);
}

DeviceSwitch::~DeviceSwitch()
{
    delete ui;
}

void DeviceSwitch::setVoulum(int v)
{
    curretnVolum = ui->vloumSlider->value();
    //将volum发送给device
    emit currentVoulum(curretnVolum);
}

void DeviceSwitch::deviceSwitch()
{
    //查询device的当前状态
    //发送当前状态
    switchFlag = !switchFlag;//逆转状态
    //将当前状态转发送出去
    emit currentFlag(switchFlag);
}

void DeviceSwitch::setDeviceLable(const QString &lable)
{
    ui->deviceLabel->setText(lable);
    emit currentLabel(lable);
}
