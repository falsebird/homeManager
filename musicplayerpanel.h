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

private:
    Ui::MusicPlayerPanel *ui;
};

#endif // MUSICPLAYERPANEL_H
