
#include <vector>

using std::vector;

// C version
int removeDuplicates(int* nums, int numsSize) {
  size_t duplicates_count = 0;
  for (size_t i = 1; i < numsSize; ++i) {
    if (nums[i] == nums[i - 1 - duplicates_count]) {
      ++duplicates_count;
    }
    if (duplicates_count != 0) {
      nums[i] ^= nums[i - duplicates_count];
      nums[i - duplicates_count] ^= nums[i];
      nums[i] ^= nums[i - duplicates_count];
    }
  }
  return numsSize - duplicates_count;
}

// C++ version
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    size_t duplicates_count = 0;
    for (size_t i = 1; i < nums.size(); ++i) {
      if (nums[i] == nums[i - 1 - duplicates_count]) {
        ++duplicates_count;
      }
      if (duplicates_count != 0) {
        nums[i] ^= nums[i - duplicates_count];
        nums[i - duplicates_count] ^= nums[i];
        nums[i] ^= nums[i - duplicates_count];
      }
    }
    return nums.size() - duplicates_count;
  }
};