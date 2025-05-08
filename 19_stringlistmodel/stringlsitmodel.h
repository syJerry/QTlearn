#ifndef STRINGLSITMODEL_H
#define STRINGLSITMODEL_H

#include "ui_mainwindow.h"

#include <QModelIndex>
class StringLsitModel:public QAbstractListModel
{
    Q_OBJECT
public:
    StringLsitModel(const QStringList& strings,QObject* parent = 0);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role) const override;
    QVariant headerData(int section,Qt::Orientation orientattion,
                        int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    bool setData(const QModelIndex& index,const QVariant& value,int role = Qt::EditRole)override;
    bool insertRows(int position, int rows,const QModelIndex& index)override;
    bool removeRows(int position, int rows,const QModelIndex& index)override;

    //编写拖动逻辑
    virtual QStringList mimeTypes()const override;
    virtual QMimeData* mimeData(const QModelIndexList& indexes) const override;
    virtual bool dropMimeData(const QMimeData* data,
                              Qt::DropAction action,
                              int row,int column,
                              const QModelIndex& parent)override;
    virtual Qt::DropActions supportedDropActions()const override;
private:
    QStringList stringList;
};

#endif // STRINGLSITMODEL_H
