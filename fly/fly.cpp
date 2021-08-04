#include "fly.h"

#include <atomic>
#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

namespace {

static int flies_count = 0;
static const int kStupidityMax = 10;

const float kFlyWidthShareOfCellWidth{0.2};
const float kFlyHeightShareOfCellHeight{0.2};

static const std::vector<std::string> kIconPaths{
    "res/fly_0.png", "res/fly_1.png", "res/fly_2.png", "res/fly_3.png"};

int GenerateValueInRange(int min, int max) {
  return min + (rand() % static_cast<int>(max - min + 1));
};

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
  ~Implementation();

  void Run();
  void RequestStop();
  void Stop();

  int GetStupidity() const;
  void SetStupidity(const int stupidity);

  std::string GetName() const;
  void SetName(const std::string& name);

  int GetAge() const;
  void IncreaseAge();

  int GetCellId() const;

  std::string GetIconPath() const;

  bool GetVisability() const;

  int GetX();
  void SetX(const int x);
  void SetRealX(const int x);

  int GetY();
  void SetY(const int y);
  void SetRealY(const int y);

  int GetWidth();
  void SetWidth(const int width);

  int GetHeight();
  void SetHeight(const int height);

 private:
  const std::function<PositionInfo(const int index)> kRequestCellPositionInfo_;
  const std::function<std::vector<int>(const int)> kRequestPossibleCellsToMove_;
  const std::function<bool(const int, const int)> kRequestFlyReplacement_;

  void FlyingFunction();

  bool is_visible_{false};
  std::string icon_path_{};
  int stupidity_{};
  int age_{0};
  std::string name_;
  int cell_id_{};
  bool is_need_stop_{false};
  bool is_alive_{false};
  PositionInfo position_info_{};
  PositionInfo real_position_info_{};

  std::shared_ptr<std::thread> thread_;
  mutable std::mutex mtx_;
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
      cell_id_(cell_id),
      position_info_([&]() {
        const auto kCellPositionInfo = kRequestCellPositionInfo_(cell_id_);

        int width = kCellPositionInfo.width_ * kFlyWidthShareOfCellWidth;
        int height = kCellPositionInfo.height_ * kFlyHeightShareOfCellHeight;

        return PositionInfo{0, 0, width, height};
      }()) {}

Fly::Implementation::~Implementation() {
  Stop();
}

int Fly::Implementation::GetStupidity() const {
  std::lock_guard<std::mutex> guard(mtx_);

  return stupidity_;
}

void Fly::Implementation::SetStupidity(const int stupidity) {
  std::lock_guard<std::mutex> guard(mtx_);

  stupidity_ = stupidity;
}

std::string Fly::Implementation::GetName() const {
  std::lock_guard<std::mutex> guard(mtx_);

  return name_;
}

void Fly::Implementation::SetName(const std::string& name) {
  std::lock_guard<std::mutex> guard(mtx_);

  name_ = name;
}

int Fly::Implementation::GetAge() const {
  std::lock_guard<std::mutex> guard(mtx_);

  return age_;
}

void Fly::Implementation::IncreaseAge() {
  std::lock_guard<std::mutex> guard(mtx_);

  age_++;
}

int Fly::Implementation::GetCellId() const {
  std::lock_guard<std::mutex> guard(mtx_);

  return cell_id_;
}

std::string Fly::Implementation::GetIconPath() const {
  std::lock_guard<std::mutex> guard(mtx_);

  return icon_path_;
}

bool Fly::Implementation::GetVisability() const {
  return is_visible_;
}

int Fly::Implementation::GetX() {
  std::lock_guard<std::mutex> guard(mtx_);

  return position_info_.x_;
}

void Fly::Implementation::SetX(const int x) {
  std::lock_guard<std::mutex> guard(mtx_);

  position_info_.x_ = x;
}

void Fly::Implementation::SetRealX(const int x) {
  std::lock_guard<std::mutex> guard(mtx_);
  real_position_info_.x_ = x;
}

int Fly::Implementation::GetY() {
  std::lock_guard<std::mutex> guard(mtx_);

  return position_info_.y_;
}

void Fly::Implementation::SetY(const int y) {
  std::lock_guard<std::mutex> guard(mtx_);

  position_info_.y_ = y;
}

void Fly::Implementation::SetRealY(const int y) {
  std::lock_guard<std::mutex> guard(mtx_);
  real_position_info_.y_ = y;
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

void Fly::Implementation::FlyingFunction() {
  int target_point_x{kRequestCellPositionInfo_(cell_id_).x_};
  int target_point_y{kRequestCellPositionInfo_(cell_id_).y_};

  bool is_x_increasing_motion{true};
  bool is_y_increasing_motion{true};

  int flying_seconds_counter{0};
  int cycle_rounds_counter{0};

  const auto CheckAxisTargetPointReaching =
      [](bool& is_increasing_motion, int& fly_position, int& fly_size,
         int& cell_position, int& cell_size, int& target_position) {
        if (((fly_position >= target_position) && is_increasing_motion) ||
            ((fly_position <= target_position) && !is_increasing_motion)) {
          target_position = GenerateValueInRange(
              cell_position, cell_position + cell_size - fly_size);

          is_increasing_motion = (target_position > fly_position);
        }
      };

  const auto MoveFlyOnAxis = [](bool& is_increasing_motion, int& fly_position) {
    if (is_increasing_motion)
      fly_position++;
    else
      fly_position--;
  };

  // =========================================

  auto cell_position_info{kRequestCellPositionInfo_(cell_id_)};

  //  if (!is_visible_) {
  //    is_visible_ = true;

  //    position_info_.x_ =
  //        GenerateValueInRange((cell_position_info.x_ -
  //        real_position_info_.x_),
  //                             (cell_position_info.x_ + cell_position_info.x_
  //                             -
  //                              position_info_.width_ -
  //                              real_position_info_.x_));
  //    position_info_.y_ =
  //        GenerateValueInRange((cell_position_info.y_ -
  //        real_position_info_.y_),
  //                             (cell_position_info.y_ + cell_position_info.y_
  //                             -
  //                              position_info_.height_ -
  //                              real_position_info_.y_));
  //  }

  {
    std::lock_guard<std::mutex> guard(mtx_);
    is_visible_ = true;
  }

  while (!is_need_stop_) {
    {
      std::lock_guard<std::mutex> guard(mtx_);

      position_info_.x_ = GenerateValueInRange(
          (cell_position_info.x_ - real_position_info_.x_),
          (cell_position_info.x_ + cell_position_info.width_ -
           position_info_.width_ - real_position_info_.x_));
      position_info_.y_ = GenerateValueInRange(
          (cell_position_info.y_ - real_position_info_.y_),
          (cell_position_info.y_ + cell_position_info.height_ -
           position_info_.height_ - real_position_info_.y_));

      //      cell_position_info = kRequestCellPositionInfo_(cell_id_);

      //      position_info_.x_ = cell_position_info.x_ -
      //      real_position_info_.x_; position_info_.y_ = cell_position_info.y_
      //      - real_position_info_.y_;

      //      if (name_ == "fly_1") {
      //        std::cout << name_ << " real(" << real_position_info_.x_ << " :
      //        "
      //                  << real_position_info_.y_ << ") just (" <<
      //                  position_info_.x_
      //                  << " : " << position_info_.y_ << ")" << std::endl;
      //      }

      //      // X axis
      //      CheckAxisTargetPointReaching(is_x_increasing_motion,
      //      position_info_.x_,
      //                                   position_info_.width_,
      //                                   kCellPositionInfo.x_,
      //                                   kCellPositionInfo.width_,
      //                                   target_point_x);
      //      MoveFlyOnAxis(is_x_increasing_motion, position_info_.x_);

      //      // Y axis
      //      CheckAxisTargetPointReaching(is_y_increasing_motion,
      //      position_info_.y_,
      //                                   position_info_.height_,
      //                                   kCellPositionInfo.y_,
      //                                   kCellPositionInfo.height_,
      //                                   target_point_y);
      //      MoveFlyOnAxis(is_y_increasing_motion, position_info_.y_);

      //      cycle_rounds_counter++;
    }

    std::this_thread::sleep_for(
        std::chrono::milliseconds(kFliesUpdatePeriodMilliseconds));
  }
}

void Fly::Implementation::Run() {
  if (thread_)
    return;

  std::cout << std::this_thread::get_id() << " : Run" << std::endl;

  std::lock_guard<std::mutex> guard(mtx_);

  thread_.reset(new std::thread([&]() { FlyingFunction(); }));
  is_need_stop_ = false;
  is_alive_ = true;
}

void Fly::Implementation::RequestStop() {
  std::cout << std::this_thread::get_id() << " : Request stop" << std::endl;

  if (!thread_)
    return;

  std::lock_guard<std::mutex> guard(mtx_);

  is_need_stop_ = true;
}

void Fly::Implementation::Stop() {
  std::cout << std::this_thread::get_id() << " : Stop" << std::endl;

  if (!thread_)
    return;

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

std::string Fly::GetIconPath() const {
  return impl_->GetIconPath();
}

int Fly::GetX() const {
  return impl_->GetX();
}

void Fly::SetX(const int x) {
  impl_->SetX(x);
}

void Fly::SetRealX(const int x) {
  impl_->SetRealX(x);
}

bool Fly::GetVisability() const {
  return impl_->GetVisability();
}

int Fly::GetY() const {
  return impl_->GetY();
}

void Fly::SetY(const int y) {
  impl_->SetY(y);
}

void Fly::SetRealY(const int y) {
  impl_->SetRealY(y);
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

void Fly::RequestStop() {
  impl_->RequestStop();
}

void Fly::Stop() {
  impl_->Stop();
}
