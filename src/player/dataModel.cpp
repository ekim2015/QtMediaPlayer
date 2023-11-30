#include "dataModel.h"

// to list mp3 files
DataModel::DataModel(QWidget *parent) : QWidget(parent)
{
    QTableView *tableView = new QTableView;
    QSortFilterProxyModel *model = new QSortFilterProxyModel;

    tableView->setModel(model);
    tableView->setContextMenuPolicy(Qt::CustomContextMenu);

    // make it so right click on table produces context menu
    connect(tableView, SIGNAL(customContextMenuRequested(QPoint)), SLOT(createContextMenu(QPoint)));
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
    return proxy->columnCount();
}

void DataModel::createContextMenu(QPoint &point)
{
    QMenu *contextMenu = new QMenu;
    QAction *play = new QAction(tr("&Play"), this);
    QAction *stop = new QAction(tr("&Stop"), this);

    contextMenu->addAction(play);
    contextMenu->addAction(stop);
    contextMenu->addSeparator();

    QAction *edit = new QAction(tr("&Edit"), this);
    contextMenu->addAction(edit);
}

// provide header data only if orientation is vertical
QVariant DataModel::addHeader(int section, int role) const
{
    if (role != Qt::DisplayRole)
    {
        return QVariant();
    }

    switch (section)
    {
    case 0:
        return (tr("ID"));
    case 1:
        return (tr("Name"));
    case 2:
        return (tr("Artist"));
    case 3:
        return (tr("Duration"));
    default:
        break;
    }

    return QVariant();
}
