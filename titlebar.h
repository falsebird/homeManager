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

signals:
    void backoffClicked();
public slots:
    void setNoVisBack();
    void setNoClose();
    void setTitle(const QString& title);
private:
    Ui::Titlebar *ui;
    bool _ispressed;
    QPoint _startMovePos;
protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
private slots:
    void on_backBtn_clicked();
};

#endif // TITLEBAR_H
