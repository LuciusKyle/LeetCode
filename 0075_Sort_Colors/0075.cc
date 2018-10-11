
#include <vector>

using std::vector;

class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int lower_index = 0;
    int upper_index = nums.empty() ? 0 : nums.size() - 1;
    int temp = 0;
    for (int i = lower_index; i <= upper_index; ++i) {
      if (nums[i] == 0) {
        temp = nums[i];
        nums[i] = nums[lower_index];
        nums[lower_index] = temp;
        ++lower_index;
        continue;
      }
      if (nums[i] == 2) {
        temp = nums[i];
        nums[i] = nums[upper_index];
        nums[upper_index] = temp;
        --upper_index;
        --i;
      }
    }
  }
};

int main(void) {
  Solution sln;
  vector<int> test_sample{2};
  sln.sortColors(test_sample);
  test_sample = {1, 2, 0};
  sln.sortColors(test_sample);
  test_sample = {0, 1, 0};
  sln.sortColors(test_sample);
  return 0;
}
