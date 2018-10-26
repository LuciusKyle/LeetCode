
#include <array>
#include <ios>
#include <iostream>

class Solution {
 public:
  int rangeBitwiseAnd(const int m, const int n) {
    int rtn = 0;
    for (int i = 0; i < 31; ++i) {
      int cur_bit = m & (1 << i);
      if (cur_bit != 0) {
        cur_bit = (((cur_bit - 1) & m) + (n - m)) < cur_bit ? cur_bit : 0;
        rtn |= cur_bit;
      }
    }
    return rtn;
  }
};

int main(int argc, char const *argv[]) {
  Solution sln;
  int rtn = sln.rangeBitwiseAnd(5, 7);
  rtn = sln.rangeBitwiseAnd(INT_MAX - 2, INT_MAX - 1);
  return 0;
}
