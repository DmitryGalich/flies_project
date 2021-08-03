#ifndef CELL
#define CELL

#include <vector>

#include "support.h"

class Cell {
 public:
  Cell(const int capacity = 15);
  ~Cell() = default;

  int GetCapacity() const;
  void SetCapacity(const int capacity);

  int GetFliesCount() const;
  void SetFliesyCount(const int flies_count);
  bool AddFly();
  void RemoveFly();

  PositionInfo GetPositionInfo() const;
  void SetX(const int x);
  void SetY(const int y);
  void SetWidth(const int width);
  void SetHeight(const int height);

 private:
  int capacity_;
  int flies_count_;

  PositionInfo position_info_;
};

class CellsHolder {
 public:
  CellsHolder() : cells_(9){};
  CellsHolder(const CellsHolder&) = delete;
  CellsHolder& operator=(const CellsHolder&) = delete;
  ~CellsHolder() = default;

  Cell& GetCell(const size_t index);
  int GetCellsCount();
  void SetCellsCount(const size_t count);

  bool AddFlyToCell(const size_t cell_index);

  std::vector<int> GetPossibleCellsToMove(const int cell_index);

  bool ReplaceFly(const int current_cell_index, const int new_cell_index);

 private:
  std::vector<Cell> cells_;
};

#endif
