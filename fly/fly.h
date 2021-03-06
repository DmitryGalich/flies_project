#ifndef FLY
#define FLY

#include "support.h"

#include <functional>
#include <memory>
#include <vector>

class Fly {
 public:
  Fly(const std::string& name,
      const int stupidity,
      const int cell_id,
      const std::function<PositionInfo(const int index)>
          request_cell_position_info,
      const std::function<std::vector<int>(const int)>
          request_possible_cells_to_move,
      const std::function<bool(const int, const int)> request_fly_replacement,
      const std::function<int()> request_cells_count_in_edge);
  ~Fly() = default;

  static std::string GetDefaultName();
  static int GetStupidityMax();

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

  int GetX() const;
  void SetX(const int x);
  void SetRealX(const int x);

  int GetY() const;
  void SetY(const int y);
  void SetRealY(const int y);

  int GetWidth() const;
  void SetWidth(const int width);

  int GetHeight() const;
  void SetHeight(const int height);

  bool GetIsAlive() const;

  void PrintInfo() const;

 private:
  class Implementation;
  std::shared_ptr<Implementation> impl_;
};

class FliesHolder {
 public:
  enum class ErrorCodes { kOk, kWrongCell };

  FliesHolder();
  FliesHolder(const FliesHolder&) = delete;
  FliesHolder& operator=(const FliesHolder&) = delete;
  ~FliesHolder() = default;

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
  void SetRequestCellsCountInEdge(const std::function<int()> request);

 private:
  class Implementation;
  std::shared_ptr<Implementation> impl_;
};

#endif
