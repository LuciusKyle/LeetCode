
#include<assert.h>

constexpr int negative_mask = ~3;
class Solution {
 public:
  bool isPowerOfFour(int num) {
    while (num) {
      if (num == 1) return true;
      if ((negative_mask | num) != negative_mask) return false;
      num = num >> 2;
    }
    return false;
  }
};

int main(int argc, char const *argv[]) {
  Solution sln;
  assert(sln.isPowerOfFour(1));
  assert(sln.isPowerOfFour(4));
  assert(sln.isPowerOfFour(16));
  assert(!sln.isPowerOfFour(2));
  assert(!sln.isPowerOfFour(1234567));
  return 0;
}
