
#include <math.h>

#include <vector>

using std::vector;

class Solution {
 public:
  int threeSumClosest(vector<int>& nums, const int target) {
    std::sort(nums.begin(), nums.end());
    int closest_sum = nums[0] + nums[1] + nums[2], closest_distance = abs(closest_sum - target);
    const int length = nums.size();
    for (int i = 0; i < length - 2; ++i) {
      int l_index = i + 1, r_index = length - 1;
      while (l_index < r_index) {
        const int temp_sum = nums[i] + nums[l_index] + nums[r_index];
        if (abs(temp_sum - target) < closest_distance) {
          closest_distance = abs(temp_sum - target);
          closest_sum = temp_sum;
        }
        if (temp_sum < target)
          ++l_index;
        else if (target < temp_sum)
          --r_index;
        else
          return target;
      }
    }
    return closest_sum;
  }
};