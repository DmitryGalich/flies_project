#include "board_model.h"

#include <cmath>
#include <iostream>

BoardModel::BoardModel(const std::string& qml_title,
                       std::vector<Cell>& cells,
                       QObject* parent)
    : QAbstractListModel(parent),
      AbstractQMLHandler(qml_title),
      cells_(cells) {}

int BoardModel::rowCount(const QModelIndex& parent) const {
  Q_UNUSED(parent);
  return cells_.size();
}

int BoardModel::columnCount(const QModelIndex& parent) const {
  Q_UNUSED(parent);
  return cells_.size();
}

QVariant BoardModel::data(const QModelIndex& index, int role) const {
  if (index.row() < 0 || index.row() >= static_cast<int>(cells_.size()))
    return QVariant();

  if (index.column() < 0 || index.column() >= static_cast<int>(cells_.size()))
    return QVariant();

  if (role == CellCapacitytRole)
    return QString::number(cells_.at(index.row()).GetCapacity());

  return QVariant();
}

bool BoardModel::setData(const QModelIndex& index,
                         const QVariant& value,
                         int role) {
  if (index.row() < 0 || index.row() >= static_cast<int>(cells_.size()))
    return false;

  if (index.column() < 0 || index.column() >= static_cast<int>(cells_.size()))
    return false;

  if (role == CellXRole)
    cells_.at(index.row()).SetX(value.toInt());
  else if (role == CellYRole)
    cells_.at(index.row()).SetY(value.toInt());
  else if (role == CellWidthRole)
    cells_.at(index.row()).SetWidth(value.toInt());
  else if (role == CellHeightRole)
    cells_.at(index.row()).SetHeight(value.toInt());
  else if (role == CellCapacitytRole)
    cells_.at(index.row()).SetCapacity(value.toInt());

  return true;
}

QHash<int, QByteArray> BoardModel::roleNames() const {
  QHash<int, QByteArray> roles;

  roles[CellFliesRole] = "cellFlies";
  roles[CellXRole] = "cellX";
  roles[CellYRole] = "cellY";
  roles[CellWidthRole] = "cellWidth";
  roles[CellHeightRole] = "cellHeight";
  roles[CellCapacitytRole] = "cellCapacity";

  return roles;
}

void BoardModel::setGridSide(int value) {
  if (std::pow(value, 2) == cells_.size())
    return;

  beginResetModel();
  cells_.resize(std::pow(value, 2));
  endResetModel();

  emit gridSideChanged();
}

int BoardModel::gridSide() const {
  return std::sqrt(cells_.size());
}

void BoardModel::openCellSettingsWindow(const int cell_index) {
  if (static_cast<size_t>(cell_index) >= cells_.size())
    return;

  emit openCellSettingWindow(cell_index, cells_.at(cell_index).GetCapacity());
}
void BoardModel::setCellCapacity(const int cell_index, const int value) {
  setData(this->index(cell_index, 0), value, CellCapacitytRole);
}
