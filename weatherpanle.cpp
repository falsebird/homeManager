#include "weatherpanle.h"
#include "ui_weatherpanle.h"

WeatherPanle::WeatherPanle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WeatherPanle)
{
    ui->setupUi(this);
     connect(ui->widget,&Titlebar::backoffClicked,this,&WeatherPanle::backoffClicked);
     ui->widget->setTitle(tr("weather"));
     ui->widget->setNoClose();
     this->setLayout(ui->verticalLayout);
}

WeatherPanle::~WeatherPanle()
{
    delete ui;
}

void WeatherPanle::backoffClicked()
{
    hide();
}

