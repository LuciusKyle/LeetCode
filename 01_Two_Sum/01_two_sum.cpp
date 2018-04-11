
//
//									Hello World!
//------------------------------------------------------------------------------------------------
//
//						this is a cpp source file.
//
//						Lucius@LUCIUS-PC
//											--4/11/2018 14:56:11
//
//
//			Copyright (c) 2018 LuciusKyle@outlook.com. All rights reserved.
//
//------------------------------------------------------------------------------------------------
//									Goodbye World!
//


//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
//Example:
//
//Given nums = [2, 7, 11, 15], target = 9,
//
//Because nums[0] + nums[1] = 2 + 7 = 9,
//return [0, 1].

#include<vector>
#include<set>

using std::vector;
using std::set;

class Solution {
public:
	vector<int> twoSum(const vector<int>& nums, int target) {
		set<int> nums_set;
		for (const auto num : nums) {
			nums_set.insert(num);
		}
		for (const auto num : nums_set) {
			if (num >= target)
				return {};
			if (0 < nums_set.count(target - num)) {
				return { num, target - num };
			}
		}
		return {};
	}
};

int main(int argc, char *argv[])
{

	Solution sln;
	auto rtn = sln.twoSum({ 1, 2, 3, 4, 5, 6, 7 }, 13);

	return 0;
}
