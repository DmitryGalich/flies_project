#include "flies_model.h"

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

void FliesModel::runSession() {
  for (auto& fly : flies_)
    fly.Run();
}

void FliesModel::stopSession() {
  for (auto& fly : flies_)
    fly.Stop();
}

void FliesModel::addFly() {
  emit openFlyAdditionWindow();
}

QHash<int, QByteArray> FliesModel::roleNames() const {
  QHash<int, QByteArray> roles;
  roles[StupidityRole] = "stupidity";
  roles[NameRole] = "name";
  return roles;
}
