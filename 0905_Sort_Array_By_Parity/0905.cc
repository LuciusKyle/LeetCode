
#include <stddef.h>

#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> sortArrayByParity(vector<int>& nums) {
    const int s = nums.size();
    int left_index = 0, right_index = s - 1;
    while (left_index < s && nums[left_index] % 2 == 0) ++left_index;
    while (0 <= right_index && nums[right_index] % 2 == 1) --right_index;
    while (left_index < right_index) {
      nums[left_index] ^= nums[right_index];
      nums[right_index] ^= nums[left_index];
      nums[left_index] ^= nums[right_index];
      while (left_index < s && nums[left_index] % 2 == 0) ++left_index;
      while (0 <= right_index && nums[right_index] % 2 == 1) --right_index;
    }
    return nums;
  }
};

int main(void) {
  Solution sln;
  return 0;
}
