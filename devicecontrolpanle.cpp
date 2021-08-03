#include "devicecontrolpanle.h"
#include "ui_devicecontrolpanle.h"

DeviceControlPanle::DeviceControlPanle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceControlPanle)
{
    ui->setupUi(this);
}

DeviceControlPanle::~DeviceControlPanle()
{
    delete ui;
}
