#include "fly.h"

#include <atomic>
#include <iostream>

namespace {
const std::string kDefaultName{"Fly"};
static std::atomic<int> flies_count{0};
}  // namespace

Fly::Fly(const std::string& name, const int stupidity, QObject* parent)
    : QObject(parent),
      kId_(flies_count++),
      stupidity_(stupidity),
      name_(name) {}

Fly::Fly(const int stupidity, QObject* parent)
    : QObject(parent), kId_(flies_count++), stupidity_(stupidity) {
  name_ = kDefaultName + "_" + std::to_string(kId_);
}

Fly::Fly(const Fly& fly)
    : QObject(fly.parent()),
      kId_(flies_count++),
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

void Fly::Run() {
  std::cout << name_ << " run" << std::endl;
}

void Fly::Stop() {
  std::cout << name_ << " stop" << std::endl;
}
