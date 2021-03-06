#include "board_model.h"

#include <cmath>
#include <iostream>

BoardModel::BoardModel(const std::string& qml_title,
                       CellsHolder& cells,
                       QObject* parent)
    : QAbstractListModel(parent),
      AbstractQMLHandler(qml_title),
      cells_holder_(cells) {}

int BoardModel::rowCount(const QModelIndex& parent) const {
  Q_UNUSED(parent);
  return cells_holder_.GetCellsCount();
}

int BoardModel::columnCount(const QModelIndex& parent) const {
  Q_UNUSED(parent);
  return cells_holder_.GetCellsCount();
}

QVariant BoardModel::data(const QModelIndex& index, int role) const {
  if (index.row() < 0 ||
      index.row() >= static_cast<int>(cells_holder_.GetCellsCount()))
    return QVariant();

  if (index.column() < 0 ||
      index.column() >= static_cast<int>(cells_holder_.GetCellsCount()))
    return QVariant();

  if (role == CellCapacitytRole)
    return QString::number(cells_holder_.GetCell(index.row()).GetCapacity());
  else if (role == CellFliesRole)
    return QString::number(cells_holder_.GetCell(index.row()).GetFliesCount());

  return QVariant();
}

bool BoardModel::setData(const QModelIndex& index,
                         const QVariant& value,
                         int role) {
  if (index.row() < 0 ||
      index.row() >= static_cast<int>(cells_holder_.GetCellsCount()))
    return false;

  if (index.column() < 0 ||
      index.column() >= static_cast<int>(cells_holder_.GetCellsCount()))
    return false;

  if (role == CellXRole)
    cells_holder_.GetCell(index.row()).SetX(value.toInt());
  else if (role == CellYRole)
    cells_holder_.GetCell(index.row()).SetY(value.toInt());
  else if (role == CellWidthRole)
    cells_holder_.GetCell(index.row()).SetWidth(value.toInt());
  else if (role == CellHeightRole)
    cells_holder_.GetCell(index.row()).SetHeight(value.toInt());
  else if (role == CellCapacitytRole)
    cells_holder_.GetCell(index.row()).SetCapacity(value.toInt());
  else if (role == CellFliesRole)
    cells_holder_.GetCell(index.row()).SetFliesyCount(value.toInt());

  dataChanged(index, index,
              {CellFliesRole, CellXRole, CellYRole, CellWidthRole,
               CellHeightRole, CellCapacitytRole});

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
  if (std::pow(value, 2) == cells_holder_.GetCellsCount())
    return;

  beginResetModel();
  cells_holder_.SetCellsCount(std::pow(value, 2));
  endResetModel();

  emit gridSideChanged();
}

int BoardModel::gridSide() const {
  return std::sqrt(cells_holder_.GetCellsCount());
}

void BoardModel::openCellSettingsWindow(const int cell_index) {
  if (cell_index >= cells_holder_.GetCellsCount())
    return;

  emit signalTopenCellSettingWindow(
      cell_index, cells_holder_.GetCell(cell_index).GetCapacity());
}
void BoardModel::setCellCapacity(const int cell_index, const int value) {
  if (cells_holder_.GetCell(cell_index).GetCapacity() == value)
    return;

  setData(index(cell_index, 0), value, CellCapacitytRole);
}

void BoardModel::updateModel() {
  beginResetModel();
  endResetModel();
}
