
#include <vector>

using std::vector;

// extra space, 41% beat.
class Solution {
 public:
  vector<int> findDuplicates(vector<int>& nums) {
    vector<int> count(nums.size(), 0);
    vector<int> rtn;
    for (const int i : nums)
      if (count[nums[i] - 1] != 0) rtn.push_back(nums[i]);
      else count[nums[i] - 1] = nums[i];
    return rtn;
  }
};