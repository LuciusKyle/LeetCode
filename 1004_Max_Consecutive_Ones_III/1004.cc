
#include <vector>

using std::vector;

class Solution {
 public:
  int longestOnes(vector<int>& nums, int k) {
    int fast_i = 0, slow_i = 0, zero_count = 0, result = 0;
    // enlarge window
    while (fast_i < nums.size())
      if (nums[fast_i] == 1)
        ++fast_i;
      else {
        if (zero_count == k) break;
        ++zero_count;
        ++fast_i;
      }
    result = fast_i - slow_i;
    while (fast_i < nums.size()) {
      // shift window
      if (nums[fast_i] == 0) ++zero_count;
      if (nums[slow_i] == 0) --zero_count;
      ++fast_i;
      ++slow_i;

      // try to enlarge window
      if (zero_count <= k) {
        while (fast_i < nums.size())
          if (nums[fast_i] == 1)
            ++fast_i;
          else {
            if (zero_count == k) break;
            ++zero_count;
            ++fast_i;
          }
        result = fast_i - slow_i;
      }
    }
    return result;
  }
};
