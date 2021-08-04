#include "devicecontrolpanle.h"
#include "ui_devicecontrolpanle.h"

DeviceControlPanle::DeviceControlPanle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceControlPanle)
{
    ui->setupUi(this);
    ui->titlebar->setTitle(tr("Device Control"));
    ui->titlebar->setNoClose();
    connect(ui->titlebar,&Titlebar::backoffClicked,this,&DeviceControlPanle::backoffClicked);
    setLayout(ui->mainVerLay);
    ui->airCondiSwitch->setLayout(ui->airHorLay);
}

DeviceControlPanle::~DeviceControlPanle()
{
    delete ui;
}

void DeviceControlPanle::backoffClicked()
{
    hide();
}
