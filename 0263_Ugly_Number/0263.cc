
#include <assert.h>
#include <limits.h>
#include <array>
#include <unordered_set>
#include <vector>

using std::vector;

constexpr std::array base_arr{2, 3, 5};

// my final solution.
class Solution {
 public:
  bool isUgly(int num) {
    if (num <= 0) return false;
    while (num % 2 == 0) num /= 2;
    while (num % 3 == 0) num /= 3;
    while (num % 5 == 0) num /= 5;
    return num == 1;
  }
};

class Solution1 {
 public:
  Solution1() : ugly_num_set_{1, 2, 3, 5} {}
  bool isUgly(int num) {
    if (num <= 0) return false;
    if (0 != ugly_num_set_.count(num)) return true;
    if ((0 == (num % 2) && isUgly(num / 2)) ||
        (0 == (num % 3) && isUgly(num / 3)) ||
        (0 == (num % 5) && isUgly(num / 5))) {
      ugly_num_set_.insert(num);
      return true;
    } else
      return false;
  }

 private:
  std::unordered_set<int> ugly_num_set_;
};

int main(void) {
  Solution sln;
  Solution1 sln1;
  for (int i = -1; i < 0x1000; ++i) {
    if (sln1.isUgly(i))
      assert(sln.isUgly(i));
    else
      assert(!sln.isUgly(i));
  }
  return 0;
}
