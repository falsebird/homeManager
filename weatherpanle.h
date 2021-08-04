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

public slots:
    void backoffClicked();
private slots:
//    void on_pushButton_clicked();
};

#endif // WEATHERPANLE_H
