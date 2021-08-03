#include "deviceswitch.h"
#include "ui_deviceswitch.h"

DeviceSwitch::DeviceSwitch(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::DeviceSwitch)
{
    ui->setupUi(this);
}

DeviceSwitch::~DeviceSwitch()
{
    delete ui;
}
