#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTextEdit>
#include <QMdiArea>
#include <QMdiSubWindow>
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

void MainWindow::on_actionnewfile_N_triggered()
{
    qDebug()<<"新建文件"<<Qt::endl;
    QTextEdit* textedit = new QTextEdit(this);
    auto childwindow = ui->mdiArea->addSubWindow(textedit);
    childwindow->setWindowTitle(tr("文本编辑子窗口"));
    childwindow->show();
}


void MainWindow::on_actionshowdock_S_triggered()
{
    qDebug()<<"显示dock"<<Qt::endl;
    ui->dockWidget->show();

}

