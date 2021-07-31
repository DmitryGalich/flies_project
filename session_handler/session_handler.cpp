#include "session_handler.h"

#include <iostream>

void SessionHandler::Run() {
  std::cout << "Run" << std::endl;
}

void SessionHandler::Stop() {
  std::cout << "Stop" << std::endl;
}

std::vector<Fly>& SessionHandler::GetFlies() {
  return flies_;
}

std::vector<Cell>& SessionHandler::GetCells() {
  return cells_;
}
