#ifndef CELL
#define CELL

class Cell {
 public:
  Cell(const int capacity = 10);
  ~Cell() = default;

  int GetCapacity() const;
  void SetCapacity(const int capacity);

  int GetFliesyCount() const;
  void SetFliesyCount(const int flies_count);
  bool AddFly();
  void RemoveFly();

 private:
  int capacity_;
  int flies_count_;
};

#endif
