#ifndef MUSICPLAYERPANEL_H
#define MUSICPLAYERPANEL_H

#include <QWidget>

namespace Ui {
class MusicPlayerPanel;
}

class MusicPlayerPanel : public QWidget
{
    Q_OBJECT

public:
    explicit MusicPlayerPanel(QWidget *parent = nullptr);
    ~MusicPlayerPanel();

signals:
    void backOff();
private:
    Ui::MusicPlayerPanel *ui;

public slots:
    void backOffClicked();
};

#endif // MUSICPLAYERPANEL_H
