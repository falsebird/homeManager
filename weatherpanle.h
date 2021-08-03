#ifndef WEATHERPANLE_H
#define WEATHERPANLE_H

#include <QWidget>

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
};

#endif // WEATHERPANLE_H
