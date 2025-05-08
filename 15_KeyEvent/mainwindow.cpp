#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    if(event->modifiers() == Qt::ControlModifier)
    {
        if(event->key() == Qt::Key_M && windowState() != Qt::WindowFullScreen)
        {
            setWindowState(Qt::WindowFullScreen);
            return;
        }
        return;
    }
    if(event->key() == Qt::Key_Escape && windowState() == Qt::WindowFullScreen)
    {
        setWindowState(Qt::WindowNoState);
        return;
    }

    //移动按钮
    bool b_upflag = false;
    bool b_downflag = false;
    bool b_leftflag = false;
    bool b_rightflag = false;

    if(event->key() == Qt::Key_W)
    {
        if(event->isAutoRepeat())
        {
            auto curpos = ui->pushButton->pos();
            curpos.setY(curpos.y()-5);
            ui->pushButton->move(curpos);
            return;
        }
        else
        {
            b_upflag = true;
        }
    }

    if(event->key() == Qt::Key_S)
    {
        if(event->isAutoRepeat())
        {
            auto curpos = ui->pushButton->pos();
            curpos.setY(curpos.y()+5);
            ui->pushButton->move(curpos);
            return;
        }
        else
        {
            b_downflag = true;
        }
    }

    if(event->key() == Qt::Key_A)
    {
        if(event->isAutoRepeat())
        {
            auto curpos = ui->pushButton->pos();
            curpos.setX(curpos.x()-5);
            ui->pushButton->move(curpos);
            return;
        }
        else
        {
            b_leftflag = true;
        }
    }

    if(event->key() == Qt::Key_D)
    {
        if(event->isAutoRepeat())
        {
            auto curpos = ui->pushButton->pos();
            curpos.setX(curpos.x()+5);
            ui->pushButton->move(curpos);
            return;
        }
        else
        {
            b_rightflag = true;
        }
    }
    auto curpos = ui->pushButton->pos();
    if(b_upflag){
        curpos.setY(curpos.y()-5);
    }
    if(b_downflag){
        curpos.setY(curpos.y()+5);
    }
    if(b_leftflag){
        curpos.setX(curpos.x()-5);
    }
    if(b_rightflag){
        curpos.setX(curpos.x()+5);
    }
    ui->pushButton->move(curpos);
}
