#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include<QMap>
#include"logincontrolor.h"
namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();
    void setStyle();

signals:
    void userLogin(const QString&, const QString& passwd);
    void userlogInsuccess(const QString& username);
private slots:
    void on_logInBtn_clicked();
    void logInsuccess(const QString& username);//将用户名作为键


private:
    Ui::LoginDialog *ui;
    LoginControlor* loginControlor;
};

#endif // LOGINDIALOG_H
