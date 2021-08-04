#include "musicplayerpanel.h"
#include "ui_musicplayerpanel.h"

MusicPlayerPanel::MusicPlayerPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MusicPlayerPanel)
{
    ui->setupUi(this);
    connect(ui->widget,&Titlebar::backoffClicked,this,&MusicPlayerPanel::backOffClicked);
    ui->widget->setTitle(tr("music player"));
    ui->widget->setNoClose();
    this->setLayout(ui->verticalLayout_3);

    m_fileThread = new FileExplore(this);
    m_music_palyer = new musicPlayer(this);
    connect(m_fileThread,&FileExplore::getFileListDone,m_music_palyer,&musicPlayer::getFileInfoList);
    m_fileThread->run();
    //ui->musicListView
    ui->musicListView->setModel(m_music_palyer);
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
