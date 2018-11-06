
#include <limits.h>
#include <unordered_set>
#include <vector>

using std::unordered_set;
using std::vector;

class Solution {
 public:
  int missingNumber(const vector<int>& nums) {
    const unordered_set<int> nums_set(nums.cbegin(), nums.cend());
    for (int i = 0; i < static_cast<int>(nums.size()); ++i)
      if (nums_set.count(i) == 0) return i;

    return static_cast<int>(nums.size());
  }
};

int main(void) {
  Solution sln;
  int rtn = sln.missingNumber({0});
  return 0;
}