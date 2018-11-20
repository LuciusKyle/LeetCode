
#include <assert.h>

class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n == 0) return false;
    while (n != 0) {
      if (n == 1) return true;
      if (n % 2 != 0) return false;
      n /= 2;
    }
    return true;
  }
};

int main(void) {
  Solution sln;
  assert(sln.isPowerOfTwo(1));
  assert(sln.isPowerOfTwo(16));
  assert(!sln.isPowerOfTwo(17));
  return 0;
}
