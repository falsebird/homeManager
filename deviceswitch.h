#ifndef DEVICESWITCH_H
#define DEVICESWITCH_H

#include <QFrame>
class Device;
namespace Ui {
class DeviceSwitch;
}

class DeviceSwitch : public QFrame
{
    Q_OBJECT

signals:
    void currentVoulum(int v);
    void currentFlag(bool flag);
    void currentLabel(const QString& lable);
public:
    explicit DeviceSwitch(QWidget *parent = nullptr);
    ~DeviceSwitch();
public slots:
    void setVoulum(int v);
    void deviceSwitch();
    void setDeviceLable(const QString& lable);

private:
    Ui::DeviceSwitch *ui;
    bool switchFlag;
    int curretnVolum;
    Device* device;//指向设备的指针，现阶段先空着
};

#endif // DEVICESWITCH_H
