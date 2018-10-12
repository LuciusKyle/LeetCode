
#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> twoSum(const vector<int>& numbers, int target) {
    size_t lower_index = 0;
    size_t upper_index = numbers.size() - 1;
    while (lower_index < upper_index) {
      const int sum = numbers[lower_index] + numbers[upper_index];
      if (sum < target) {
        ++lower_index;
        continue;
      }
      if (target < sum) {
        --upper_index;
        continue;
      }
      return {static_cast<int>(lower_index + 1), static_cast<int>(upper_index + 1)};
    }
    return {static_cast<int>(lower_index + 1), static_cast<int>(upper_index + 1)};
  }
};

int main(void) {
  Solution sln;
  auto rtn = sln.twoSum({1, 2, 7, 11, 15}, 9);

  return 0;
}
