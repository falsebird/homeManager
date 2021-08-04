#include "devicecontrolpanle.h"
#include "ui_devicecontrolpanle.h"

DeviceControlPanle::DeviceControlPanle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceControlPanle)
{
    ui->setupUi(this);

    ui->titlebar->setTitle(tr("设备控制"));
    ui->titlebar->setNoClose();
    connect(ui->titlebar,&Titlebar::backoffClicked,this,&DeviceControlPanle::backoffClicked);

    setLayout(ui->mainVerLay);
    ui->airCondiSwitch->setLayout(ui->airHorLay);
    ui->soundSwitch->setLayout(ui->soundHorLay);
    ui->bedLightSwitch->setLayout(ui->bedLigHorLay);
    ui->mainLightSwitch->setLayout(ui->lightHorLay);

    ui->bedLigSlider->setRange(0,100);
    ui->lightSlider->setRange(0,100);
    ui->soundSlider->setRange(0,100);

    connect(ui->lightSlider,&QSlider::valueChanged,this,&DeviceControlPanle::lightSliderChange);
    connect(ui->bedLigSlider,&QSlider::valueChanged,this,&DeviceControlPanle::bedLightSliderChange);
    connect(ui->soundSlider,&QSlider::valueChanged,this,&DeviceControlPanle::soundSliderChange);

    ui->temprShowLiEd->setText(QString::number(m_airCondiTempre)+" C");

    ui->bedLigSwitchBtn->setDefault(m_bedLightFlag);
    ui->bedLigStateBtn->setDefault(m_bedLightFlag);

    ui->lightSwitchBtn->setDefault(m_lightFlag);
    ui->lightStateBtn->setDefault(m_lightFlag);

    ui->soundStateBtn->setDefault(m_soundFlag);
    ui->soundSwitchBtn->setDefault(m_soundFlag);

    ui->airCondiSwitchBtn->setDefault(m_airCondiFlag);
    ui->airCondiStateBtn->setDefault(m_airCondiFlag);

//    setLightSwitchBack();
//    setAirConSwitchBack();
//    setBedLightSwitchBack();
//    setSoundSwitchBack();
}


DeviceControlPanle::~DeviceControlPanle()
{
    delete ui;
}

void DeviceControlPanle::backoffClicked()
{
    this->hide();
    emit backOff();
}

void DeviceControlPanle::lightSliderChange(int v)
{
    ui->outInfoPlaTeEd->appendPlainText("当前灯光亮度为："+QString::number(v));
}

void DeviceControlPanle::bedLightSliderChange(int v)
{
    ui->outInfoPlaTeEd->appendPlainText("当前床头灯光亮度为："+QString::number(v));
}

void DeviceControlPanle::soundSliderChange(int v)
{
    ui->outInfoPlaTeEd->appendPlainText("当前音响音量为："+QString::number(v));
}


void DeviceControlPanle::on_lightSwitchBtn_clicked()
{
    if(m_lightFlag){
        ui->outInfoPlaTeEd->appendPlainText(tr("主灯关闭"));
        m_lightFlag= false;
    }else{
        ui->outInfoPlaTeEd->appendPlainText(tr("主灯打开"));
        m_lightFlag= true;
    }
    ui->lightSwitchBtn->setDefault(m_lightFlag);
    ui->lightStateBtn->setDefault(m_lightFlag);

}

void DeviceControlPanle::on_bedLigSwitchBtn_clicked()
{
    if(m_bedLightFlag){
        ui->outInfoPlaTeEd->appendPlainText(tr("床头灯关闭"));
        m_bedLightFlag= false;
    }else{
        ui->outInfoPlaTeEd->appendPlainText(tr("床头灯打开"));
        m_bedLightFlag= true;
    }

    ui->bedLigSwitchBtn->setDefault(m_bedLightFlag);
    ui->bedLigStateBtn->setDefault(m_bedLightFlag);
//    setBedLightSwitchBack();
}

void DeviceControlPanle::on_soundSwitchBtn_clicked()
{
    if(m_soundFlag){
        ui->outInfoPlaTeEd->appendPlainText(tr("音响关闭"));
        m_soundFlag= false;
    }else{
        ui->outInfoPlaTeEd->appendPlainText(tr("音响打开"));
        m_soundFlag= true;
    }
    ui->soundStateBtn->setDefault(m_soundFlag);
    ui->soundSwitchBtn->setDefault(m_soundFlag);
//    setSoundSwitchBack();
}

void DeviceControlPanle::on_airCondiSwitchBtn_clicked()
{
    if(m_airCondiFlag == 0){
        ui->outInfoPlaTeEd->appendPlainText(tr("空调关闭"));
        m_airCondiFlag= 1;
    }else if(m_airCondiFlag ==1){
        ui->outInfoPlaTeEd->appendPlainText(tr("空调打开"));
        m_airCondiFlag= 0;
    }
    ui->airCondiSwitchBtn->setDefault(m_airCondiFlag);
    ui->airCondiStateBtn->setDefault(m_airCondiFlag);
//    setAirConSwitchBack();
}

void DeviceControlPanle::on_clearOutInfoBtn_clicked()
{
    ui->outInfoPlaTeEd->clear();
}

void DeviceControlPanle::on_tempDownBtn_clicked()
{
    m_airCondiTempre -=1;
    ui->temprShowLiEd->setText(QString::number(m_airCondiTempre)+" C");
}


void DeviceControlPanle::on_tempUpBtn_clicked()
{
    m_airCondiTempre +=1;
    ui->temprShowLiEd->setText(QString::number(m_airCondiTempre)+" C");
}
