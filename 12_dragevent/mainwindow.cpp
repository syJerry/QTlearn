#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDragEnterEvent>
#include <QMimeData>
#include <QTextCodec>
#include <QTextStream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);
    ui->textEdit->setAcceptDrops(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dragEnterEvent(QDragEnterEvent* event)
{
    if(event->mimeData()->hasUrls())
    {
        event->acceptProposedAction();
    }else
    {
        event->ignore();
    }
}

void MainWindow::dropEvent(QDropEvent* event)
{
    const QMimeData* mimedata = event->mimeData();
    if(mimedata->hasUrls())
    {
        QList<QUrl> urllist = mimedata->urls();
        QString filename = urllist[0].toLocalFile();
        if(!filename.isEmpty())
        {
            QTextCodec* codec = QTextCodec::codecForName("UTF-8");
            QFile file(filename);
            if(!file.open(QIODevice::ReadOnly))
            {
                return;
            }
            QTextCodec::setCodecForLocale(codec);
            QTextStream in(&file);

            ui->textEdit->setText(in.readAll());
        }
    }
    else
    {
        event->ignore();
    }
}
