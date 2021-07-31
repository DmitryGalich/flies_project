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

 private:
  std::string icon_path_;

  int stupidity_;
  int age_;
  std::string name_;

  // ?
  int cell_id_;
};

class FliesHolder {
 public:
  FliesHolder() = default;
  ~FliesHolder() = default;

  std::vector<Fly> flies_;
};

#endif
