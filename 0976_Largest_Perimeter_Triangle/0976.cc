
#include <algorithm>
#include <vector>

using std::vector;

class Solution {
 public:
  int largestPerimeter(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    for (int i = nums.size() - 1; 2 <= i; --i)
      if (nums[i] < nums[i - 2] + nums[i - 1])
        return nums[i] + nums[i - 1] + nums[i - 2];

    return 0;
  }
};