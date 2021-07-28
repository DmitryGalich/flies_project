#ifndef DATA_HOLDER
#define DATA_HOLDER

#include <QList>

#include <memory>

#include "fly.h"

class DataHolder {
 public:
  DataHolder() : flies_(3) {}
  ~DataHolder() = default;

  std::vector<Fly>& GetFlies() { return flies_; }

 private:
  std::vector<Fly> flies_;
};

#endif
