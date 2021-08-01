#ifndef FLY
#define FLY

#include <QObject>

class Fly : public QObject {
  Q_OBJECT

 public:
  Fly(const std::string& name,
      const int stupidity,
      const int cell_id,
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
  struct PositionInfo {
    int x_;
    int y_;
    int width_;
    int height_;
  } position_info_;

  std::string icon_path_;

  int stupidity_;
  int age_;
  std::string name_;

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

  ErrorCodes AddFly(Fly fly);
  Fly& GetFly(const size_t index);
  int GetFliesCount();

  bool Run();
  void Stop();

  void SetRequestFlyAdditionToCell(const std::function<bool(int)> request);

 private:
  std::function<bool(int)> add_fly_to_cell_;

  std::vector<Fly> flies_;
};

#endif
