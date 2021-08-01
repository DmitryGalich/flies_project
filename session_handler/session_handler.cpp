#include "session_handler.h"

#include <iostream>

SessionHandler::SessionHandler() {
  flies_holder_.SetRequestFlyAdditionToCell(
      [&](int cell_index) { return cells_holder_.AddFlyToCell(cell_index); });
}

FliesHolder& SessionHandler::GetFlies() {
  return flies_holder_;
}

CellsHolder& SessionHandler::GetCells() {
  return cells_holder_;
}
