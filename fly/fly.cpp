#include "fly.h"

#include <atomic>
#include <iostream>

namespace {

static int flies_count = 0;
static const int kStupidityMax = 10;

static const std::vector<std::string> kIconPaths{
    "res/fly_0.png", "res/fly_1.png", "res/fly_2.png", "res/fly_3.png"};

}  // namespace

Fly::Fly(const std::string& name,
         const int stupidity,
         const int cell_id,
         QObject* parent)
    : QObject(parent),
      icon_path_(kIconPaths.at(flies_count++ % kIconPaths.size())),
      stupidity_(stupidity),
      age_(0),
      name_(name),
      cell_id_(cell_id) {}

Fly::Fly(const Fly& fly)
    : QObject(fly.parent()),
      icon_path_(fly.icon_path_),
      stupidity_(fly.stupidity_),
      age_(fly.age_),
      name_(fly.name_) {}

Fly Fly::operator=(const Fly& fly) {
  if (this == &fly)
    return *this;

  age_ = fly.age_;
  icon_path_ = fly.icon_path_;
  name_ = fly.name_;
  stupidity_ = fly.stupidity_;

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

std::string Fly::GetIconPath() {
  return icon_path_;
}

void Fly::Run() {
  std::cout << name_ << " run" << std::endl;
}

void Fly::Stop() {
  std::cout << name_ << " stop" << std::endl;
}
