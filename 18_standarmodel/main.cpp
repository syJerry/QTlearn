#include "mainwindow.h"

#include <QApplication>
#include <QStandardItemModel>
#include <QTreeView>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    QStandardItemModel model;
    QStandardItem* parentItem = model.invisibleRootItem();

    QStandardItem* item0 = new QStandardItem();
    item0->setText("Item0");
    QPixmap pixmap0(50,50);
    pixmap0.fill(Qt::red);
    item0->setIcon(pixmap0);
    item0->setToolTip("indexA");
    parentItem->appendRow(item0);

    parentItem = item0;
    QStandardItem* item1 = new QStandardItem();
    item1->setText("Item1");
    QPixmap pixmap1(50,50);
    pixmap1.fill(Qt::blue);
    item1->setIcon(pixmap1);
    item1->setToolTip("indexB");
    parentItem->appendRow(item1);

    // parentItem = item1;
    QStandardItem* item2 = new QStandardItem();
    item2->setText("Item2");
    QPixmap pixmap2(50,50);
    pixmap2.fill(Qt::green);
    item2->setIcon(pixmap1);
    item2->setToolTip("indexC");
    parentItem->appendRow(item2);

    QTreeView* view = new QTreeView();
    view->setModel(&model);
    view->show();
    return a.exec();
}
