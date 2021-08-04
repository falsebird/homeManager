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
     net = new MyNetwork(this);
     connect(ui->requestBtn,&QPushButton::clicked,this,&WeatherPanle::search);
     connect(net,&MyNetwork::weathreInfo,this,&WeatherPanle::getWeatherInfo);

}

WeatherPanle::~WeatherPanle()
{
    delete ui;
    delete net;
    delete m_currentWeatherInfo;
}

void WeatherPanle::backoffClicked()
{
    hide();
}

void WeatherPanle::search()
{
    QString city = ui->cityLineEd->text();
    this->net->requestNetwork(city);
}

void WeatherPanle::getWeatherInfo(const QString &info)
{

    QJsonDocument jsonDoc = QJsonDocument::fromJson(info.toUtf8());
    QJsonObject jsonRoot = jsonDoc.object();
    QJsonObject data = jsonRoot["data"].toObject();
    QJsonArray forcast = data["forecast"].toArray();
    QJsonObject todayobj = forcast[0].toObject();
    m_currentWeatherInfo = new WeatherInfo(todayobj,this);
    ui->contentShowTextEd->setText(m_currentWeatherInfo->toString());
}

