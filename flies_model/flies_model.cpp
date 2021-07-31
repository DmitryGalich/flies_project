#include "flies_model.h"

#include <iostream>

FliesModel::FliesModel(const std::string& qml_title,
                       std::vector<Fly>& flies,
                       const std::function<int()> request_cells_count,
                       QObject* parent)
    : QAbstractListModel(parent),
      AbstractQMLHandler(qml_title),
      kRequestCellsCount_(request_cells_count),
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
  else if (role == AgeRole)
    return flies_.at(index.row()).GetAge();
  else if (role == CellRole)
    return flies_.at(index.row()).GetCellId();

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

void FliesModel::signalizeToOpenFlySettingsWindow() {
  emit openFlyAdditionWindow(Fly::GetDefaultName().c_str(),
                             kRequestCellsCount_() - 1, Fly::GetStupidityMax());
}

void FliesModel::addFly(QString name, int stupidity, int cell_id) {
  if (name.isEmpty())
    return;

  if (cell_id < 0 || cell_id >= kRequestCellsCount_())
    return;

  if (name.isEmpty())
    return;

  beginResetModel();
  flies_.push_back({name.toStdString(), stupidity, cell_id});
  endResetModel();
}

QHash<int, QByteArray> FliesModel::roleNames() const {
  QHash<int, QByteArray> roles;

  roles[StupidityRole] = "flyStupidity";
  roles[NameRole] = "flyName";
  roles[AgeRole] = "flyAge";
  roles[CellRole] = "flyCell";

  return roles;
}
