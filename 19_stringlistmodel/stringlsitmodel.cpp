#include "stringlsitmodel.h"
// #include <QAbstractListModel>
#include <QStringList>
#include <QMimeData>
StringLsitModel::StringLsitModel(const QStringList &strings, QObject *parent)
    :QAbstractListModel(parent),stringList(strings)
{

}

int StringLsitModel::rowCount(const QModelIndex &parent) const
{
    return stringList.count();
}

QVariant StringLsitModel::data(const QModelIndex &index, int role) const
{
    //QVariant存储和操作多种数据类型
    if(!index.isValid())
    {
        return QVariant();
    }
    if(index.row() >= stringList.size())
    {
        return QVariant();
    }

    if(role == Qt::DisplayRole || role == Qt::EditRole)
    {
        return stringList.at(index.row());
    }
    else
    {
        return QVariant();
    }
}

QVariant StringLsitModel::headerData(int section, Qt::Orientation orientattion, int role) const
{
    if(role != Qt::DisplayRole)
    {
        return QVariant();
    }
    if(orientattion == Qt::Horizontal)
    {
        return QString("Column %1").arg(section);
    }else{
        return QString("Row %1").arg(section);
    }
}

Qt::ItemFlags StringLsitModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
    {
        return Qt::ItemIsEnabled;
    }
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable
        | Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled;
}

bool StringLsitModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid() && role == Qt::EditRole){
        stringList.replace(index.row(),value.toString());
        emit dataChanged(index,index);
        return true;
    }
    return false;
}

bool StringLsitModel::insertRows(int position, int rows, const QModelIndex &index)
{
    beginInsertRows(QModelIndex(),position,position+rows-1);
    for(int row=0;row<rows;row++)
    {
        stringList.insert(position,"");
    }
    endInsertRows();
    return true;
}

bool StringLsitModel::removeRows(int position, int rows, const QModelIndex &index)
{
    beginRemoveRows(QModelIndex(),position,position+rows-1);
    for(int row=0;row<rows;row++)
    {
        stringList.removeAt(position);
    }
    endRemoveRows();
    return true;
}

QStringList StringLsitModel::mimeTypes() const
{
    //自定义一个类型，用来表示拖动导出的类型
    QStringList types;
    types<<"application/zack.list";
    return types;
}

QMimeData *StringLsitModel::mimeData(const QModelIndexList &indexes) const
{
    //将拖动的数据放入mimedata中
    QMimeData* mimeData = new QMimeData();

    QByteArray encodeData;
    QDataStream stream(&encodeData,QIODevice::WriteOnly);
    foreach (const QModelIndex& index, indexes) {
        if(index.isValid()){
            QString text = data(index,Qt::DisplayRole).toString();
            stream << text;
        }
    }

    mimeData->setData("application/zack.list",encodeData);
    return mimeData;
}

bool StringLsitModel::dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent)
{
    // 将拖放的数据从mimedata中导出
    if(action == Qt::IgnoreAction){
        return true;
    }
    if(!data->hasFormat("application/zack.list"))
    {
        return false;
    }
    if(column > 0)
    {
        return false;
    }


    //设置开始插入行
    int beginrow;
    if(row != -1)
    {
        beginrow = row;
    }
    else if(parent.isValid())
    {
        beginrow = parent.row()+1;
    }
    else
    {
        beginrow = rowCount(QModelIndex());
    }

    QByteArray encodedata = data->data("application/zack.list");
    QDataStream stream(&encodedata,QIODevice::ReadOnly);
    QStringList newitems;
    int rows = 0;
    while(!stream.atEnd()){
        QString text;
        stream >>text;
        newitems<<text;
        rows++;
    }

    insertRows(beginrow,rows,QModelIndex());
    foreach(const QString& text,newitems)
    {
        QModelIndex idx = index(beginrow,0,QModelIndex());
        setData(idx,text);
        beginrow++;
    }
    return true;
}

Qt::DropActions StringLsitModel::supportedDropActions() const
{
    return Qt::CopyAction | Qt::MoveAction;
}



