#include "devicecontrolpanle.h"
#include "ui_devicecontrolpanle.h"

DeviceControlPanle::DeviceControlPanle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceControlPanle)
{
    ui->setupUi(this);
//    ui->widget->setTitle(tr("Device Control"));
//    ui->widget->setNoClose();
//    connect(ui->widget,&Titlebar::backoffClicked,this,&DeviceControlPanle::backoffClicked);
//    setLayout(ui->outSideVerticalLayout);
}

DeviceControlPanle::~DeviceControlPanle()
{
    delete ui;
}

void DeviceControlPanle::backoffClicked()
{
    hide();
}
