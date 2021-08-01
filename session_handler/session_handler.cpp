#include "session_handler.h"

#include <iostream>

FliesHolder& SessionHandler::GetFlies() {
  return flies_;
}

CellsHolder &SessionHandler::GetCells() {
  return cells_;
}
