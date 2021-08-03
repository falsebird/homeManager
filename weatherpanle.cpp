#include "weatherpanle.h"
#include "ui_weatherpanle.h"

WeatherPanle::WeatherPanle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WeatherPanle)
{
    ui->setupUi(this);
}

WeatherPanle::~WeatherPanle()
{
    delete ui;
}
