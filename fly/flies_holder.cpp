#include "fly.h"

class FliesHolder::Implementation {
 public:
  Implementation() = default;
  Implementation(const Implementation&) = delete;
  Implementation& operator=(const Implementation&) = delete;
  ~Implementation() = default;

  ErrorCodes AddFly(std::string name, int stupidity, int cell_id);
  Fly& GetFly(const size_t index);
  int GetFliesCount() const;

  bool Run();
  void Stop();

  void SetRequestFlyAdditionToCell(const std::function<bool(const int)> value);
  void SetRequestCellPositionInfo(
      const std::function<PositionInfo(const int)> request);
  void SetRequestPossibleCellsToMove(
      const std::function<std::vector<int>(const int)> request);
  void SetRequestFlyReplacement(
      const std::function<bool(const int, const int)> request);

 private:
  std::function<bool(const int)> add_fly_to_cell_;
  std::function<PositionInfo(const int)> request_cell_position_info_;
  std::function<std::vector<int>(const int)> request_possible_cells_to_move_;
  std::function<bool(const int, const int)> request_fly_replacement_;

  std::vector<Fly> flies_;
};

FliesHolder::ErrorCodes FliesHolder::Implementation::AddFly(std::string name,
                                                            int stupidity,
                                                            int cell_id) {
  if (!add_fly_to_cell_(cell_id))
    return ErrorCodes::kWrongCell;

  flies_.push_back({name, stupidity, cell_id, request_cell_position_info_,
                    request_possible_cells_to_move_, request_fly_replacement_});
  return ErrorCodes::kOk;
}

Fly& FliesHolder::Implementation::GetFly(const size_t index) {
  return flies_.at(index);
}

int FliesHolder::Implementation::GetFliesCount() const {
  return flies_.size();
}

bool FliesHolder::Implementation::Run() {
  if (flies_.empty())
    return false;

  for (auto& fly : flies_)
    fly.Run();

  return true;
}

void FliesHolder::Implementation::Stop() {
  for (auto& fly : flies_)
    fly.RequestStop();

  for (auto& fly : flies_)
    fly.Stop();
}

void FliesHolder::Implementation::SetRequestFlyAdditionToCell(
    const std::function<bool(const int)> value) {
  add_fly_to_cell_ = value;
}

void FliesHolder::Implementation::SetRequestCellPositionInfo(
    const std::function<PositionInfo(const int)> request) {
  request_cell_position_info_ = request;
}

void FliesHolder::Implementation::SetRequestPossibleCellsToMove(
    const std::function<std::vector<int>(const int)> request) {
  request_possible_cells_to_move_ = request;
}

void FliesHolder::Implementation::SetRequestFlyReplacement(
    const std::function<bool(const int, const int)> request) {
  request_fly_replacement_ = request;
}

// ======================================================

FliesHolder::FliesHolder() : impl_(std::make_shared<Implementation>()) {}

FliesHolder::ErrorCodes FliesHolder::AddFly(std::string name,
                                            int stupidity,
                                            int cell_id) {
  return impl_->AddFly(name, stupidity, cell_id);
}

Fly& FliesHolder::GetFly(const size_t index) {
  return impl_->GetFly(index);
}

int FliesHolder::GetFliesCount() const {
  return impl_->GetFliesCount();
}

bool FliesHolder::Run() {
  return impl_->Run();
}

void FliesHolder::Stop() {
  impl_->Stop();
}

void FliesHolder::SetRequestFlyAdditionToCell(
    const std::function<bool(const int)> value) {
  impl_->SetRequestFlyAdditionToCell(value);
}

void FliesHolder::SetRequestCellPositionInfo(
    const std::function<PositionInfo(const int)> request) {
  impl_->SetRequestCellPositionInfo(request);
}

void FliesHolder::SetRequestPossibleCellsToMove(
    const std::function<std::vector<int>(const int)> request) {
  impl_->SetRequestPossibleCellsToMove(request);
}

void FliesHolder::SetRequestFlyReplacement(
    const std::function<bool(const int, const int)> request) {
  impl_->SetRequestFlyReplacement(request);
}
