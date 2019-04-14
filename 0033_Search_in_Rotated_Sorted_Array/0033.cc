
#include <limits.h>
#include <vector>

using std::vector;

class Solution {
 public:
  int search(const vector<int>& nums, int target) {
    if (nums.empty()) return -1;
    size_t lower_index = 0, upper_index = nums.size() - 1;
    while (lower_index + 1 < upper_index) {
      const size_t mid_index = lower_index / 2 + upper_index / 2 + ((0 != (0x1 & lower_index) && 0 != (0x1 & upper_index)) ? 1 : 0);
      if (nums[lower_index] < nums[mid_index]) { // left part is sorted.
        if (nums[lower_index] <= target && target <= nums[mid_index]) {
          upper_index = mid_index;
        }
        else {
          lower_index = mid_index;
        }
      }
      else { //right part is sorted.
        if (nums[mid_index] <= target && target <= nums[upper_index]) {
          lower_index = mid_index;
        }
        else {
          upper_index = mid_index;
        }
      }
    }

    if (nums[lower_index] == target) return int(lower_index);
    else if (nums[upper_index] == target) return int(upper_index);
    else return -1;
  }
};

int main(void) {
  Solution sln;
  int rtn = sln.search({4, 5, 6, 7, 0, 1, 2, 3}, 0);
  return 0;
}
