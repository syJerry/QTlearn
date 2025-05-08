#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "childwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    child_window = new ChildDialog(this);
    //qt4风格，不对函数进行检查,比如此处添加参数编译可通过，但点击没有反应
    // connect(ui->showChildButton,SIGNAL(clicked(bool)),this,SLOT(showChidDialog(1,2,3)));

    //qt5风格
    connect(ui->showChildButton,&QPushButton::clicked,this,&MainWindow::showChidDialog);
    connect(child_window,&ChildDialog::showMainSig,this,&MainWindow::showMainDialog);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showChidDialog()
{
    qDebug()<<"show child dialog"<< Qt::endl;
    child_window->show();
    this->hide();
}

void MainWindow::showMainDialog()
{
    qDebug()<<"show main dialog"<< Qt::endl;
    child_window->hide();
    this->show();
}
