#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QTableWidget>
#include <QCheckBox>
#include <QDateTime>
#include <QAbstractItemView>
#include <QMessageBox>
#include "person.h"


Widget::Widget(QWidget *parent,QString sname) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->setWindowTitle("签到信息");

    this->sname=sname;

    dataToTable("select * from student");
    displayClass();
    displaySno();


    connect(ui->tableWidget,ui->tableWidget->cellDoubleClicked,[=](int row,int col){
        Person *p=new Person();
        p->init(ui->tableWidget->item(row,0)->text(),ui->tableWidget->item(row,1)->text());
        p->show();
    });
}
//按班级显示
void Widget::displayClass()
{
    QSqlQuery q3;
    if(q3.exec("select distinct class from student order by class asc"))
    {
        ui->comboBox->addItem("全部班级");
        while(q3.next())
        {
             ui->comboBox->addItem(q3.value(0).toString());
        }
        connect(ui->comboBox,QComboBox::currentTextChanged,[=](QString text){
            if(text=="全部班级")
            {
                dataToTable("select * from student");
            }
            else
            {
                dataToTable(QString("select * from student where class='%1'").arg(text));
            }

        });
    }
}
//按学号显示
void Widget::displaySno()
{
    connect(ui->pushButton,QPushButton::clicked,[=](){
        if(ui->lineEdit->text().isEmpty())
        {
            QMessageBox::warning(this,"warn","您输入为空");
        }
        else
        {
            dataToTable(QString("select * from student where sno like '%1'").arg(ui->lineEdit->text()));
        }
    });
}
//将数据显示到数据库中
void Widget::dataToTable(QString sql)
{
    QSqlQuery q;
    q.exec(QString("select sno from student where sname='%1'").arg(sname));
    q.next();
    QString curSno=q.value(0).toString();


    if(q.exec(sql))
    {
        ui->tableWidget->setRowCount(q.size());
        int i=0;
        while(q.next())
        {
            QCheckBox *c=new QCheckBox("未签到");
            QString sno=q.value(0).toString();

            if(sno!=curSno)
            {
                c->setDisabled(true);
            }

            QSqlQuery q2;
            q2.exec(QString("select sdate from signin where sno=%1 and date(sdate)=curdate()order by sdate desc").arg(sno));
            q2.next();
            if(q2.size())
            {
                c->setText("已签到");
                c->setDisabled(true);
                c->setChecked(true);
                ui->tableWidget->setItem(i,4,new QTableWidgetItem(q2.value(0).toDateTime().toString()));
            }


            ui->tableWidget->setItem(i,0,new QTableWidgetItem(sno));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(q.value(1).toString()));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(q.value(2).toString()));
            ui->tableWidget->setCellWidget(i,3,c);

            connect(c,QCheckBox::clicked,[=](){
//                if(ui->tableWidget->item(i,1)->text()==q.value(0).toString())
//                {
                    //1.修改控件本身的状态
                     c->setText("已签到");
                     c->setDisabled(true);

                    //2.向表格中添加本人签到时间
                     ui->tableWidget->setItem(i,4,new QTableWidgetItem(QDateTime::currentDateTime().toString()));

                    //3.向数据库中插入一条数据
                     QSqlQuery q1;
                     q1.exec(QString("insert into signin values(%1,now())").arg(sno));
//                }
//                else
//                {
//                    c->setChecked(false);
//                }
                });
             i++;
        }
    }
}

Widget::~Widget()
{
    delete ui;
}
