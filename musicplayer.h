#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QObject>
#include<QAbstractItemModel>
#include<QFileInfo>
#include<QMediaPlayer>
//展示读取到的文件，并负责音乐的播放。
class musicPlayer : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit musicPlayer(QObject *parent = nullptr);
    ~musicPlayer();
protected:
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;

signals:

public slots:
    void getFileInfoList(QFileInfoList *);
    void playMusic(int row);
    void nextMusic();
    void preMusic();
    void _playMusic();//为了方便区分这里在方法名前加_
    void _puseMusic();
    void volumUp();
    void VolumDown();
private:
    QFileInfoList *_fileList;//存储文件信息的指针
    int m_current_paly_row;
    QMediaPlayer *m_music_player;
    int m_current_volum;
};

#endif // MUSICPLAYER_H
