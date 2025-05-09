#include "mydialog.h"
#include "ui_mydialog.h"
#include "maindialog.h"

MyDialog::MyDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MyDialog)
{
    ui->setupUi(this);
}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::on_pushButton_clicked()
{
    close();
    MainDialog m;
    if(m.exec()==QDialog::Accepted)
    {
        this->show();
    }
    else
    {
        return ;
    }
}

