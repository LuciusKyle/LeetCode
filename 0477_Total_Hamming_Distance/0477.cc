
#include <immintrin.h>

#include <vector>

constexpr int a = 1 << 30;

using std::vector;

class Solution {
 public:
  int totalHammingDistance(vector<int>& nums) {
    int rtn = 0;
    for (int i = 0, zero = 0, one = 0; i < 31; ++i, zero = 0, one = 0) {
      for (const int num : nums)
        if (num & (1 << i))
          ++one;
        else
          ++zero;
      rtn += zero * one;
    }
    return rtn;
  }
};
