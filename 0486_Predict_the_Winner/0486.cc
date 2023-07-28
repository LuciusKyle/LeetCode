
#include <limits.h>

#include <vector>

using std::vector;

class Solution {
 public:
  bool PredictTheWinner(vector<int>& nums) {
    dp_.assign(nums.size(), vector<int>(nums.size(), INT_MIN));
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size() - 1));
    return 0 <= scoreDiff(nums, 0, nums.size() - 1);
  }

 private:
  vector<vector<int>> dp_;
  int scoreDiff(const vector<int>& nums, int l_index, int r_index) {
    if (l_index == r_index) return nums[l_index];
    if (dp_[l_index][r_index] == INT_MIN)
      dp_[l_index][r_index] = std::max(nums[l_index] - scoreDiff(nums, l_index + 1, r_index), nums[r_index] - scoreDiff(nums, l_index, r_index - 1));
    return dp_[l_index][r_index];
  }
};
