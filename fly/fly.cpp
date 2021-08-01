#include "fly.h"

#include <atomic>
#include <iostream>

namespace {

static int flies_count = 0;
static const int kStupidityMax = 10;

static const std::vector<std::string> kIconPaths{
    "res/fly_0.png", "res/fly_1.png", "res/fly_2.png", "res/fly_3.png"};

}  // namespace

class Fly::Implementation {
 public:
  Implementation(
      const std::string& name,
      const int stupidity,
      const int cell_id,
      const std::function<PositionInfo(const int index)>
          request_cell_position_info,
      const std::function<std::vector<int>(const int)>
          request_possible_cells_to_move,
      const std::function<bool(const int, const int)> request_fly_replacement);
  Implementation(const Implementation& fly);
  ~Implementation() = default;
  Implementation operator=(const Implementation& fly);

  static std::string GetDefaultName();
  static int GetStupidityMax();

  void Run();
  void Stop();

  int GetStupidity() const;
  void SetStupidity(const int stupidity);

  std::string GetName() const;
  void SetName(const std::string& name);

  int GetAge() const;
  void IncreaseAge();

  int GetCellId() const;

  std::string GetIconPath();

  int GetX() const;
  void SetX(const int x);

  int GetY() const;
  void SetY(const int y);

  int GetWidth() const;
  void SetWidth(const int width);

  int GetHeight() const;
  void SetHeight(const int height);

 private:
  const std::function<PositionInfo(const int index)> kRequestCellPositionInfo_;
  const std::function<std::vector<int>(const int)> kRequestPossibleCellsToMove_;
  const std::function<bool(const int, const int)> kRequestFlyReplacement_;

  PositionInfo position_info_;
  PositionInfo cell_position_info_;

  std::string icon_path_;
  int stupidity_;
  int age_{0};
  std::string name_;
  int cell_id_;
  bool is_running_{false};
};

Fly::Implementation::Implementation(
    const std::string& name,
    const int stupidity,
    const int cell_id,
    const std::function<PositionInfo(const int)> request_cell_position_info,
    const std::function<std::vector<int>(const int)>
        request_possible_cells_to_move,
    const std::function<bool(const int, const int)> request_fly_replacement)
    : kRequestCellPositionInfo_(request_cell_position_info),
      kRequestPossibleCellsToMove_(request_possible_cells_to_move),
      kRequestFlyReplacement_(request_fly_replacement),
      icon_path_(kIconPaths.at(flies_count++ % kIconPaths.size())),
      stupidity_(stupidity),
      name_(name),
      cell_id_(cell_id) {}

Fly::Implementation::Implementation(const Implementation& fly)
    : kRequestCellPositionInfo_(fly.kRequestCellPositionInfo_),
      kRequestPossibleCellsToMove_(fly.kRequestPossibleCellsToMove_),
      kRequestFlyReplacement_(fly.kRequestFlyReplacement_),
      position_info_(fly.position_info_),
      cell_position_info_(fly.cell_position_info_),
      icon_path_(fly.icon_path_),
      stupidity_(fly.stupidity_),
      age_(fly.age_),
      name_(fly.name_),
      cell_id_(fly.cell_id_),
      is_running_(fly.is_running_) {}

Fly::Implementation Fly::Implementation::operator=(const Implementation& fly) {
  if (this == &fly)
    return *this;

  age_ = fly.age_;
  icon_path_ = fly.icon_path_;
  name_ = fly.name_;
  stupidity_ = fly.stupidity_;
  position_info_ = fly.position_info_;

  return *this;
}

std::string Fly::Implementation::GetDefaultName() {
  return "fly_" + std::to_string(flies_count);
}

int Fly::Implementation::GetStupidityMax() {
  return kStupidityMax;
}

int Fly::Implementation::GetStupidity() const {
  return stupidity_;
}

void Fly::Implementation::SetStupidity(const int stupidity) {
  stupidity_ = stupidity;
}

std::string Fly::Implementation::GetName() const {
  return name_;
}

void Fly::Implementation::SetName(const std::string& name) {
  name_ = name;
}

int Fly::Implementation::GetAge() const {
  return age_;
}

void Fly::Implementation::IncreaseAge() {
  age_++;
}

int Fly::Implementation::GetCellId() const {
  return cell_id_;
}

std::string Fly::Implementation::GetIconPath() {
  return icon_path_;
}

int Fly::Implementation::GetX() const {
  return position_info_.x_;
}

void Fly::Implementation::SetX(const int x) {
  position_info_.x_ = x;
}

int Fly::Implementation::GetY() const {
  return position_info_.y_;
}

void Fly::Implementation::SetY(const int y) {
  position_info_.y_ = y;
}

int Fly::Implementation::GetWidth() const {
  return position_info_.width_;
}

void Fly::Implementation::SetWidth(const int width) {
  position_info_.width_ = width;
}

int Fly::Implementation::GetHeight() const {
  return position_info_.height_;
}

void Fly::Implementation::SetHeight(const int height) {
  position_info_.height_ = height;
}

void Fly::Implementation::Run() {
  if (is_running_)
    return;

  is_running_ = true;

  std::cout << name_ << " run" << std::endl;
}

void Fly::Implementation::Stop() {
  if (!is_running_)
    return;
  is_running_ = false;

  std::cout << name_ << " stop" << std::endl;
}

// ==============================================================

Fly::Fly(
    const std::string& name,
    const int stupidity,
    const int cell_id,
    const std::function<PositionInfo(const int)> request_cell_position_info,
    const std::function<std::vector<int>(const int)>
        request_possible_cells_to_move,
    const std::function<bool(const int, const int)> request_fly_replacement)
    : impl_(std::make_shared<Implementation>(name,
                                             stupidity,
                                             cell_id,
                                             request_cell_position_info,
                                             request_possible_cells_to_move,
                                             request_fly_replacement)) {}

Fly::Fly(const Fly& fly) : impl_(fly.impl_) {}

Fly Fly::operator=(const Fly& fly) {
  if (this == &fly)
    return *this;
  impl_ = fly.impl_;
  return *this;
}

std::string Fly::GetDefaultName() {
  return "fly_" + std::to_string(flies_count);
}

int Fly::GetStupidityMax() {
  return kStupidityMax;
}

int Fly::GetStupidity() const {
  return impl_->GetStupidity();
}

void Fly::SetStupidity(const int stupidity) {
  impl_->SetStupidity(stupidity);
}

std::string Fly::GetName() const {
  return impl_->GetName();
}

void Fly::SetName(const std::string& name) {
  impl_->SetName(name);
}

int Fly::GetAge() const {
  return impl_->GetAge();
}

void Fly::IncreaseAge() {
  impl_->IncreaseAge();
}

int Fly::GetCellId() const {
  return impl_->GetCellId();
}

std::string Fly::GetIconPath() {
  return impl_->GetIconPath();
}

int Fly::GetX() const {
  return impl_->GetX();
}

void Fly::SetX(const int x) {
  impl_->SetX(x);
}

int Fly::GetY() const {
  return impl_->GetY();
}

void Fly::SetY(const int y) {
  impl_->SetY(y);
}

int Fly::GetWidth() const {
  return impl_->GetWidth();
}

void Fly::SetWidth(const int width) {
  impl_->SetWidth(width);
}

int Fly::GetHeight() const {
  return impl_->GetHeight();
}

void Fly::SetHeight(const int height) {
  impl_->SetHeight(height);
}

void Fly::Run() {
  impl_->Run();
}

void Fly::Stop() {
  impl_->Stop();
}
