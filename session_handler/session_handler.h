#ifndef SESSION_HANDLER
#define SESSION_HANDLER

#include <memory>

#include "cell.h"
#include "fly.h"

class SessionHandler {
 public:
  SessionHandler() = default;
  ~SessionHandler() = default;

  FliesHolder& GetFlies();
  CellsHolder& GetCells();

 private:
  FliesHolder flies_;
  CellsHolder cells_;
};

#endif
