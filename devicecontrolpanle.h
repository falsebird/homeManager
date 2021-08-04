#ifndef DEVICECONTROLPANLE_H
#define DEVICECONTROLPANLE_H

#include <QWidget>

namespace Ui {
class DeviceControlPanle;
}

class DeviceControlPanle : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceControlPanle(QWidget *parent = nullptr);
    ~DeviceControlPanle();

private:
    Ui::DeviceControlPanle *ui;
    bool m_lightFlag = false;
    bool m_bedLightFlag = false;
    bool m_soundFlag = false;
    int m_soundVoulum = 0;
    int m_bedLightVoulum = 0;
    int m_lightVoulum = 0;
    int m_airCondiTempre = 26;
    int m_airCondiFlag = 0;//0 shutdown 1 cold 2 warm
signals:
    void backOff();
public slots:

    void backoffClicked();
    void lightSliderChange(int v);
    void bedLightSliderChange(int v);
    void soundSliderChange(int v);

private slots:
    void on_lightSwitchBtn_clicked();
    void on_bedLigSwitchBtn_clicked();
    void on_soundSwitchBtn_clicked();
    void on_airCondiSwitchBtn_clicked();
    void on_clearOutInfoBtn_clicked();
    void on_tempDownBtn_clicked();
    void on_tempUpBtn_clicked();
};

#endif // DEVICECONTROLPANLE_H
