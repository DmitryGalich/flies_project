#include "flies_model.h"

#include <iostream>

FliesModel::FliesModel(const std::string& qml_title,
                       FliesHolder& flies_holder,
                       const std::function<int()> request_cells_count,
                       QObject* parent)
    : QAbstractListModel(parent),
      AbstractQMLHandler(qml_title),
      kRequestCellsCount_(request_cells_count),
      flies_holder_(flies_holder) {}

FliesModel::~FliesModel() {}

int FliesModel::rowCount(const QModelIndex& parent) const {
  Q_UNUSED(parent);
  return flies_holder_.GetFliesCount();
}

QVariant FliesModel::data(const QModelIndex& index, int role) const {
  if (index.row() < 0 ||
      index.row() >= static_cast<int>(flies_holder_.GetFliesCount()))
    return QVariant();

  if (role == StupidityRole)
    return flies_holder_.GetFly(index.row()).GetStupidity();
  else if (role == NameRole)
    return flies_holder_.GetFly(index.row()).GetName().c_str();
  else if (role == AgeRole)
    return flies_holder_.GetFly(index.row()).GetAge();
  else if (role == CellRole)
    return flies_holder_.GetFly(index.row()).GetCellId();

  else if (role == IconRole)
    return flies_holder_.GetFly(index.row()).GetIconPath().c_str();

  else if (role == XRole)
    return flies_holder_.GetFly(index.row()).GetX();
  else if (role == YRole)
    return flies_holder_.GetFly(index.row()).GetY();
  else if (role == WidthRole)
    return flies_holder_.GetFly(index.row()).GetWidth();
  else if (role == HeightRole)
    return flies_holder_.GetFly(index.row()).GetHeight();

  return QVariant();
}

void FliesModel::runSession() {
  if (!flies_holder_.Run())
    return;
}

void FliesModel::stopSession() {
  flies_holder_.Stop();
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
  auto status = flies_holder_.AddFly(name.toStdString(), stupidity, cell_id);
  if (status == FliesHolder::ErrorCodes::kWrongCell) {
    std::cout << "Wrong cell" << std::endl;
  }
  endResetModel();
}

QHash<int, QByteArray> FliesModel::roleNames() const {
  QHash<int, QByteArray> roles;

  roles[StupidityRole] = "flyStupidity";
  roles[NameRole] = "flyName";
  roles[AgeRole] = "flyAge";
  roles[CellRole] = "flyCell";

  roles[IconRole] = "flyIcon";

  roles[XRole] = "flyX";
  roles[YRole] = "flyY";
  roles[WidthRole] = "flyWidth";
  roles[HeightRole] = "flyHeight";

  return roles;
}
