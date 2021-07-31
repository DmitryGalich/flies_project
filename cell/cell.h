#ifndef CELL
#define CELL

class Cell {
 public:
  Cell(const int capacity = 5);
  ~Cell() = default;

  int GetCapacity() const;
  void SetCapacity(const int capacity);

  int GetFliesCount() const;
  void SetFliesyCount(const int flies_count);
  bool AddFly();
  void RemoveFly();

  int GetX() const;
  void SetX(const int x);

  int GetY() const;
  void SetY(const int y);

  int GetWidth() const;
  void SetWidth(const int width);

  int GetHeight() const;
  void SetHeight(const int height);

 private:
  int capacity_;
  int flies_count_;

  int x_;
  int y_;
  int width_;
  int height_;
};

#endif
