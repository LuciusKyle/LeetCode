#include <assert.h>
#include <vector>

using std::vector;

class Solution {
 public:

  // for leetcode test case, brute force algorithm is better than this code.
  // this solution is similar to problem 31.
  bool search(const vector<int>& nums, int target) {
    if (nums.empty()) return false;

    size_t lower_index = 0, upper_index = nums.size() - 1;
    while (lower_index + 1 < upper_index) {
      const size_t mid_index = (upper_index - lower_index) / 2 + lower_index;
      if (nums[mid_index] == target) return true;
      if (nums[lower_index] < nums[mid_index])  // left part is sorted.
        if (nums[lower_index] <= target && target <= nums[mid_index])
          upper_index = mid_index;
        else
          lower_index = mid_index;
      else if (nums[lower_index] < nums[mid_index]) {  // right part is sorted.
        if (nums[mid_index] <= target && target <= nums[upper_index])
          lower_index = mid_index;
        else
          upper_index = mid_index;
      } else {  // I don't know witch part is sorted.
        return search({nums.cbegin(), nums.cbegin() + mid_index}, target) ||
               search({nums.cbegin() + mid_index, nums.cend()}, target);
      }
    }
    return nums[lower_index] == target || nums[upper_index] == target;
  }
};

int main(void) {
  Solution sln;

  return 0;
}
