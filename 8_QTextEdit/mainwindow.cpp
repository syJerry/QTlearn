#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextFrame>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //插入文本
    QTextDocument* doc = ui->textEdit->document();
    QTextFrame* root_frame = doc->rootFrame();
    QTextFrameFormat format;
    format.setBorderBrush(Qt::blue);
    format.setBorder(3);
    root_frame->setFrameFormat(format);
    ui->textEdit->insertPlainText("hello world!\n");
    ui->textEdit->insertPlainText("Hello Qt!\n");

    //插入文本块
    QTextFrameFormat  frameFormat;
    frameFormat.setBackground(Qt::lightGray);
    frameFormat.setMargin(10);
    frameFormat.setPadding(5);
    frameFormat.setBorder(2);
    frameFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Dashed);
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.insertFrame(frameFormat);
    ui->textEdit->insertPlainText("inner text!\n");
    ui->textEdit->insertPlainText("Hello inner Text!\n");

    //遍历文本块
    QAction* action_frame = new QAction("frame",this);
    connect(action_frame,&QAction::triggered,this,&MainWindow::showTextFrame);
    ui->menubar->addAction(action_frame);

    //打印文本块
    QAction* action_textfrmae = new QAction("文本块",this);
    connect(action_textfrmae,&QAction::triggered,this,&MainWindow::showTextBlock);
    ui->menubar->addAction(action_textfrmae);

    //设置字体格式
    QAction* action_font = new QAction("字体",this);
    action_font->setCheckable(true);
    connect(action_font,&QAction::triggered,this,&MainWindow::setTextFont);
    ui->menubar->addAction(action_font);

    //插入表格列表图片
    QAction* action_textTable = new QAction(tr("表格"), this);
    QAction* action_textList = new QAction(tr("列表"), this);
    QAction* action_textImage = new QAction(tr("图片"), this);
    connect(action_textTable, &QAction::triggered,this, &MainWindow::insertTable);
    ui->menubar->addAction(action_textTable);
    connect(action_textList, &QAction::triggered,this, &MainWindow::insertList);
    ui->menubar->addAction(action_textList);
    connect(action_textImage, &QAction::triggered,this, &MainWindow::insertImage);
    ui->menubar->addAction(action_textImage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showTextFrame()
{
    auto* doc = ui->textEdit->document();
    auto* root_frame = doc->rootFrame();
    for(auto iter = root_frame->begin();iter != root_frame->end();iter++)
    {
        auto cur_frame = iter.currentFrame();
        auto cur_block = iter.currentBlock();
        if(cur_frame){
            qDebug() << "cur node is frame " ;
        } else if(cur_block.isValid()){
            qDebug() << "cur node is text block ,text is " << cur_block.text();
        }
    }
}

void MainWindow::showTextBlock()
{
    QTextDocument* doc = ui->textEdit->document();
    QTextBlock block = doc->firstBlock();
    for(int i=0;i<doc->blockCount();i++)
    {
        qDebug() << tr("文本块%1, 文本块首行行号%2, 长度%3, 内容%4").arg(i).arg(block.firstLineNumber()).arg(block.length())
                 .arg(block.text());
        block = block.next();
    }
}

void MainWindow::setTextFont(bool checked)
{
    if(checked){
        QTextCursor cursor = ui->textEdit->textCursor();
        //插入居中文本块
        QTextBlockFormat blockFormat;
        blockFormat.setAlignment(Qt::AlignCenter);
        cursor.insertBlock(blockFormat);
        QTextCharFormat charFormat;
        charFormat.setBackground(Qt::lightGray);
        charFormat.setForeground(Qt::blue);
        charFormat.setFont(QFont(tr("宋体"),12,QFont::Bold,true));
        charFormat.setFontUnderline(true);
        cursor.setCharFormat(charFormat);
        cursor.insertText(tr("插入字体"));
    }else{
        QTextCursor cursor = ui->textEdit->textCursor();
        QTextBlockFormat blockFormat;
        blockFormat.setAlignment(Qt::AlignLeft);
        cursor.insertBlock(blockFormat);
        QTextCharFormat charFormat;
        //        charFormat.setBackground(Qt::white);
        //        charFormat.setForeground(Qt::black);
        //        charFormat.setFont(QFont(tr("微软雅黑"),12,QFont::Normal, false));
        //        charFormat.setFontUnderline(false);
        cursor.setCharFormat(charFormat);
        cursor.insertText(tr("微软雅黑字体"));
    }
}

void MainWindow::insertTable()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextTableFormat format;
    format.setCellSpacing(2);
    format.setCellPadding(10);
    cursor.insertTable(2,2,format);
}

void MainWindow::insertList(){
    QTextListFormat format;
    format.setStyle(QTextListFormat::ListDecimal);
    ui->textEdit->textCursor().insertList(format);
}

void MainWindow::insertImage(){
    QTextImageFormat format;
    format.setName(":/img/head.jpg");
    ui->textEdit->textCursor().insertImage(format);
}
