#ifndef BOARD
#define BOARD

#include <vector>

#include "cell.h"

class Board {
 public:
  Board(const std::vector<std::vector<Cell>>& cell);

 private:
  const std::vector<std::vector<Cell>>& kCells_;
};

#endif
