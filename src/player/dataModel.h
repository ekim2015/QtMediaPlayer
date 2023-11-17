#ifndef DATAMODEL_H
#define DATAMODEL_H

#include "qtDependencies.h"

// struct to populate music items
struct MusicData
{
    qint16 id;
    QString name;
    QString artist;
    QString duration;
};

// subclass QAbstractItemModel for model
class DataModel : public QAbstractTableModel
{
public:
    DataModel(QObject *parent = nullptr);
    DataModel(const QList<MusicData> &data, QObject *parent = nullptr);

private:
};

#endif // DATAMODEL_H
