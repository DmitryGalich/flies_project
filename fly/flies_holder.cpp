#include "fly.h"

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
