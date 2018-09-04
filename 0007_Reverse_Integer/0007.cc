
// this question doesn't limit function usage, so there are some tricky plays.
// in C++, you can use containers such as vector and string.

#include <assert.h>

class Solution {
 public:
  int reverse(int x) {
    int rtn = 0;
    bool positive = x > 0;
    x *= (positive ? 1 : -1);
    while (x > 0) {
      int digit = x % 10;
      rtn *= 10;
      rtn += digit;
      x /= 10;
    }
    return rtn * (positive ? 1 : -1);
  }
};

int main(void) {
  Solution sln;
  int rtn = sln.reverse(123);
  assert(rtn == 321);
  rtn = sln.reverse(-123);
  assert(rtn == -321);
  rtn = sln.reverse(-120);
  assert(rtn == -21);
  return 0;
}