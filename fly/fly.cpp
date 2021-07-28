#include "fly.h"

Fly::Fly(const int stupidity, const std::string& name, QObject* parent)
    : QObject(parent), stupidity_(stupidity), name_(name) {}

Fly::Fly(const Fly& fly)
    : QObject(fly.parent()),
      stupidity_(fly.GetStupidity()),
      name_(fly.GetName()) {}

Fly Fly::operator=(const Fly& fly) {
  if (this == &fly)
    return *this;

  stupidity_ = fly.GetStupidity();
  name_ = fly.GetName();

  return *this;
}

int Fly::GetStupidity() const {
  return stupidity_;
}

void Fly::SetStupidity(const int stupidity) {
  stupidity_ = stupidity;
}

std::string Fly::GetName() const {
  return name_;
}

void Fly::SetName(const std::string& name) {
  name_ = name;
}
