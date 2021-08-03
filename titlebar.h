#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include<QMouseEvent>
namespace Ui {
class Titlebar;
}

class Titlebar : public QWidget
{
    Q_OBJECT

public:
    explicit Titlebar(QWidget *parent = nullptr);
    ~Titlebar();

private:
    Ui::Titlebar *ui;
    bool _ispressed;
    QPoint _startMovePos;
protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
};

#endif // TITLEBAR_H
