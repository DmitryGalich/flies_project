#include "fly.h"

#include <atomic>
#include <iostream>

namespace {

static int flies_count = 0;
static const int kStupidityMax = 10;

static const std::vector<std::string> kIconPaths{
    "res/fly_0.png", "res/fly_1.png", "res/fly_2.png", "res/fly_3.png"};

}  // namespace

Fly::Fly(
    const std::string& name,
    const int stupidity,
    const int cell_id,
    const std::function<PositionInfo(const int)> request_cell_position_info,
    const std::function<std::vector<int>(const int)>
        request_possible_cells_to_move,
    const std::function<bool(const int, const int)> request_fly_replacement,
    QObject* parent)
    : QObject(parent),
      kRequestCellPositionInfo_(request_cell_position_info),
      kRequestPossibleCellsToMove_(request_possible_cells_to_move),
      kRequestFlyReplacement_(request_fly_replacement),
      icon_path_(kIconPaths.at(flies_count++ % kIconPaths.size())),
      stupidity_(stupidity),
      name_(name),
      cell_id_(cell_id) {}

Fly::Fly(const Fly& fly)
    : QObject(fly.parent()),
      kRequestCellPositionInfo_(fly.kRequestCellPositionInfo_),
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

Fly Fly::operator=(const Fly& fly) {
  if (this == &fly)
    return *this;

  age_ = fly.age_;
  icon_path_ = fly.icon_path_;
  name_ = fly.name_;
  stupidity_ = fly.stupidity_;
  position_info_ = fly.position_info_;

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

int Fly::GetX() const {
  return position_info_.x_;
}

void Fly::SetX(const int x) {
  position_info_.x_ = x;
}

int Fly::GetY() const {
  return position_info_.y_;
}

void Fly::SetY(const int y) {
  position_info_.y_ = y;
}

int Fly::GetWidth() const {
  return position_info_.width_;
}

void Fly::SetWidth(const int width) {
  position_info_.width_ = width;
}

int Fly::GetHeight() const {
  return position_info_.height_;
}

void Fly::SetHeight(const int height) {
  position_info_.height_ = height;
}

void Fly::Run() {
  if (is_running_)
    return;

  is_running_ = true;

  std::cout << name_ << " run" << std::endl;
}

void Fly::Stop() {
  if (!is_running_)
    return;
  is_running_ = false;

  std::cout << name_ << " stop" << std::endl;
}

// =================================================

FliesHolder::ErrorCodes FliesHolder::AddFly(std::string name,
                                            int stupidity,
                                            int cell_id) {
  if (!add_fly_to_cell_(cell_id))
    return ErrorCodes::kWrongCell;

  flies_.push_back({name, stupidity, cell_id, request_cell_position_info_,
                    request_possible_cells_to_move_, request_fly_replacement_});
  return ErrorCodes::kOk;
}

Fly& FliesHolder::GetFly(const size_t index) {
  return flies_.at(index);
}

int FliesHolder::GetFliesCount() {
  return flies_.size();
}

bool FliesHolder::Run() {
  if (flies_.empty())
    return false;

  for (auto& fly : flies_)
    fly.Run();

  return true;
}

void FliesHolder::Stop() {
  for (auto& fly : flies_)
    fly.Stop();
}

void FliesHolder::SetRequestFlyAdditionToCell(
    const std::function<bool(const int)> value) {
  add_fly_to_cell_ = value;
}

void FliesHolder::SetRequestCellPositionInfo(
    const std::function<PositionInfo(const int)> request) {
  request_cell_position_info_ = request;
}

void FliesHolder::SetRequestPossibleCellsToMove(
    const std::function<std::vector<int>(const int)> request) {
  request_possible_cells_to_move_ = request;
}

void FliesHolder::SetRequestFlyReplacement(
    const std::function<bool(const int, const int)> request) {
  request_fly_replacement_ = request;
}
