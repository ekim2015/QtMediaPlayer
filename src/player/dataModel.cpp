#include "dataModel.h"

// to list mp3 files
DataModel::DataModel(QWidget *parent) : QWidget(parent)
{
    QTableView *tableView = new QTableView;
    QSortFilterProxyModel *model = new QSortFilterProxyModel;

    tableView->setModel(model);
    tableView->setContextMenuPolicy(Qt::CustomContextMenu);

    // make it so right click on table produces context menu
    connect(tableView, SIGNAL(customContextMenuRequested(const QPoint &)), SLOT(createContextMenu(const QPoint &)));
}

// count number of songs (rows)
// we are overriding the pure virtual function from QAbstractItemModel
int DataModel::getSongNum(const QModelIndex &parent, QSortFilterProxyModel *proxy) const
{
    return proxy->rowCount();
}

// creation of popup context menu
int DataModel::getColumns(const QModelIndex &parent, QSortFilterProxyModel *proxy) const
{
}

void DataModel::createContextMenu(const QPoint &point)
{
}
