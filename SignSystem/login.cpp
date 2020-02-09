#include "login.h"
#include "ui_login.h"
#include <QSqlQuery>
#include <QDebug>
#include "widget.h"
#include <QMessageBox>
#include "register.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setWindowTitle("登录界面");
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("sign_system");
    db.setUserName("root");
    db.setPassword("123456");

    if(db.open())
    {
        qDebug()<<"打开数据库成功";
    }
    else
    {
        qDebug()<<"打开数据库失败";
    }
    //登录按钮
    //loginBtn();
}

void Login::on_RegisterBtn_clicked()
{
    Register *r=new Register();
    r->show();
}
void Login::on_LoginBtn_clicked()
{
    QString sname=ui->LE_user->text();
    QString pwd=ui->LE_pwd->text();
    QSqlQuery q;
    q.exec(QString("select * from student where sname='%1'").arg(sname));
    if(q.size())
    {
        q.exec(QString("select * from student where sname='%1' and pwd='%2'").arg(sname).arg(pwd));
        if(q.size())
        {
            QMessageBox::warning(this,"登录提示！","登陆成功");
            Widget *w=new Widget(0,sname);
            w->show();
            this->close();
        }
        else
        {
            QMessageBox::warning(this,"登录提示！","密码错误");
        }
    }
    else
    {
        QMessageBox::warning(this,"登录提示！","用户不存在");
    }
}
void Login::on_ResetBtn_clicked()
{
    if(QMessageBox::question(this,"询问","是否全部清空")==QMessageBox::Yes)
    {
        ui->LE_user->clear();
        ui->LE_pwd->clear();
    }
}
Login::~Login()
{
    delete ui;
}
/*void Login::loginBtn()
{
    connect(ui->LoginBtn,QPushButton::clicked,[=](){
        if(ui->LE_user->text()==NULL||ui->LE_pwd->text()==NULL)
        {
            QMessageBox::warning(this,"登陆提示！","用户名或密码不能为空！");
        }
        else
        {
           QSqlQuery q;
           q.exec(QString("select judge('%1','%2')").arg(ui->LE_user->text()).arg(ui->LE_pwd->text()));
           q.next();
           if(q.value(0).toString()=="登陆成功")
           {
               QMessageBox::warning(this,"登录提示！","登陆成功");
               Widget *w=new Widget(0,ui->LE_user->text());
               w->show();
               this->close();
           }
           else
           {
               QMessageBox::warning(this,"登陆提示！",q.value(0).toString());
           }
        }
    });
}*/



