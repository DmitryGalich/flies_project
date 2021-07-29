#include "cells_model.h"

#include <cmath>
#include <iostream>

CellsModel::CellsModel(const std::string& qml_title,
                       std::vector<Cell>& cells,
                       QObject* parent)
    : QAbstractListModel(parent),
      AbstractQMLHandler(qml_title),
      cells_(cells) {}

int CellsModel::rowCount(const QModelIndex& parent) const {
  Q_UNUSED(parent);
  return cells_.size();
}

int CellsModel::columnCount(const QModelIndex& parent) const {
  Q_UNUSED(parent);
  return cells_.size();
}

QVariant CellsModel::data(const QModelIndex& index, int role) const {
  if (index.row() < 0 || index.row() >= static_cast<int>(cells_.size()))
    return QVariant();

  if (index.column() < 0 || index.column() >= static_cast<int>(cells_.size()))
    return QVariant();

  if (role == CapacityRole)
    return cells_.at(index.row()).GetCapacity();

  return QVariant();
}

QHash<int, QByteArray> CellsModel::roleNames() const {
  QHash<int, QByteArray> roles;
  roles[CapacityRole] = "capacity";
  return roles;
}

void CellsModel::setGridSide(int value) {
  beginResetModel();
  cells_.resize(std::pow(value, 2));
  endResetModel();

  emit gridSideChanged();
}

int CellsModel::gridSide() const {
  return std::sqrt(cells_.size());
}
