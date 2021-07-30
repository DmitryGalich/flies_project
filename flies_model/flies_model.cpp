#include "cell_model.h"

#include <iostream>

FliesModel::FliesModel(const std::string& qml_title,
                     std::vector<Fly>& flies,
                     QObject* parent)
    : QAbstractListModel(parent),
      AbstractQMLHandler(qml_title),
      flies_(flies) {}

FliesModel::~FliesModel() {}

int FliesModel::rowCount(const QModelIndex& parent) const {
  Q_UNUSED(parent);
  return flies_.size();
}

QVariant FliesModel::data(const QModelIndex& index, int role) const {
  if (index.row() < 0 || index.row() >= static_cast<int>(flies_.size()))
    return QVariant();

  if (role == StupidityRole)
    return flies_.at(index.row()).GetStupidity();
  else if (role == NameRole)
    return flies_.at(index.row()).GetName().c_str();

  return QVariant();
}

void FliesModel::setFlyStupidity(const int index, const int stupidity) {
  flies_[index].SetStupidity(stupidity);
}

void FliesModel::setFlyName(const int index, const QString& name) {
  flies_[index].SetName(name.toStdString());
}

void FliesModel::setFliesCount(const int count) {
  beginResetModel();
  flies_.resize(count);
  endResetModel();
}

int FliesModel::getFliesCount() const {
  return flies_.size();
}

QHash<int, QByteArray> FliesModel::roleNames() const {
  QHash<int, QByteArray> roles;
  roles[StupidityRole] = "stupidity";
  roles[NameRole] = "name";
  return roles;
}
