#include "fly.h"

#include <atomic>
#include <iostream>

namespace {

static int flies_count = 0;
static const int kStupidityMax = 10;

}  // namespace

Fly::Fly(const std::string& name,
         const int stupidity,
         const int cell_id,
         QObject* parent)
    : QObject(parent),
      stupidity_(stupidity),
      age_(0),
      name_(name),
      cell_id_(cell_id) {
  flies_count++;
}

Fly::Fly(const Fly& fly)
    : QObject(fly.parent()),
      stupidity_(fly.GetStupidity()),
      age_(fly.GetAge()),
      name_(fly.GetName()) {
  flies_count++;
}

Fly Fly::operator=(const Fly& fly) {
  if (this == &fly)
    return *this;

  stupidity_ = fly.GetStupidity();
  name_ = fly.GetName();
  age_ = fly.age_;

  return *this;
}

std::string Fly::GetDefaultName() {
  return "fly_" + std::to_string(flies_count);
}

int Fly::GetStupidityMax() {
  return kStupidityMax;
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

int Fly::GetAge() const {
  return age_;
}

void Fly::IncreaseAge() {
  age_++;
}

int Fly::GetCellId() const {
  return cell_id_;
}

void Fly::Run() {
  std::cout << name_ << " run" << std::endl;
}

void Fly::Stop() {
  std::cout << name_ << " stop" << std::endl;
}
