
#include <limits.h>
#include <stdint.h>

#include <cctype>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

constexpr int kArrSize = 1000 / 32 + (1000 % 32 != 0);

class SmallestInfiniteSet {
 public:
  SmallestInfiniteSet() : num_bitmap_{UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, 1 | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7)} {}

  int popSmallest() {
    for (int i = 0; i < kArrSize - 1; ++i)
      if (num_bitmap_[i] != 0)
        for (int j = 0, probe = 1; j < 32; ++j)
          if ((probe << j) & num_bitmap_[i]) {
            num_bitmap_[i] &= ~(probe << j);
            return 32 * i + j + 1;
          }
    for (int i = 0, probe = 1; i < 8; ++i)
      if ((probe << i) & num_bitmap_[kArrSize - 1]) {
        num_bitmap_[kArrSize - 1] &= ~(probe << i);
        return (kArrSize - 1) * 32 + i + 1;
      }
    return -1;
  }

  void addBack(int num) { num_bitmap_[(num - 1) / 32] |= (1 << ((num - 1) % 32)); }

 private:
  uint32_t num_bitmap_[kArrSize];
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

int main(int argc, char* argv[]) {
  SmallestInfiniteSet sln;
  sln.addBack(2);
  cout << sln.popSmallest() << "\n";
  cout << sln.popSmallest() << "\n";
  cout << sln.popSmallest() << "\n";
  sln.addBack(1);
  cout << sln.popSmallest() << "\n";
  cout << sln.popSmallest() << "\n";
  cout << sln.popSmallest() << "\n";
  cout << endl;
  return 0;
}
