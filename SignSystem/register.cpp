#include "register.h"
#include "ui_register.h"
#include <QSqlQuery>
#include <QMessageBox>
#include "login.h"

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    this->setWindowTitle("注册信息");


}

Register::~Register()
{
    delete ui;
}

void Register::on_ConfirmBtn_clicked()
{   
    if(ui->number->text()!=NULL&&ui->username->text()!=NULL&&ui->Class->text()!=NULL&&ui->password->text()!=NULL)
    {
        QSqlQuery q;
        q.exec(QString("insert into student values('%1','%2','%3','%4')")
               .arg(ui->number->text()).arg(ui->username->text()).arg(ui->Class->text()).arg(ui->password->text()));
        QMessageBox::warning(this,"提示！","注册成功");
        Login *l=new Login();
        l->show();
        this->close();
    }
    else
    {
        QMessageBox::warning(this,"提示！","请全部填写");
    }  
}

void Register::on_password_textEdited(const QString)
{
    ui->password->setEchoMode(QLineEdit::Password);
}
