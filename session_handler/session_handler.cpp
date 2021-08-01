#include "session_handler.h"

#include <iostream>

SessionHandler::SessionHandler() {
  flies_holder_.SetRequestFlyAdditionToCell([&](const int cell_index) {
    return cells_holder_.AddFlyToCell(cell_index);
  });
  flies_holder_.SetRequestCellPositionInfo([&](const int cell_index) {
    return cells_holder_.GetCell(cell_index).GetPositionInfo();
  });
  flies_holder_.SetRequestPossibleCellsToMove([&](const int cell_index) {
    return cells_holder_.GetPossibleCellsToMove(cell_index);
  });
  flies_holder_.SetRequestFlyReplacement(
      [&](const int cell_index, const int new_cell_index) {
        return cells_holder_.ReplaceFly(cell_index, new_cell_index);
      });
}

FliesHolder& SessionHandler::GetFlies() {
  return flies_holder_;
}

CellsHolder& SessionHandler::GetCells() {
  return cells_holder_;
}
