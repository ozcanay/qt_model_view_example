#pragma once

#include <QAbstractTableModel>
#include <QVector>

#include "myobject.h"

class MyModel : public QAbstractTableModel
{
    Q_OBJECT
private:
    QVector<MyObject> my_objects_; /// underlying data structure for the model.
public:
    MyModel(QObject * parent = {});
    int rowCount(const QModelIndex &) const override;
    int columnCount(const QModelIndex &) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::EditRole) const override;

    void add(const MyObject& my_object);
    void edit(const MyObject& my_object);
};
