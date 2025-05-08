#include "childwindow.h"
#include "ui_childwindow.h"

ChildDialog::ChildDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChildDialog)
{
    ui->setupUi(this);
    this->parent=parent;

    // connect(ui->showMainButton,&QPushButton::clicked,this,&ChildDialog::showMianDialog);

    //利用信号连接信号的方式使代码更简洁
    connect(ui->showMainButton,&QPushButton::clicked,this,&ChildDialog::showMainSig);
}

ChildDialog::~ChildDialog()
{
    delete ui;
}

void ChildDialog::showMianDialog()
{
    //未使用信号机制版本
    // this->hide();
    // parent->show();

    //使用信号机制解耦
    this->hide();
    emit showMainSig();
}
