#ifndef SESSION_HANDLER
#define SESSION_HANDLER

#include <memory>

#include "cell.h"
#include "fly.h"

class SessionHandler {
 public:
  SessionHandler() : cells_(9) {}
  ~SessionHandler() = default;

  FliesHolder& GetFlies();
  std::vector<Cell>& GetCells();

 private:
  FliesHolder flies_;
  std::vector<Cell> cells_;
};

#endif
