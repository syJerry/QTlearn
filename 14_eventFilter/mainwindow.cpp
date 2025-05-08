#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWheelEvent>
#include <QEvent>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->installEventFilter(this);
    ui->spinBox->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject* object,QEvent* event)
{
    if(object == ui->textEdit)
    {
        if (event->type() == QEvent::Wheel) {
            QWheelEvent* wheelevent = static_cast<QWheelEvent*>(event);
            // 处理鼠标滚轮事件
            if(wheelevent->angleDelta().ry() > 0)
            {
                qDebug()<<"catch wheel event delta > 0";
                ui->textEdit->zoomIn();
            }
            else
            {
                qDebug()<<"catch wheel event delta < 0";
                ui->textEdit->zoomOut();
            }
            return true;
        }
        return false;
    }
    else if(object == ui->spinBox)
    {
        if(event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyevent = static_cast<QKeyEvent*>(event);
            if(keyevent->key() == Qt::Key_Space)
            {
                ui->spinBox->setValue(0);
                return true;
            }
        }
        return false;
    }
    return QWidget::eventFilter(object,event);
}
