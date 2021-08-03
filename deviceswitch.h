#ifndef DEVICESWITCH_H
#define DEVICESWITCH_H

#include <QFrame>

namespace Ui {
class DeviceSwitch;
}

class DeviceSwitch : public QFrame
{
    Q_OBJECT

public:
    explicit DeviceSwitch(QWidget *parent = nullptr);
    ~DeviceSwitch();

private:
    Ui::DeviceSwitch *ui;
};

#endif // DEVICESWITCH_H
