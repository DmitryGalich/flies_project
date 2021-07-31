#include "session_handler.h"

#include <iostream>

FliesHolder& SessionHandler::GetFlies() {
  return flies_;
}

std::vector<Cell>& SessionHandler::GetCells() {
  return cells_;
}
