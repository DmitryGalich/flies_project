#include "flies_model.h"

FliesModel::FliesModel(const std::string& qml_title,
                       QList<Fly>& flies,
                       QObject* parent)
    : QAbstractListModel(parent),
      AbstractQMLHandler(qml_title),
      flies_(flies) {}

FliesModel::~FliesModel() {}

void FliesModel::AddFly(const Fly& fly) {
  beginInsertRows(QModelIndex(), rowCount(), rowCount());
  flies_.push_back(fly);
  endInsertRows();
}

int FliesModel::rowCount(const QModelIndex& parent) const {
  Q_UNUSED(parent);
  return flies_.count();
}

QVariant FliesModel::data(const QModelIndex& index, int role) const {
  if (index.row() < 0 || index.row() >= flies_.count())
    return QVariant();

  if (role == StupidityRole)
    return flies_.at(index.row()).GetStupidity();

  return QVariant();
}

QHash<int, QByteArray> FliesModel::roleNames() const {
  QHash<int, QByteArray> roles;
  roles[StupidityRole] = "stupidity";
  return roles;
}
