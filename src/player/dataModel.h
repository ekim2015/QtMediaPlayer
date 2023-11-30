#ifndef DATAMODEL_H
#define DATAMODEL_H

#define DEFAULT_FIELD "N/A"

#include <QSortFilterProxyModel>
#include <QTableView>
#include <QWidget>
#include <QVariant>

// struct to populate music items
struct MusicData
{
    qint16 id;
    // convert duration in seconds to time using QDateTime
    qint16 duration;
    QString name;
    QString artist{DEFAULT_FIELD};
};

// subclass QSortFilterProxyModel
// we can add custom sorting by overriding DataModel functions
class DataModel : public QWidget
{
    Q_OBJECT
public:
    DataModel(QWidget *parent = nullptr);
    void insertFileData(const QStringList &files);

protected:
private:
    int getSongNum(const QModelIndex &parent, QSortFilterProxyModel *proxy) const;
    int getColumns(const QModelIndex &parent, QSortFilterProxyModel *proxy) const;
    void createContextMenu(const QPoint &point);
};

#endif // DATAMODEL_H
