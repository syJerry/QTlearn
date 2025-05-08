#include "hellodialog.h"
#include "ui_hellodialog.h"
#include <QIcon>

HelloDialog::HelloDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::HelloDialog)
{
    ui->setupUi(this);
    // 创建对话框方法一：使用指针创建
    auto w = new QDialog(this);
    w->setModal(true);
    w->show();
    // 创建对话框方法一：使用exec
    auto d = QDialog(this);
    d.setModal(true);
    d.exec();

}

HelloDialog::~HelloDialog()
{
    delete ui;
}
