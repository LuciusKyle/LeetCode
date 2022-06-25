
#include <limits.h>

#include <vector>

using std::vector;

class Solution {
 public:
  bool checkPossibility(vector<int>& nums) {
    const int arr_size = nums.size();  // use int instead of size_t.
    nums.push_back(INT_MAX);
    int ascending_from_left = -1, decending_from_right = arr_size - 1;
    for (int i = 0; i < arr_size - 1; ++i) {
      if (nums[i] > nums[i + 1]) {
        ascending_from_left = i;
        break;
      }
    }
    if (ascending_from_left == -1) return true;
    for (int i = arr_size; 0 < i; --i) {
      if (nums[i - 1] > nums[i]) {
        decending_from_right = i;
        break;
      }
    }
    if (ascending_from_left + 1 != decending_from_right) return false;
    if (ascending_from_left == 0 || decending_from_right == arr_size - 1) return true;
    return (nums[ascending_from_left] <= nums[decending_from_right + 1] || nums[ascending_from_left - 1] <= nums[decending_from_right]);
  }
};