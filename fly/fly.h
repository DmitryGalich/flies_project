#ifndef FLY
#define FLY

#include <QObject>

class Fly : public QObject {
  Q_OBJECT

 public:
  Fly(const int stupidity, QObject* parent = nullptr);
  Fly(const Fly& fly);
  virtual ~Fly() override = default;
  Fly operator=(const Fly& fly);

  int GetStupidity() const;
  void SetStupidity(const int stupidity);

 private:
  int stupidity_;
};

#endif
