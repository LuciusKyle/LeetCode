
// problem 31: leetcode.com/problems/next-permutation
// use the solution of problem 31.
// both problem 0046 and problem 0047 can use this code.


#include <vector>

using std::vector;

class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> rtn;
    vector<int> permutation(nums);
    for (size_t i = 0, count = factorial(nums.size()); i < count; ++i) {
      nextPermutation(permutation);
      rtn.push_back(permutation);
    }
    return rtn;
  }
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> rtn;
    vector<int> permutation(nums);
    do {
      nextPermutation(permutation);
      rtn.push_back(permutation);
    } while (permutation != nums);
    return  rtn;
  }

 private:
  void nextPermutation(vector<int>& nums) {
    size_t revers_position = 0;
    for (size_t i = nums.size() - 1; i > 0 /*don't let i = 0*/; --i) {
      if (nums[i - 1] < nums[i]) {
        revers_position = i;
        for (size_t ii = nums.size() - 1; ii > i - 1; --ii) {
          if (nums[ii] > nums[i - 1]) {
            nums[ii] ^= nums[i - 1];
            nums[i - 1] ^= nums[ii];
            nums[ii] ^= nums[i - 1];
            break;
          }
        }
        break;
      }
    }
    for (size_t i = 0; i < (nums.size() - revers_position) / 2; ++i) {
      nums[i + revers_position] ^= nums[nums.size() - 1 - i];
      nums[nums.size() - 1 - i] ^= nums[i + revers_position];
      nums[i + revers_position] ^= nums[nums.size() - 1 - i];
    }
  }

  int factorial(const int value) const {
    return value == 1 ? 1 : (factorial(value - 1) * value);
  }
};

int main(void) {
  Solution sln;
  vector<int> nums{1, 1, 2};
  auto rtn = sln.permuteUnique(nums);

  return 0;
}

