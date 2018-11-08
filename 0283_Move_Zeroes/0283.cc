
#include <vector>

using std::vector;

class Solution {
 public:
  void moveZeroes(vector<int> &nums) {
    size_t cur_index = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
      if (nums[cur_index] == 0)
        if (cur_index != i) {
          nums[cur_index] ^= nums[i];
          nums[i] ^= nums[cur_index];
          nums[cur_index] ^= nums[i];
        }
      if (nums[cur_index] != 0) ++cur_index;
    }
  }
};

int main(void) {
  Solution sln;
  vector test_sample{1, 0, 2, 0, 3, 0, 0, 4, 0, 5};
  sln.moveZeroes(test_sample);

  return 0;
}
