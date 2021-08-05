#include "musicplayerpanel.h"
#include "ui_musicplayerpanel.h"
#include<QModelIndex>
MusicPlayerPanel::MusicPlayerPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MusicPlayerPanel)
{
    ui->setupUi(this);
    connect(ui->titlebar,&Titlebar::backoffClicked,this,&MusicPlayerPanel::backOffClicked);
    ui->titlebar->setTitle(tr("音乐播放器"));
    ui->titlebar->setNoClose();
    this->setLayout(ui->verticalLayout_3);
//获取歌曲列表
    m_music_palyer = new musicPlayer(this);
    m_fileThread = new FileExplore(this);

    connect(m_fileThread,&FileExplore::getFileListDone,m_music_palyer,&musicPlayer::getFileInfoList);
    m_fileThread->start();
//连接按钮与播放器的槽函数
    connect(ui->preSong_Btn,&QPushButton::clicked,m_music_palyer,&musicPlayer::preMusic);
    connect(ui->nextSong_Btn,&QPushButton::clicked,m_music_palyer,&musicPlayer::nextMusic);
    connect(ui->playSonn_Btn,&QPushButton::clicked,m_music_palyer,&musicPlayer::_playMusic);
    connect(ui->volumDown_Btn,&QPushButton::clicked,m_music_palyer,&musicPlayer::VolumDown);
    connect(ui->volumUp_Btn,&QPushButton::clicked,m_music_palyer,&musicPlayer::volumUp);
    connect(ui->musicListView,&QListView::doubleClicked,this,&MusicPlayerPanel::itemDoubleClicked);
    connect(m_music_palyer,&musicPlayer::playStateChange,ui->playSonn_Btn,&QPushButton::setDefault);
    this->setWindowFlags(Qt::FramelessWindowHint);      //设置为无边框窗口
    this->setMinimumSize(45,45);                        //设置最小尺寸
    ui->verticalSlider->setRange(0,100);
    connect(ui->verticalSlider,&QSlider::valueChanged,m_music_palyer,&musicPlayer::setVolum);
    connect(m_music_palyer,&musicPlayer::volumChanged,ui->musicVolumLiEd,&QLineEdit::setText);
    ui->playSonn_Btn->setDefault(m_music_palyer->getIfPlay());

    //ui->musicListView
    ui->musicListView->setModel(m_music_palyer);
}

MusicPlayerPanel::~MusicPlayerPanel()
{
    delete ui;
    emit stopThread();
    m_fileThread->quit();
    m_fileThread->wait();
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


