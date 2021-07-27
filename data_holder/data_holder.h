#ifndef DATA_HOLDER
#define DATA_HOLDER

#include <QList>

#include <memory>

#include "fly.h"

class DataHolder {
 public:
  DataHolder() = default;
  ~DataHolder() = default;

  QList<Fly>& GetFlies() { return flies_; }

 private:
  QList<Fly> flies_;
};

#endif
