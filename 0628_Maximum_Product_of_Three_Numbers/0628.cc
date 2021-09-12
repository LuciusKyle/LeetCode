
#include <limits.h>
#include <immintrin.h>

#include <algorithm>
#include <vector>

using std::vector;

// sort,
class Solution_1 {
 public:
  int maximumProduct(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    return std::max(nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3], nums[nums.size() - 1] * nums[0] * nums[1]);
    const size_t nums_size = nums.size();
    return std::max(nums[nums_size - 1] * nums[nums_size - 2] * nums[nums_size - 3], nums[nums_size - 1] * nums[0] * nums[1]);
  }
};

class Solution {
 public:
  int maximumProduct(const vector<int>& nums) {
    int min_two_and_max_three[5] = {INT_MAX, INT_MAX, INT_MIN, INT_MIN, INT_MIN};
    for (const int num : nums) {
      if (num < min_two_and_max_three[1]) {
        if (num < min_two_and_max_three[0]) {
          min_two_and_max_three[1] = min_two_and_max_three[0];
          min_two_and_max_three[0] = num;
        } else {
          min_two_and_max_three[1] = num;
        }
      }
      if (min_two_and_max_three[2] < num) {
        if (min_two_and_max_three[3] < num) {
          min_two_and_max_three[2] = min_two_and_max_three[3];
          if (min_two_and_max_three[4] < num) {
            min_two_and_max_three[3] = min_two_and_max_three[4];
            min_two_and_max_three[4] = num;
          } else {
            min_two_and_max_three[3] = num;
          }
        } else {
          min_two_and_max_three[2] = num;
        }
      }
    }
    return std::max(min_two_and_max_three[0] * min_two_and_max_three[1] * min_two_and_max_three[4], min_two_and_max_three[2] * min_two_and_max_three[3] * min_two_and_max_three[4]);
  }
};
