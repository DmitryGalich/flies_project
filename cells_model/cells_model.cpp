#include "cells_model.h"

#include <cmath>
#include <iostream>

CellsModel::CellsModel(const std::string& qml_title,
                       std::vector<std::vector<Cell> >& cells,
                       QObject* parent)
    : QAbstractListModel(parent), AbstractQMLHandler(qml_title), cells_(cells) {
  ConvertToCellsList();
}

int CellsModel::rowCount(const QModelIndex& parent) const {
  Q_UNUSED(parent);
  return cells_list_.size();
}

QVariant CellsModel::data(const QModelIndex& index, int role) const {
  if (index.row() < 0 || index.row() >= static_cast<int>(cells_list_.size()))
    return QVariant();

  if (role == CapacityRole)
    return cells_list_.at(index.row())->GetCapacity();

  return QVariant();
}

int CellsModel::getCellsCount() const {
  return cells_list_.size();
}

void CellsModel::ConvertToCellsList() {
  cells_list_.resize(std::pow(cells_.size(), 2));

  size_t cells_list_index = 0;
  for (size_t i = 0; i < cells_.size(); i++)
    for (size_t j = 0; j < cells_.size(); j++)
      cells_list_[cells_list_index++] = &cells_.at(i).at(j);
}

QHash<int, QByteArray> CellsModel::roleNames() const {
  QHash<int, QByteArray> roles;
  roles[CapacityRole] = "capacity";
  return roles;
}
