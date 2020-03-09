
#include <vector>
#include <map>

using std::vector;
using std::map;

class Solution {
 public:
  bool canPartition(const vector<int>& nums) {
    vector<map<int, bool>> result(nums.size());
    int target = 0;
    int odd_count = 0;
    for (const int num : nums) {
      target += num / 2;
      if (num % 2) ++odd_count;      
    }
    if (odd_count % 2 == 1 || nums.size() < 2) return false;
    target += odd_count / 2;
    return canPartition(nums, 0, target, result);
  }

 private:
  bool canPartition(const vector<int>& nums, const size_t cur_index, const int target, vector<map<int, bool>>& result) {
    // if (nums.empty()) return false; // don't check empty at here.
    if (nums.size() - cur_index == 0) return false;
    if (nums.size() - cur_index == 1) return nums[cur_index] == target;
    if (result[cur_index].find(target) != result[cur_index].end()) return result[cur_index].at(target);
    const bool rtn = canPartition(nums, cur_index + 1, target, result) || canPartition(nums, cur_index + 1, target - nums[cur_index], result);
    result[cur_index].insert({target, rtn});
    return rtn;
  }
};

int main(void) {
  Solution sln;
  return 0;
}

