
#include <cstddef>
#include <vector>

using std::vector;

class Solution {
 public:
  int minimizeArrayValue(vector<int>& nums) {
    size_t curr_sum = 0;
    int curr_max = nums.front();
    for (int i = 0; i < nums.size(); ++i) {
      curr_sum += nums[i];
      const int possible_max = curr_sum / (i + 1) + (curr_sum % (i + 1) == 0 ? 0 : 1);
      if (curr_max < possible_max) curr_max = possible_max;
    }
    return curr_max;
  }
};
