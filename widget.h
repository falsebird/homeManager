#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"logindialog.h"
#include"musicplayerpanel.h"
#include"weatherpanle.h"
#include"devicecontrolpanle.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void loadStyleSheet(const QString& sheetName);
    void setMusicPanle();
    void setDeviceContPanle();
    void setWeatherPanle();
    void setMainWindos();
    void setLoginDialog();
private:
    Ui::Widget *ui;
    LoginDialog* loginDialog;
    MusicPlayerPanel* musicPlayerPanel;
    WeatherPanle* weatherPanle;
    DeviceControlPanle* deviceContPanle;
private slots:
    void userLoginSuccess(const QString& username);
    void secondPageBackOff();
    void on_weatherRequest_Btn_clicked();
    void on_music_Btn_clicked();
    void on_control_Btn_clicked();
};
#endif // WIDGET_H
