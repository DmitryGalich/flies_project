#include "fly.h"

#include <atomic>
#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

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
  ~Implementation() = default;

  void Run();
  void Stop();

  int GetStupidity();
  void SetStupidity(const int stupidity);

  std::string GetName();
  void SetName(const std::string& name);

  int GetAge();
  void IncreaseAge();

  int GetCellId();

  std::string GetIconPath();

  int GetX();
  void SetX(const int x);

  int GetY();
  void SetY(const int y);

  int GetWidth();
  void SetWidth(const int width);

  int GetHeight();
  void SetHeight(const int height);

 private:
  const std::function<PositionInfo(const int index)> kRequestCellPositionInfo_;
  const std::function<std::vector<int>(const int)> kRequestPossibleCellsToMove_;
  const std::function<bool(const int, const int)> kRequestFlyReplacement_;

  void ThreadFunction();

  PositionInfo position_info_;
  //  PositionInfo cell_position_info_;

  std::string icon_path_;
  int stupidity_;
  int age_{0};
  std::string name_;
  int cell_id_;
  bool is_need_stop_{false};

  std::shared_ptr<std::thread> thread_;
  std::mutex mtx_;
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

int Fly::Implementation::GetStupidity() {
  std::lock_guard<std::mutex> guard(mtx_);

  return stupidity_;
}

void Fly::Implementation::SetStupidity(const int stupidity) {
  std::lock_guard<std::mutex> guard(mtx_);

  stupidity_ = stupidity;
}

std::string Fly::Implementation::GetName() {
  std::lock_guard<std::mutex> guard(mtx_);

  return name_;
}

void Fly::Implementation::SetName(const std::string& name) {
  std::lock_guard<std::mutex> guard(mtx_);

  name_ = name;
}

int Fly::Implementation::GetAge() {
  std::lock_guard<std::mutex> guard(mtx_);

  return age_;
}

void Fly::Implementation::IncreaseAge() {
  std::lock_guard<std::mutex> guard(mtx_);

  age_++;
}

int Fly::Implementation::GetCellId() {
  std::lock_guard<std::mutex> guard(mtx_);

  return cell_id_;
}

std::string Fly::Implementation::GetIconPath() {
  std::lock_guard<std::mutex> guard(mtx_);

  return icon_path_;
}

int Fly::Implementation::GetX() {
  std::lock_guard<std::mutex> guard(mtx_);

  return position_info_.x_;
}

void Fly::Implementation::SetX(const int x) {
  std::lock_guard<std::mutex> guard(mtx_);

  position_info_.x_ = x;
}

int Fly::Implementation::GetY() {
  std::lock_guard<std::mutex> guard(mtx_);

  return position_info_.y_;
}

void Fly::Implementation::SetY(const int y) {
  std::lock_guard<std::mutex> guard(mtx_);

  position_info_.y_ = y;
}

int Fly::Implementation::GetWidth() {
  std::lock_guard<std::mutex> guard(mtx_);

  return position_info_.width_;
}

void Fly::Implementation::SetWidth(const int width) {
  std::lock_guard<std::mutex> guard(mtx_);

  position_info_.width_ = width;
}

int Fly::Implementation::GetHeight() {
  std::lock_guard<std::mutex> guard(mtx_);

  return position_info_.height_;
}

void Fly::Implementation::SetHeight(const int height) {
  std::lock_guard<std::mutex> guard(mtx_);

  position_info_.height_ = height;
}

void Fly::Implementation::ThreadFunction() {
  while (!is_need_stop_) {
    {
      std::lock_guard<std::mutex> guard(mtx_);

      std::cout << std::this_thread::get_id() << " : " << name_ << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::seconds(stupidity_));
  }
}

void Fly::Implementation::Run() {
  std::cout << std::this_thread::get_id() << " : Run" << std::endl;

  std::lock_guard<std::mutex> guard(mtx_);

  thread_.reset(new std::thread([&]() { ThreadFunction(); }));
  is_need_stop_ = false;
}

void Fly::Implementation::Stop() {
  std::cout << std::this_thread::get_id() << " : Stop" << std::endl;

  if (!thread_)
    return;

  std::lock_guard<std::mutex> guard(mtx_);

  is_need_stop_ = true;

  if (!thread_->joinable())
    return;

  thread_->join();
  thread_.reset();
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
