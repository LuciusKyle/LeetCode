
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
 public:
  int findTargetSumWays(const vector<int>& nums, int S) {
    if (nums.empty()) return 0;
    vector<unordered_map<int, int>> result(nums.size());
    result[0].insert({nums[0], nums[0] == 0 ? 2 : 1});
    result[0].insert({nums[0] * -1, 1});
    for (int i = 1; i < nums.size(); ++i) 
      for (auto iter = result[i - 1].cbegin(); iter != result[i - 1].cend(); iter++) {
        if (result[i].count(iter->first + nums[i]) != 0)
          result[i].at(iter->first + nums[i]) += iter->second;
        else
          result[i].insert({iter->first + nums[i], iter->second});
        if (result[i].count(iter->first - nums[i]) != 0)
          result[i].at(iter->first - nums[i]) += iter->second;
        else
          result[i].insert({iter->first - nums[i], iter->second});
      }

    return result[nums.size() - 1].count(S) == 0 ? 0 : result[nums.size() - 1].at(S);
  }
};

int main(void) {
  Solution sln;
  int rtn = sln.findTargetSumWays({1, 1, 1, 1, 1}, 3);
  rtn = sln.findTargetSumWays({0, 0, 0, 0, 0, 0, 0, 0, 1}, 1);
  return 0;
}
