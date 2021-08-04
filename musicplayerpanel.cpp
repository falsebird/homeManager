#include "musicplayerpanel.h"
#include "ui_musicplayerpanel.h"
#include<QModelIndex>
MusicPlayerPanel::MusicPlayerPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MusicPlayerPanel)
{
    ui->setupUi(this);
    connect(ui->widget,&Titlebar::backoffClicked,this,&MusicPlayerPanel::backOffClicked);
    ui->widget->setTitle(tr("music player"));
    ui->widget->setNoClose();
    this->setLayout(ui->verticalLayout_3);
//获取歌曲列表
    m_fileThread = new FileExplore(this);
    m_music_palyer = new musicPlayer(this);
    connect(m_fileThread,&FileExplore::getFileListDone,m_music_palyer,&musicPlayer::getFileInfoList);
    m_fileThread->run();
    //ui->musicListView
    ui->musicListView->setModel(m_music_palyer);
//连接按钮与播放器的槽函数
    connect(ui->preSong_Btn,&QPushButton::clicked,m_music_palyer,&musicPlayer::preMusic);
    connect(ui->nextSong_Btn,&QPushButton::clicked,m_music_palyer,&musicPlayer::nextMusic);
    connect(ui->playSonn_Btn,&QPushButton::clicked,m_music_palyer,&musicPlayer::_playMusic);
    connect(ui->volumDown_Btn,&QPushButton::clicked,m_music_palyer,&musicPlayer::VolumDown);
    connect(ui->volumUp_Btn,&QPushButton::clicked,m_music_palyer,&musicPlayer::volumUp);
    connect(ui->musicListView,&QListView::doubleClicked,this,&MusicPlayerPanel::itemDoubleClicked);
}

MusicPlayerPanel::~MusicPlayerPanel()
{
    delete ui;
    delete m_fileThread;
    delete m_music_palyer;
}

void MusicPlayerPanel::backOffClicked()
{
    hide();
    emit backOff();
}

void MusicPlayerPanel::itemDoubleClicked(const QModelIndex &index)
{
    m_music_palyer->playMusic(index.row());
}


