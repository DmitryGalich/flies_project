#ifndef CELL
#define CELL

class Cell {
 public:
  struct Coordinates {
    int x_;
    int y_;
  };

  Cell(const int capacity = 10);
  ~Cell() = default;

  int GetCapacity() const;
  void SetCapacity(const int capacity);

  int GetFliesCount() const;
  void SetFliesyCount(const int flies_count);
  bool AddFly();
  void RemoveFly();

  const Coordinates& GetCoordinates() const;
  void SetCoordinates(const Coordinates& cooridinates);

 private:
  int capacity_;
  int flies_count_;
  Coordinates cooridinates_;
};

#endif
