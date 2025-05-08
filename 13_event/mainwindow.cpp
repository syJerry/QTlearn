#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    line_edit_ = new MyEdit(this);
    line_edit_->move(100,100);
    line_edit_->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    qDebug()<<"mainwindow press event";
}

bool MainWindow::eventFilter(QObject* object, QEvent* event)
{
    if(object == line_edit_ && event->type()==QEvent::KeyPress)
    {
        qDebug()<<"mainwindow catch key press";
        return false;
    }
    return QWidget::eventFilter(object,event);
}
