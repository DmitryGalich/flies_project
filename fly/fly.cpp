#include "fly.h"

Fly::Fly(const int stupidity, QObject* parent)
    : QObject(parent), stupidity_(stupidity) {}

Fly::Fly(const Fly& fly)
    : QObject(fly.parent()), stupidity_(fly.GetStupidity()) {}

Fly Fly::operator=(const Fly& fly) {
  if (this == &fly)
    return *this;

  stupidity_ = fly.GetStupidity();

  return *this;
}

int Fly::GetStupidity() const {
  return stupidity_;
}

void Fly::SetStupidity(const int stupidity) {
  stupidity_ = stupidity;
}
