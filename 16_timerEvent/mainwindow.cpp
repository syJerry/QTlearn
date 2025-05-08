#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTimer>
#include <QTime>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    id1 = startTimer(1000);
    id2 = startTimer(2000);
    id3 = startTimer(3000);

    QTimer* timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&MainWindow::slotUpdateLed);
    timer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
    killTimer(id1);
    killTimer(id2);
    killTimer(id3);
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == id1)
    {
        qDebug()<<"id1 timer";
    }

    if(event->timerId() == id2)
    {
        qDebug()<<"id2 timer";
    }

    if(event->timerId() == id3)
    {
        qDebug()<<"id3 timer";
    }
}

void MainWindow::slotUpdateLed()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm:ss");

    if(time.second()%2==0){
        text[5] = ' ';
        text[2] = ' ';
    }
    ui->lcdNumber->setDigitCount(text.length());
    ui->lcdNumber->display(text);
}
