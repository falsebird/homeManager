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
    bool lightFlag = false;
    bool bedLightFlag = false;
    bool soundFlag = false;
    int soundVoulum = 0;
    int bedLightVoulum = 0;
    int lightVoulum = 0;
    int airCondiTempre = 26;
    int airCondiFlag = 0;//0 shutdown 1 cold 2 warm
public slots:
    void backoffClicked();

};

#endif // DEVICECONTROLPANLE_H
