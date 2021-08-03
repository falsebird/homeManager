#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"logindialog.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void loadStyleSheet(const QString& sheetName);

private:
    Ui::Widget *ui;
    LoginDialog* loginDialog;
private slots:
    void userLoginSuccess(const QString& username);

};
#endif // WIDGET_H
