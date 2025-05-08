#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qstring.h>
#include <QRegExpValidator>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->ipEdit->setEchoMode(QLineEdit::Normal);
    QString ip_mask = "000.000.000.000;_";
    ui->ipEdit->setInputMask(ip_mask);

    ui->macEdit->setEchoMode(QLineEdit::Normal);
    QString mac_mask = "HH:HH:HH:HH;_";
    ui->macEdit->setInputMask(mac_mask);

    ui->emailEdit->setEchoMode(QLineEdit::Normal);
    //设置正则表达式过滤  secondtonone23@163.com
    QRegExp regx("[a-zA-Z0-9_-]+@[a-zA-Z0-9]+\.[a-zA-Z0-9]+");
    QValidator *validator = new QRegExpValidator(regx, ui->emailEdit );
    ui->emailEdit->setValidator(validator);


    ui->passwordEdit->setEchoMode(QLineEdit::Password);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{
    qDebug()<<ui->emailEdit->text()<<Qt::endl;
    qDebug()<<ui->passwordEdit->text()<<Qt::endl;
    qDebug()<<ui->ipEdit->text()<<Qt::endl;
    qDebug()<<ui->macEdit->text()<<Qt::endl;
}


void MainWindow::on_pushButton_2_clicked()
{
    close();
}

