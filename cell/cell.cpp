#include "cell.h"

Cell::Cell(const int capacity) : capacity_(capacity), flies_count_(0) {}

int Cell::GetCapacity() const {
  return capacity_;
}

void Cell::SetCapacity(const int capacity) {
  capacity_ = capacity;
}

int Cell::GetFliesyCount() const {
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
