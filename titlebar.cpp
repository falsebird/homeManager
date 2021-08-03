#include "titlebar.h"
#include "ui_titlebar.h"

Titlebar::Titlebar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Titlebar)
{
    _ispressed=false;
    ui->setupUi(this);
    this->setFixedHeight(40);
    connect(ui->clostBtn, SIGNAL(clicked(bool)), qApp, SLOT(quit()));
 // ui->winTitle->setStyleSheet(QString::fromUtf8("font: 20pt \"Arial\";color : #00ffff;"));
//  ui->winTitle->setStyleSheet(QString::fromUtf8("color : #00ffff;"));

}

Titlebar::~Titlebar()
{
    delete ui;
}

void Titlebar::setNoVisBack()
{
    ui->backBtn->setVisible(false);
    ui->leftSpacer->changeSize(0,0);
}

void Titlebar::mousePressEvent(QMouseEvent *event)
{
    _ispressed=true;
    _startMovePos = event->globalPos();
    return QWidget::mousePressEvent(event);//返回父类处理事件

}

void Titlebar::mouseMoveEvent(QMouseEvent *event)
{
    if(_ispressed){
        QPoint movePoint = event->globalPos() - _startMovePos;

            if(parentWidget())
            {
                QPoint widgetPos = this->parentWidget()->pos();
                _startMovePos = event->globalPos();
                parentWidget()->move(widgetPos.x() + movePoint.x(), widgetPos.y() + movePoint.y());
            }
    }
    return QWidget::mouseMoveEvent(event);//返回父类处理事件
}

void Titlebar::mouseReleaseEvent(QMouseEvent *event)
{
    _ispressed= false;
    return QWidget::mouseReleaseEvent(event);//返回父类处理事件

}


