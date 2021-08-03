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
};

#endif // DEVICECONTROLPANLE_H
