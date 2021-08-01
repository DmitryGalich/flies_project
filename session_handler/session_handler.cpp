#include "session_handler.h"

#include <iostream>

SessionHandler::SessionHandler() {
  flies_holder_.SetRequestFlyAdditionToCell([&](const int cell_index) {
    return cells_holder_.AddFlyToCell(cell_index);
  });
  flies_holder_.SetRequestCellPositionInfo([&](const int cell_index) {
    return cells_holder_.GetCell(cell_index).GetPositionInfo();
  });
}

FliesHolder& SessionHandler::GetFlies() {
  return flies_holder_;
}

CellsHolder& SessionHandler::GetCells() {
  return cells_holder_;
}
