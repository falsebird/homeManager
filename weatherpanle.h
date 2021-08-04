#ifndef WEATHERPANLE_H
#define WEATHERPANLE_H

#include <QWidget>
#include"mynetwork.h"
#include"weatherinfo.h"
namespace Ui {
class WeatherPanle;
}

class WeatherPanle : public QWidget
{
    Q_OBJECT

public:
    explicit WeatherPanle(QWidget *parent = nullptr);
    ~WeatherPanle();

private:
    Ui::WeatherPanle *ui;
    MyNetwork* net;
    WeatherInfo* m_currentWeatherInfo;
signals:
    void backOff();
public slots:
    void backoffClicked();
    void search();
    void getWeatherInfo(const QString& info);

private slots:
//    void on_pushButton_clicked();
};

#endif // WEATHERPANLE_H
