#include "weatherpanle.h"
#include "ui_weatherpanle.h"

WeatherPanle::WeatherPanle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WeatherPanle)
{
    ui->setupUi(this);
     connect(ui->titlebar,&Titlebar::backoffClicked,this,&WeatherPanle::backoffClicked);
     ui->titlebar->setTitle(tr("天气查询"));
     ui->titlebar->setNoClose();
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
    emit backOff();
}

void WeatherPanle::search()
{
    QString city = ui->cityLineEd->text();
    if(city!=""){
        this->net->requestNetwork(city);
    }

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

