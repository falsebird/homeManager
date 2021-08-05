#include "musicplayer.h"

musicPlayer::musicPlayer(QObject *parent) : QAbstractListModel(parent)
{
    m_current_paly_row = 0;
    m_current_volum = 20;
    m_music_player = new QMediaPlayer(this);
    m_play_flag = false;
    num = 0;
    emit volumChanged(QString::number( m_current_volum));
}

musicPlayer::~musicPlayer()
{
    delete m_music_player;
}

bool musicPlayer::getIfPlay() const
{
    return m_play_flag;
}

QVariant musicPlayer::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
           return QVariant();

       if (index.row() >= _fileList->size())
           return QVariant();

       // 其他的role一定要有返回值，默认给QVariant()就行
       if((Qt::DisplayRole != role) && (Qt::EditRole != role) && (Qt::DecorationRole != role)
           && (Qt::BackgroundColorRole != role) && (Qt::CheckStateRole != role)){
           return QVariant();
       }
       int curRow = index.row();
       return QVariant(_fileList->at(curRow).fileName());
}

int musicPlayer::rowCount(const QModelIndex &parent) const
{
    return num;

}

int musicPlayer::columnCount(const QModelIndex &parent) const
{
    return 1;
}

QHash<int, QByteArray> musicPlayer::roleNames() const
{

}

void musicPlayer::getFileInfoList(QFileInfoList * fileList)
{
    emit beginResetModel();
    qDebug()<<"get file list music player"<<endl;
    _fileList = fileList;
    num = _fileList->size();
    emit endResetModel();
}

void musicPlayer::playMusic(int row)
{

    if(row >=0&&row<_fileList->size()){
        m_current_paly_row = row;
        QString music_path = _fileList->at(row).absoluteFilePath();
        m_music_player->setMedia(QUrl::fromLocalFile(music_path));
        //3.设置音量
        m_music_player->setVolume(40); // 0~100
        m_music_player->play();
        m_play_flag = true;
        emit playStateChange(m_play_flag);
        qDebug()<<" puse music"<<endl;
    }

}

void musicPlayer::nextMusic()
{
    if((m_current_paly_row+1) == _fileList->size())
        playMusic(0);
    else
        playMusic(m_current_paly_row+1);
}

void musicPlayer::preMusic()
{
    qDebug()<<" preMusic"<<endl;
    if(m_current_paly_row ==0){
        playMusic(_fileList->size()-1);
    }else{
        playMusic(m_current_paly_row-1);
    }
}

void musicPlayer::_playMusic()
{
    qDebug()<<" _playMusic"<<endl;
    if(m_play_flag){
        _puseMusic();
    }else{
        playMusic(m_current_paly_row);
    }

}

void musicPlayer::_puseMusic()
{
    qDebug()<<" puse music"<<endl;
    m_music_player->pause();
    m_play_flag = false;
    emit playStateChange(m_play_flag);
}

void musicPlayer::volumUp()
{
    m_current_volum +=1;
    m_music_player->setVolume(m_current_volum);
    emit volumChanged(QString::number( m_current_volum));
}

void musicPlayer::VolumDown()
{
    m_current_volum -=1;
    m_music_player->setVolume(m_current_volum);
    emit volumChanged(QString::number( m_current_volum));
}

void musicPlayer::setVolum(int v)
{
    m_current_volum = v;
    m_music_player->setVolume(m_current_volum);
    emit volumChanged(QString::number( m_current_volum));
}
