#ifndef FLY
#define FLY

#include <QObject>

class Fly : public QObject {
  Q_OBJECT

 public:
  Fly(const std::string& name,
      const int stupidity = 5,
      QObject* parent = nullptr);
  Fly(const int stupidity = 5, QObject* parent = nullptr);
  Fly(const Fly& fly);
  virtual ~Fly() override = default;
  Fly operator=(const Fly& fly);

  int GetStupidity() const;
  void SetStupidity(const int stupidity);

  std::string GetName() const;
  void SetName(const std::string& name);

 private:
  const int kId_;

  int stupidity_;
  std::string name_;
};

#endif
