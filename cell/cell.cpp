#include "cell.h"

#include <cmath>

Cell::Cell(const int capacity) : capacity_(capacity), flies_count_(0) {}

int Cell::GetCapacity() const {
  return capacity_;
}

void Cell::SetCapacity(const int capacity) {
  capacity_ = capacity;
}

int Cell::GetFliesCount() const {
  return flies_count_;
}

void Cell::SetFliesyCount(const int flies_count) {
  flies_count_ = flies_count;
}

bool Cell::AddFly() {
  if (flies_count_ >= capacity_)
    return false;

  flies_count_++;
  return true;
}

void Cell::RemoveFly() {
  if (flies_count_ > 0)
    return;

  flies_count_--;
}

PositionInfo Cell::GetPositionInfo() const {
  return position_info_;
}

void Cell::SetX(const int x) {
  position_info_.x_ = x;
}

void Cell::SetY(const int y) {
  position_info_.y_ = y;
}

void Cell::SetWidth(const int width) {
  position_info_.width_ = width;
}

void Cell::SetHeight(const int height) {
  position_info_.height_ = height;
}

Cell& CellsHolder::GetCell(const size_t index) {
  return cells_.at(index);
}

int CellsHolder::GetCellsCount() {
  return cells_.size();
}

void CellsHolder::SetCellsCount(const size_t count) {
  cells_.resize(count);
}

bool CellsHolder::AddFlyToCell(const size_t cell_index) {
  if (cell_index >= cells_.size())
    return false;

  if (cells_.at(cell_index).GetFliesCount() >=
      cells_.at(cell_index).GetCapacity())
    return false;

  cells_.at(cell_index).AddFly();
  return true;
}

std::vector<int> CellsHolder::GetPossibleCellsToMove(const int cell_index) {
  const auto GetAxisVariants = [](const int kSideSize,
                                  const int kAxisCoordinate,
                                  std::vector<int>& acceptable_variants) {
    acceptable_variants.push_back(kAxisCoordinate);

    if (kAxisCoordinate > 0)
      acceptable_variants.push_back(kAxisCoordinate - 1);

    if (kAxisCoordinate < kSideSize - 1)
      acceptable_variants.push_back(kAxisCoordinate + 1);
  };

  // ======================================
  std::vector<int> variants;

  if (cells_.size() <= 1)
    return {};

  int x = cells_.size() % cells_.size();
  int y = std::floor(cells_.size() / std::sqrt(cells_.size()));

  std::vector<int> acceptable_x_variants;
  std::vector<int> acceptable_y_variants;

  GetAxisVariants(std::sqrt(cells_.size()), x, acceptable_x_variants);
  GetAxisVariants(std::sqrt(cells_.size()), y, acceptable_y_variants);

  for (const auto x_coord : acceptable_x_variants)
    for (const auto y_coord : acceptable_y_variants) {
      int neighbour = y_coord * std::sqrt(cells_.size()) + x_coord;
      if (neighbour != cell_index)
        variants.push_back(neighbour);
    }

  return variants;
}

bool CellsHolder::ReplaceFly(const int current_cell_index,
                             const int new_cell_index) {
  return true;
}
