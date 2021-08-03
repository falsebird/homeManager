#include "musicplayerpanel.h"
#include "ui_musicplayerpanel.h"

MusicPlayerPanel::MusicPlayerPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MusicPlayerPanel)
{
    ui->setupUi(this);
}

MusicPlayerPanel::~MusicPlayerPanel()
{
    delete ui;
}
