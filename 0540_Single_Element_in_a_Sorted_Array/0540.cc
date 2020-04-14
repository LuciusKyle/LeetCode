
#include <vector>
#include <assert.h>

using std::vector;

class Solution {
 public:
   // c++ interface.
  int singleNonDuplicate(const vector<int>& nums) {
    return singleNonDuplicate(&nums[0], nums.size());
  }

 private:
   // C language interface.
  int singleNonDuplicate(const int* nums, int numsSize) {
    switch (numsSize) {
      case 1:
        return nums[0];
      case 3:
        return nums[0] == nums[1] ? nums[2] : nums[0];
      default:
        break;
    }
    const int mid = numsSize / 2 % 2 == 1 ? numsSize / 2 - 1 : numsSize / 2;
    if (nums[mid] == nums[mid + 1])
      return singleNonDuplicate(nums + mid, numsSize - mid);
    else
      return singleNonDuplicate(nums, mid + 1);
  }
};

int main(void) {
  Solution sln;
  assert(2 == sln.singleNonDuplicate({1, 1, 2, 3, 3, 4, 4, 8, 8}));
  assert(10 == sln.singleNonDuplicate({3, 3, 7, 7, 10, 11, 11}));
	return 0;
}
