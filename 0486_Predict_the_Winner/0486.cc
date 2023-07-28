
#include <vector>

using std::vector;

class Solution {
 public:
  bool PredictTheWinner(vector<int>& nums) {
    return 0 <= scoreDiff(nums, 0, nums.size() - 1);
  }

 private:
  int scoreDiff(const vector<int>& nums, int l_index, int r_index) {
    if (l_index == r_index) return nums[l_index];
    return std::max(nums[l_index] - scoreDiff(nums, l_index + 1, r_index), nums[r_index] - scoreDiff(nums, l_index, r_index - 1));
  }
};
