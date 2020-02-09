#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    void loginBtn();
private slots:
    void on_RegisterBtn_clicked();

    void on_LoginBtn_clicked();

    void on_ResetBtn_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
