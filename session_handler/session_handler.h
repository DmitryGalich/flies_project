#ifndef SESSION_HANDLER
#define SESSION_HANDLER

#include <memory>

#include "cell.h"
#include "fly.h"

class SessionHandler {
 public:
  SessionHandler() : cells_(9) {}
  ~SessionHandler() = default;

  void Run();
  void Stop();

  std::vector<Fly>& GetFlies();
  std::vector<Cell>& GetCells();

 private:
  std::vector<Fly> flies_;
  std::vector<Cell> cells_;
};

#endif
