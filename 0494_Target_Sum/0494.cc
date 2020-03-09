
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
 public:
  int findTargetSumWays(const vector<int>& nums, int S) {
    vector<unordered_map<int, int>> result(nums.size());
    return findTargetSumWays(nums, 0, S, result);
  }

 private:
  int findTargetSumWays(const vector<int> &nums, const size_t cur_index, const int target, vector<unordered_map<int, int>> &result) {
    if (nums.size() - cur_index == 1) {
      int rtn = 0;
      if (nums[cur_index] * -1 == target) ++rtn;
      if (nums[cur_index] == target) ++rtn;
      return rtn;
    }
    if (result[cur_index].count(target) != 0) return result[cur_index].at(target);
    const int rtn = findTargetSumWays(nums, cur_index + 1, target + nums[cur_index], result) + findTargetSumWays(nums, cur_index + 1, target - nums[cur_index], result);
    result[cur_index].insert({target, rtn});
    return rtn;
  }
};

int main(void) {

  return 0;
}

