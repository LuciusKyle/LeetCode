
#include <assert.h>

#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> searchRange(const vector<int>& nums, const int target) {
    if (nums.empty()) return {-1, -1};
    return {find_bound<true>(nums, target), find_bound<false>(nums, target)};
  }

 private:
  template <bool bound_type>  // true: lower bound, false: upper bound
  int find_bound(const vector<int>& nums, const int target) {
    int lower_index = 0;
    int upper_index = nums.size() - 1;
    while (1 < upper_index - lower_index) {
      const int mid_index = (lower_index + upper_index) / 2;
      if (nums[mid_index] < target)
        lower_index = mid_index;
      else if (target < nums[mid_index])
        upper_index = mid_index;
      else {
        if (bound_type)
          upper_index = mid_index;
        else
          lower_index = mid_index;
      }
    }
    if (bound_type)
      return (nums[lower_index] == target || nums[upper_index] == target) ? (nums[lower_index] == target ? lower_index : upper_index) : -1;
    else
      return (nums[lower_index] == target || nums[upper_index] == target) ? (nums[upper_index] == target ? upper_index : lower_index) : -1;
  }
};

int main(void) {
  Solution sln;
  assert(vector({0, 1}) == sln.searchRange({1, 1}, 1));
  assert(vector({1, 1}) == sln.searchRange({1, 2, 3}, 2));
  assert(vector({2, 2}) == sln.searchRange({1, 2, 3}, 3));
  assert(vector({3, 3}) == sln.searchRange({1, 2, 2, 3}, 3));
  assert(vector({1, 2}) == sln.searchRange({1, 2, 2, 3}, 2));
  assert(vector({0, 0}) == sln.searchRange({1, 2, 2, 2, 3}, 1));
  assert(vector({1, 3}) == sln.searchRange({1, 2, 2, 2, 3}, 2));
  assert(vector({-1, -1}) == sln.searchRange({1, 2, 2, 2, 4}, 3));
  assert(vector({-1, -1}) == sln.searchRange({1, 2, 2, 2, 3}, 4));
  assert(vector({4, 4}) == sln.searchRange({1, 2, 2, 2, 3}, 3));

  return 0;
}