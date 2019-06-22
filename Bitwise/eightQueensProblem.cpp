// This program solves the problem of Eight Queens Puzzle using recursive backtracking algorithm in bitwise operations.
// 

#include <cinttypes>
#include <iostream>

template <typename T>
class NQueens {
  const T done = 0;
  std::size_t counter = 0;

  void search(const T cl, const T ld, const T rd);
 public:
  NQueens(std::size_t size)
      : done{static_cast<T>(~(static_cast<T>(-1) << size))} {}
  ~NQueens() = default;

  std::size_t solve() { search(0, 0, 0); return counter; }
};

template<typename T>
void NQueens<T>::search(const T cl, const T ld, const T rd) {
  if (cl != done) {
    for (T state = done & ~(cl | ld | rd); state; ) {
      const T place = state & -state;
      state -= place;
      search(cl + place, (ld + place) << 1, (rd + place) >> 1);
    }
  } else {
    ++counter;
  }
}

int main() {
  NQueens<uint16_t> queens{8};
  std::cout << "N queens puzzle:" << queens.solve() << '\n';
  return 0;
}
