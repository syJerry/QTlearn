#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <thread>
#include <chrono>
#include <qdebug.h>
#include <QDir>
#include <QColorDialog>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QProgressDialog>
#include <QWizard>
#include <QWizardPage>
#include <QLabel>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QRadioButton>


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

void MainWindow::on_colorDialogButton_clicked()
{
    //颜色对话框用来选择颜色
    //方法一
    QColorDialog color_dialog(Qt::blue,this);
    color_dialog.setOption(QColorDialog::ShowAlphaChannel);
    color_dialog.exec();
    QColor color = color_dialog.currentColor();
    qDebug()<<"color is "<<color;

    //方法二
    QColor color2 = QColorDialog::getColor(Qt::blue,this,tr("选择颜色"),QColorDialog::ShowAlphaChannel);
    qDebug()<<"color2 is "<<color2;
}


void MainWindow::on_fileDialogButton_clicked()
{
    QString path = QDir::currentPath();
    QString title = tr("文件对话框");
    QString filter = tr("文本文件(*.txt);;图片文件(*.jpg *.gif *.png);;所有文件(*.*)");
    QString file_name=QFileDialog::getOpenFileName(this,title,path,filter);
    qDebug()<<file_name<<Qt::endl;
}


void MainWindow::on_textInputDialogButton_clicked()
{
    bool ok = false;
    auto text = QInputDialog::getText(this,tr("文字输入对话框"),tr("请输入姓名"),QLineEdit::Normal,tr("admin"),&ok);
    if(ok)
    {
        qDebug()<<text<<Qt::endl;
    }
}


void MainWindow::on_intInputDialogButton_clicked()
{
    bool ok = false;
    auto int_data = QInputDialog::getInt(this,tr("整型输入对话框"),tr("请输入整数"),0,0,100,2,&ok);
    if(ok)
    {
        qDebug()<<int_data<<Qt::endl;
    }
}


void MainWindow::on_floatInputDialogButton_clicked()
{
    bool ok = false;
    auto float_data = QInputDialog::getDouble(this,tr("浮点输入对话框"),tr("请输入浮点数"),0,0,100,2,&ok);
    if(ok)
    {
        qDebug()<<float_data<<Qt::endl;
    }
}


void MainWindow::on_itemInputDialogButton_clicked()
{
    QStringList items;
    items << tr("条目一") << tr("条目二");
    bool ok = false;
    auto item_data = QInputDialog::getItem(this,tr("条目输入对话框"),tr("输入或选择条目"),items,0,true,&ok);
    if(ok)
    {
        qDebug()<<item_data<<Qt::endl;
    }
}



void MainWindow::on_infoDialogButton_clicked()
{
    auto ret  = QMessageBox::question(this,tr("提问对话框"),tr("你是单身吗？"));
    if(ret == QMessageBox::Yes || ret == QMessageBox::No)
    {
        qDebug()<<ret<<Qt::endl;
    }

    auto ret2 = QMessageBox::information(this,tr("通知对话框"),tr("你好单身狗！"),ret);
    if(ret2 == QMessageBox::Ok)
    {
        qDebug()<<ret2<<Qt::endl;
    }

    auto ret3 = QMessageBox::warning(this,tr("警告对话框"),tr("你好!"),ret2);
    if(ret3 == QMessageBox::Ok)
    {
        qDebug()<<ret3<<Qt::endl;
    }

    auto ret4 = QMessageBox::critical(this,tr("关键提示对话框"),tr("我要的是真爱与自由！"),ret3);
    if(ret4 == QMessageBox::Ok)
    {
        qDebug()<<ret4<<Qt::endl;
    }
}




void MainWindow::on_progressDialogButton_clicked()
{
    QProgressDialog progress_dialog(tr("正在复制"),tr("取消复制"),0,5000,this);
    progress_dialog.setWindowTitle(tr("进度对话框"));
    progress_dialog.setWindowModality(Qt::ApplicationModal);

    for(int i=0;i<=5000;i++)
    {
        progress_dialog.setValue(i);
        // QApplication::processEvents();
        if(progress_dialog.wasCanceled())
        {
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

}


void MainWindow::on_wizardDialogButton_clicked()
{
    QWizard wizard(this);
    wizard.setWindowTitle(tr("全城热恋"));
    QWizardPage* page1 = new QWizardPage();
    page1->setTitle(tr("婚恋介绍引导程序"));
    auto label1 = new QLabel();
    label1->setText(tr("该程序帮助您找到人生伴侣"));
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(label1);
    page1->setLayout(layout);
    wizard.addPage(page1);
    QWizardPage* page2 = new QWizardPage();
    page2->setTitle("选择心动类型");

    QButtonGroup *group = new QButtonGroup(page2);
    QRadioButton * btn1 = new QRadioButton();
    btn1->setText("白富美");
    group->addButton(btn1);
    QRadioButton * btn2 = new QRadioButton();
    btn2->setText("萝莉");
    group->addButton(btn2);
    QRadioButton * btn3 = new QRadioButton();
    btn3->setText("御姐");
    group->addButton(btn3);
    QRadioButton * btn4 = new QRadioButton();
    btn4->setText("小家碧玉");
    group->addButton(btn4);
    QRadioButton * btn5 = new QRadioButton();
    btn5->setText("女汉子");
    group->addButton(btn5);

    QRadioButton * btn6 = new QRadioButton();
    btn6->setText("成年人不做选择，全选!");
    group->addButton(btn6);
    QVBoxLayout *vboxLayout2 = new QVBoxLayout();
    for(int i = 0; i < group->buttons().size(); i++){
        vboxLayout2->addWidget(group->buttons()[i]);
    }

    page2->setLayout(vboxLayout2);
    wizard.addPage(page2);

    QWizardPage* page3 = new QWizardPage();
    page3->setTitle(tr("你的缘分即将到来"));
    auto label3 = new QLabel();
    label3->setText(tr("感谢您的参与，接下来的一个月会遇到对的人"));
    QVBoxLayout *layout3 = new QVBoxLayout();
    layout3->addWidget(label3);
    page3->setLayout(layout3);
    wizard.addPage(page3);
    wizard.show();
    wizard.exec();
}

