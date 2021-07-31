#include "session_handler.h"

#include <iostream>

std::vector<Fly>& SessionHandler::GetFlies() {
  return flies_;
}

std::vector<Cell>& SessionHandler::GetCells() {
  return cells_;
}
