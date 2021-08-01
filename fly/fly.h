#ifndef FLY
#define FLY

#include "support.h"

#include <QObject>

class Fly : public QObject {
  Q_OBJECT

 public:
  Fly(const std::string& name,
      const int stupidity,
      const int cell_id,
      std::function<PositionInfo(const int index)> request_cell_position_info,
      QObject* parent = nullptr);
  Fly(const Fly& fly);
  virtual ~Fly() override = default;
  Fly operator=(const Fly& fly);

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
  PositionInfo position_info_;
  PositionInfo cell_position_info_;

  std::string icon_path_;

  int stupidity_;
  int age_;
  std::string name_;

  std::function<PositionInfo(const int index)> request_cell_position_info_;

  // ?
  int cell_id_;
};

class FliesHolder {
 public:
  enum class ErrorCodes { kOk, kWrongCell };

  FliesHolder() = default;
  FliesHolder(const FliesHolder&) = delete;
  FliesHolder& operator=(const FliesHolder&) = delete;
  ~FliesHolder() = default;

  ErrorCodes AddFly(std::string name, int stupidity, int cell_id);
  Fly& GetFly(const size_t index);
  int GetFliesCount();

  bool Run();
  void Stop();

  void SetRequestFlyAdditionToCell(const std::function<bool(const int)> value);
  void SetRequestCellPositionInfo(
      const std::function<PositionInfo(const int)> request);

 private:
  std::function<bool(const int)> add_fly_to_cell_;
  std::function<PositionInfo(const int)> request_cell_position_info_;

  std::vector<Fly> flies_;
};

#endif
