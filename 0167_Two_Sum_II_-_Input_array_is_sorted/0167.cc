
#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> twoSum(const vector<int>& numbers, int target) {
    int l_index = 0, r_index = numbers.size() - 1;
    while (l_index < r_index) {
      const int temp_sum = numbers[l_index] + numbers[r_index];
      if (temp_sum < target)
        ++l_index;
      else if (target < temp_sum)
        --r_index;
      else
        return {l_index + 1, r_index + 1};
    }
    return {};
  }
};