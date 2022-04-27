
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
 public:
  vector<int> twoSum(const vector<int>& nums, int target) {
    unordered_map<int, int> nums_map;
    nums_map.reserve(nums.size() + 1);
    for (int i = 0; i < nums.size(); ++i)
      if (0 == nums_map.count(target - nums[i]))
        nums_map.insert({nums[i], i});
      else
        return {i, nums_map.find(target - nums[i])->second};
    return {};
  }
};

int main(int argc, char* argv[]) {
  Solution sln;
  auto rtn = sln.twoSum({1, 2, 3, 4, 5, 6, 7}, 9);
  rtn = sln.twoSum({3, 2, 4}, 6);
  return 0;
}
