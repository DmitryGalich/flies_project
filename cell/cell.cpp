#include "cell.h"

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

int Cell::GetX() const {
  return x_;
}

void Cell::SetX(const int x) {
  x_ = x;
}

int Cell::GetY() const {
  return y_;
}

void Cell::SetY(const int y) {
  y_ = y;
}

int Cell::GetWidth() const {
  return width_;
}

void Cell::SetWidth(const int width) {
  width_ = width;
}

int Cell::GetHeight() const {
  return height_;
}

void Cell::SetHeight(const int height) {
  height_ = height;
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
