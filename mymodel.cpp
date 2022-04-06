#include "mymodel.h"

#include <QDebug>
#include <iostream>

MyModel::MyModel(QObject * parent)
    : QAbstractTableModel{parent}
{
}

int MyModel::rowCount(const QModelIndex &) const
{
    return my_objects_.count();
}

int MyModel::columnCount(const QModelIndex &) const {
    return 4;
}

QVariant MyModel::data(const QModelIndex &index, int role) const {
   const auto row = index.row();
   if(row == -1) {
       return {};
   }

   const auto my_object = my_objects_[row];

   if(role == Qt::DisplayRole) {
       switch (index.column()) {
           case 0: return my_object.id;
           case 1: return my_object.a;
           case 2: return my_object.b;
           case 3: return my_object.c;
           default: return {};
       };
   }

   return {};
}

bool MyModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    qDebug() << __PRETTY_FUNCTION__ << ", row: " << index.row() << ", column:" << index.column();

    if (role == Qt::EditRole) {
        if (!checkIndex(index))
            return false;

        my_objects_[index.row()] = qvariant_cast<MyObject>(value);
        emit dataChanged(index, index);

        return true;
    }

    return false;
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const {
   if (orientation != Qt::Horizontal || role != Qt::DisplayRole) {
       return {};
   }

   switch (section) {
       case 0: return "id";
       case 1: return "a";
       case 2: return "b";
       case 3: return "c";
       default: return {};
   }
}

void MyModel::add(const MyObject &my_object)
{
    beginInsertRows({}, my_objects_.count(), my_objects_.count());
    my_objects_.push_back(my_object);
    endInsertRows();
}

void MyModel::edit(const MyObject& my_object) {
    const auto id = my_object.id;
    for(auto i = 0u; i < my_objects_.size(); ++i) {
        if(my_objects_[i].id == id) {
            const auto var = QVariant::fromValue(my_object);
            setData(index(i, 1), var);
            setData(index(i, 2), var);
            setData(index(i, 3), var);
            break;
        }
    }
}

