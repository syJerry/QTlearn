#include "mainwindow.h"
#include "stringlsitmodel.h"
#include <QApplication>
#include <QListView>
#include <QTableView>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    QStringList list;
    list<<"a"<<"b"<<"c";
    StringLsitModel model(list);
    QListView listview;
    listview.setModel(&model);
    //设置拖拽
    listview.setSelectionMode(QAbstractItemView::ExtendedSelection);
    listview.setDragEnabled(true);
    listview.setAcceptDrops(true);
    listview.setDropIndicatorShown(true);
    listview.show();
    // model.insertRows(3,2,QModelIndex());
    // model.removeRows(0,1,QModelIndex());



    QTableView tableview;
    tableview.setModel(&model);
    tableview.show();
    return a.exec();
}
