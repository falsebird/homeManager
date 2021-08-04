#ifndef MUSICPLAYERPANEL_H
#define MUSICPLAYERPANEL_H

#include <QWidget>
#include"musicplayer.h"
#include"fileexplore.h"
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
    musicPlayer* m_music_palyer;
    FileExplore* m_fileThread;

public slots:
    void backOffClicked();
    void itemDoubleClicked(const QModelIndex& index);

private slots:

};

#endif // MUSICPLAYERPANEL_H
