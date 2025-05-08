#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QCursor cursor;
    cursor.setShape(Qt::OpenHandCursor);
    setCursor(cursor);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        QCursor cursor;
        cursor.setShape(Qt::ClosedHandCursor);
        QApplication::setOverrideCursor(cursor);
        offset = event->globalPos() - pos();
    }
    else if(event->button() == Qt::RightButton)
    {
        QCursor cursor(QPixmap(":/res/mouse.png"));
        QApplication::setOverrideCursor(cursor);
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent* event)
{
    QApplication::restoreOverrideCursor();
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        if(windowState() != Qt::LeftButton)
        {
            if(windowState() != Qt::WindowFullScreen)
            {
                setWindowState(Qt::WindowFullScreen);
            }
            else
            {
                setWindowState(Qt::WindowNoState);
            }
        }
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        QPoint windowpos = event->globalPos()-offset;
        this->move(windowpos);
    }
}


void MainWindow::wheelEvent(QWheelEvent *event)
{
    //鼠标滚动远离使用者放大textedit
    if(event->delta() > 0){
        qDebug() << "catch wheel event delta > 0" << endl;
        ui->textEdit->zoomIn();
    }else {
        qDebug() << "catch wheel event delta < 0" << endl;
        ui->textEdit->zoomOut();
    }
}
