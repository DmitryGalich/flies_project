#ifndef SESSION_HANDLER
#define SESSION_HANDLER

#include <memory>

#include "cell.h"
#include "fly.h"

class SessionHandler {
 public:
  SessionHandler();
  ~SessionHandler() = default;

  FliesHolder& GetFlies();
  CellsHolder& GetCells();

 private:
  FliesHolder flies_holder_;
  CellsHolder cells_holder_;
};

#endif
