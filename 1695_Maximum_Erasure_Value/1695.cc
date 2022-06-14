
#include <numeric>
#include <vector>

using std::vector;

class Solution {
 public:
  int maximumUniqueSubarray(const vector<int>& nums) {
    vector<int> sum_until_here, element_pos(10001, 0);
    sum_until_here.reserve(nums.size() + 1);
    sum_until_here.push_back(0);
    int maximum_sub_arr_sum;
    for (int i = 0, start_index = 0; i < nums.size(); ++i) {
      sum_until_here.push_back(nums[i] + sum_until_here.back());
      if (start_index < element_pos[nums[i]]) start_index = element_pos[nums[i]];
      element_pos[nums[i]] = i + 1;
      if (maximum_sub_arr_sum < sum_until_here.back() - sum_until_here[start_index]) maximum_sub_arr_sum = sum_until_here.back() - sum_until_here[start_index];
    }
    return maximum_sub_arr_sum;
  }
};
