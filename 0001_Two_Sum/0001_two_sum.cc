
//
//									Hello
// World!
//------------------------------------------------------------------------------------------------
//
//						this is a cpp source file.
//
//						Lucius@LUCIUS-PC
//											--4/11/2018
// 14:56:11
//
//
//			Copyright (c) 2018 LuciusKyle@outlook.com. All rights
// reserved.
//
//------------------------------------------------------------------------------------------------
//									Goodbye
// World!
//

// Given an array of integers, return indices of the two numbers such that they
// add up to a specific target.
//
// You may assume that each input would have exactly one solution, and you may
// not use the same element twice.
//
// Example:
//
// Given nums = [2, 7, 11, 15], target = 9,
//
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
 public:
  vector<int> twoSum(const vector<int>& nums, int target) {
    unordered_map<int, size_t> nums_map;
    nums_map.reserve(nums.size() + 1);
    for (size_t i = 0, nums_vec_size = nums.size(); i < nums_vec_size; ++i) {
      if (nums_map.end() != nums_map.find(target - nums[i]))
        return {static_cast<int>(i),
                static_cast<int>(nums_map.find(target - nums[i])->second)};
      nums_map.insert({nums[i], i});
    }
    return {};
  }
};

int main(int argc, char* argv[]) {
  Solution sln;
  auto rtn = sln.twoSum({1, 2, 3, 4, 5, 6, 7}, 9);
  rtn = sln.twoSum({3, 2, 4}, 6);
  return 0;
}
