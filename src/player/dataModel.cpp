#include "dataModel.h"

// to list mp3 files
DataModel::DataModel(QObject *parent) : QAbstractTableModel(parent)
{
}

DataModel::DataModel(const QList<MusicData> &data, QObject *parent) : QAbstractTableModel(parent), data(data)
{
}
