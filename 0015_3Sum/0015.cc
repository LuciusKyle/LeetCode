
#include <assert.h>
#include <vector>
#include<algorithm>

using std::vector;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    for (int i = 0; i + 2 < nums.size(); ++i) {
      if (0 < i && nums[i] == nums[i - 1]) continue;
      if (0 < nums[i]) break;
      int l_index = i + 1, r_index = nums.size() - 1;
      while (l_index < r_index) {
        const int temp_sum = nums[i] + nums[l_index] + nums[r_index];
        if (temp_sum < 0)
          ++l_index;
        else if (0 < temp_sum)
          --r_index;
        else {
          result.push_back({nums[i], nums[l_index], nums[r_index]});
          do {
            ++l_index;
          } while (l_index < r_index && nums[l_index - 1] == nums[l_index]);
        }
      }
    }
    return result;
  }
};
