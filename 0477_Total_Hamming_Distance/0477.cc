
#include <immintrin.h>

#include <vector>

constexpr int a = 1 << 30;

using std::vector;

// 26% beat.
class Solution1 {
 public:
  int totalHammingDistance(const vector<int>& nums) {
    int rtn = 0;
    for (int i = 0, zero = 0, one = 0; i < 31; ++i, zero = 0, one = 0) {
      for (const int num : nums)
        if (num & (1 << i)) ++one;
        else ++zero;
      rtn += zero * one;
    }
    return rtn;
  }
};

// 17% beat? WTF???
class Solution {
 public:
  int totalHammingDistance(vector<int>& nums) {
    int rtn = 0, zero = 0, one = 0;
    bool keep_doing = false;
    do {
      keep_doing = false;
      for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] & 1) ++one;
        else ++zero;
        nums[i] = nums[i] >> 1;
        if (!keep_doing && nums[i]) keep_doing = true;
      }
      rtn += one * zero;
      zero = 0;
      one = 0;
    } while (keep_doing);
    return rtn;
  }
};

int main(void) {
  Solution1 sln1;
  Solution sln;
  vector<int> test_vec({1, 2, 3, 4, 5, 6, 7, 8});
  int rtn = sln1.totalHammingDistance(test_vec);
  rtn = sln.totalHammingDistance(test_vec);
  return 0;
}
